FROM debian:bookworm
RUN apt-get update \
 && apt-get install -y --no-install-recommends php-fpm \
 && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /run/php
# COPY www.conf /etc/php/8.2/fpm/pool.d/.
COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf

CMD ["php-fpm8.2", "-F"]