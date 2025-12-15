FROM debian:bullseye

RUN apt-get update \
 && apt-get -y upgrade \
 && apt-get install -y --no-install-recommends nginx \
 && rm -rf /var/lib/apt/lists/*

COPY config.conf /etc/nginx/conf.d/default.conf
CMD ["nginx", "-g", "daemon off;"]