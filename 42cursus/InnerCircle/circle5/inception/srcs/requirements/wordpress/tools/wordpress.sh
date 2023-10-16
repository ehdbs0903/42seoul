#!/bin/sh

if [ ! -f "/var/www/html/wp-config.php" ]; then

	wp core download --allow-root --path=/var/www/html

	sleep 10;
	
	mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

	sed -i "s/username_here/$WP_USER/g" /var/www/html/wp-config.php
	sed -i "s/password_here/$WP_PASSWORD/g" /var/www/html/wp-config.php
	sed -i "s/localhost/$WP_HOSTNAME/g" /var/www/html/wp-config.php
	sed -i "s/database_name_here/$WP_DATABASE/g" /var/www/html/wp-config.php

	sleep 10;

	wp core install --allow-root --title='doykim inception' --url=${DOMAIN_NAME} --path=/var/www/html --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL} --skip-email

	wp user create cadet cadet@42.fr --allow-root --user_pass=1234 --role=subscriber --path=/var/www/html

else
	echo "Wordpress already downloaded."

fi

/usr/sbin/php-fpm7.4 -F
