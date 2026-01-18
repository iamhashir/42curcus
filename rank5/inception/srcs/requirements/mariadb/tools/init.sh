#!/bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mkdir -p /run/mysqld
    chown -R mysql:mysql /run/mysqld
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
#checks if the mysql dir isnot presnet it will make

    mysqld --bootstrap --user=mysql <<EOF #start mysqld for only setup mode without root hence bootstrap
    FLUSH PRIVILEGES; 
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    CREATE DATABASE ${MYSQL_DATABASE};
    CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOF
fi

exec mysqld --defaults-file=/etc/mysql/my.cnf --user=mysql --datadir=/var/lib/mysql