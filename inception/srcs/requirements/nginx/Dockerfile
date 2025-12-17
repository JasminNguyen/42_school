FROM debian:bookworm

RUN apt-get update \
 && apt-get -y upgrade \
 && apt-get install -y --no-install-recommends nginx \
 && rm -rf /var/lib/apt/lists/*
#runs nginx as root so I have access to the data inside web -> dev-mode only
RUN sed -i 's/^user .*/user root;/' /etc/nginx/nginx.conf || true

COPY default /etc/nginx/sites-enabled/default

CMD ["nginx", "-g", "daemon off;"]