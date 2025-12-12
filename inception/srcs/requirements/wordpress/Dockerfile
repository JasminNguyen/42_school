FROM debian:bullseye
RUN apt-get update \
 && apt-get install -y --no-install-recommends php-fpm \
 && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /run/php
CMD ["php-fpm7.4", "-F"]