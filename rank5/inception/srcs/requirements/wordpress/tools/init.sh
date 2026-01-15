#!/bin/sh

cd /var/www/html

if [ ! -f wp-config.php ]; then
    wget https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress latest.tar.gz

    chown -R nobody:nobody /var/www/html
    chmod -R 755 /var/www/html

    cp wp-config-sample.php wp-config.php
    sed -i "s/database_name_here/${WP_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WP_DB_USER}/" wp-config.php
    sed -i "s/password_here/${WP_DB_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${WP_DB_HOST}/" wp-config.php

    until mariadb -h"$WP_DB_HOST" -u"$WP_DB_USER" -p"$WP_DB_PASSWORD" "$WP_DB_NAME" &>/dev/null
    do
        echo "Waiting for MariaDB..."
        sleep 2
    done

    wp core install \
        --url=https://${DOMAIN_NAME} \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root
fi

exec php-fpm81 -F
