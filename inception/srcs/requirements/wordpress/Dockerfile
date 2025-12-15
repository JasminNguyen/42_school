FROM debian:bullseye
RUN apt-get update \
 && apt-get install -y --no-install-recommends php-fpm \
 && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /run/php
COPY www.conf /tec/php/7.4/fpm/pool.d
CMD ["php-fpm7.4", "-F"]