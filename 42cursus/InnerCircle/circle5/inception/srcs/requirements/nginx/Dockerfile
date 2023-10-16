FROM debian:bullseye

RUN apt-get -y update \
	&& apt-get -y install nginx \
		openssl \
		dumb-init

RUN mkdir -p /etc/nginx/ssl \
	&& chmod 777 /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 \
				-x509 \
				-sha256 \
				-days 365 \
				-nodes \
				-keyout /etc/nginx/ssl/doykim.key \
				-out /etc/nginx/ssl/doykim.crt \
				-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=cadet/CN=doykim"

COPY ./conf/default /etc/nginx/sites-enabled/default

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
