FROM debian:bullseye

RUN apt-get -y update \
	&& apt-get -y install curl \
		php7.4 \
		php-fpm \
		php-mysql \
		php-cli \
		php-mbstring \
		php-xml \
		wget \
		sendmail \
		vim \
		mariadb-client \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php \
	&& chmod 777 /run/php

RUN mkdir -p /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/wordpress.sh

EXPOSE 9000

ENTRYPOINT [ "/usr/local/bin/wordpress.sh" ]
