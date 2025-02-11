FROM alpine AS builder

RUN apk add build-base autoconf automake libtool pkgconf git && \
    git clone -b master https://github.com/openSUSE/xinetd.git && \
    cd xinetd && sh ./autogen.sh && ./configure && make

FROM alpine

COPY --from=builder /xinetd/xinetd /usr/sbin
RUN mkdir -p /etc/xinetd.d/ && \
    adduser -D -h /home/ctf ctf

CMD ["sleep", "infinity"]
