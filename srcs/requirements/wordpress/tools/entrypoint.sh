#!/bin/sh
set -e

WP_PATH="/var/www/html"

echo "Checking MariaDB availability..."

php82 -r "
\$ok = false;
for (\$i = 0; \$i < 10; \$i++) {
    try {
        new mysqli(
            getenv('WORDPRESS_DB_HOST'),
            getenv('WORDPRESS_DB_USER'),
            getenv('WORDPRESS_DB_PASSWORD'),
            getenv('WORDPRESS_DB_NAME')
        );
        \$ok = true;
        break;
    } catch (Throwable \$e) {
        sleep(2);
    }
}
if (!\$ok) {
    fwrite(STDERR, "MariaDB not reachable\n");
}
"

# WordPress install (non-blocking)
if [ -f "$WP_PATH/wp-config.php" ]; then
    if ! wp core is-installed --allow-root >/dev/null 2>&1; then
        echo "Installing WordPress..."

        wp core install \
            --url="https://${DOMAIN_NAME}" \
            --title="Inception" \
            --admin_user="${WP_ADMIN_USER}" \
            --admin_password="${WP_ADMIN_PASSWORD}" \
            --admin_email="${WP_ADMIN_EMAIL}" \
            --skip-email \
            --allow-root

        wp user create \
            "${WP_USER}" "${WP_USER_EMAIL}" \
            --user_pass="${WP_USER_PASSWORD}" \
            --role=author \
            --allow-root || true
    fi
fi

echo "Starting PHP-FPM"
exec php-fpm82 -F
