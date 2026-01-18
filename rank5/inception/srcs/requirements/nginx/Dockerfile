FROM alpine:3.22

RUN apk update && apk add --no-cache nginx openssl
#no cache stops apk from storing indexing

COPY conf/nginx.conf /etc/nginx/nginx.conf
# host dest_in_vm

COPY ssl/server.crt /etc/nginx/ssl/server.crt
COPY ssl/server.key /etc/nginx/ssl/server.key
# host dest_in_vm

CMD ["nginx", "-g", "daemon off;"] 
#keep nginx foreground process
