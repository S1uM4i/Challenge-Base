FROM ghcr.io/s1um4i/challenge-base/php:alpine

RUN apk add --no-cache mariadb mariadb-client

COPY my.cnf /etc/mysql/my.cnf
COPY --chmod=500 init.sh /init.sh
