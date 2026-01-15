FROM alpine:3.22


RUN apk update && apk add --no-cache \
    php81 php81-fpm php81-mysqli php81-json php81-openssl \
    php81-curl php81-zlib php81-xml php81-phar php81-intl \
    php81-dom php81-mbstring php81-gd wget curl
RUN mkdir -p /var/www/html

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

EXPOSE 9000

ENTRYPOINT [ "/init.sh" ]