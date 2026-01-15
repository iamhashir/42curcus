FROM alpine:3.22

RUN apk update && apk add --no-cache mariadb mariadb-client

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

ENTRYPOINT ["/init.sh"]