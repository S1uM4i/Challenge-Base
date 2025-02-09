FROM alpine AS builder

RUN apk add --no-cache gcc musl-dev

COPY readflag.c /readflag.c
RUN gcc /readflag.c -o /readflag -Os -static && \
    strip /readflag -o /readflag && \
    chmod +s /readflag


FROM scratch

COPY --from=builder /readflag /readflag

CMD ["/readflag"]
