FROM debian:bullseye

RUN apt-get update \
 && apt-get -y upgrade \
 && apt-get install -y --no-install-recommends nginx \
 && rm -rf /var/lib/apt/lists/*

COPY default /etc/nginx/sites-available/.
CMD ["nginx", "-g", "daemon off;"]