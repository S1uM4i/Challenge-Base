FROM alpine AS builder

RUN apk add --no-cache gcc musl-dev

ADD src /src
WORKDIR /src

RUN gcc -static -nostdlib -Os -fno-asynchronous-unwind-tables \
    -fno-stack-protector -z noseparate-code -Wl,--gc-sections \
    -Wl,-T,linker.ld -o readflag readflag.c && \
    strip --strip-all readflag && \
    chmod +s readflag

FROM scratch

ADD --chown=root:root --chmod=400 flag /flag
COPY --from=builder /src/readflag /readflag

CMD ["/readflag"]
