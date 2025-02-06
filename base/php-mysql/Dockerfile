FROM ghcr.io/s1um4i/challenge-base/php:alpine

RUN apk add --no-cache mysql mysql-client

COPY my.cnf /etc/mysql/my.cnf
COPY --chmod=500 init.sh /init.sh
