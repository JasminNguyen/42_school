FROM debian:bookworm

RUN apt-get update \
 && apt-get -y upgrade \
 && apt-get install -y --no-install-recommends nginx openssl\
 && mkdir -p /etc/nginx/ssl \
 && openssl req -x509 -nodes -newkey rsa:2048 -days 365 \
    -keyout /etc/nginx/ssl/localhost.key \
    -out /etc/nginx/ssl/localhost.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=Inception/CN=jasnguye.42.fr" \
 && rm -rf /var/lib/apt/lists/*

COPY default /etc/nginx/sites-enabled/default

CMD ["nginx", "-g", "daemon off;"]
