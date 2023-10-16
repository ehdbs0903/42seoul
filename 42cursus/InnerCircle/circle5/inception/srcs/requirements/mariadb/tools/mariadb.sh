#!/bin/sh

if [ ! -d /var/lib/mysql/${WP_NAME} ]; then

	service mariadb start

	sleep 20

	mariadb <<- EOF
	CREATE DATABASE IF NOT EXISTS $WP_NAME;
	CREATE USER IF NOT EXISTS '$WP_USER'@'%' IDENTIFIED BY '$WP_PASSWORD';
	GRANT ALL PRIVILEGES ON wordpress.* TO '$WP_USER'@'%';
	FLUSH PRIVILEGES;
	EOF

	service mariadb stop

else
	echo "MySQL db already exists."

fi

mysqld --user=root
