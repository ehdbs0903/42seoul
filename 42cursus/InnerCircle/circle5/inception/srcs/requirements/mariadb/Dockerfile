FROM debian:bullseye

RUN apt-get -y update \
	&& apt-get install -y mariadb-server \
		mariadb-client \
		vim \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/mariadb.sh /etc/mysql/mariadb.sh

RUN chmod +x /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod +x /etc/mysql/mariadb.sh

EXPOSE 3306

ENTRYPOINT [ "/etc/mysql/mariadb.sh" ]
