FROM debian:bookworm
RUN apt-get update && apt-get install -y --no-install-recommends \
    php8.2-fpm php-mysqli curl ca-certificates \
 && update-ca-certificates \
 && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /run/php
# COPY www.conf /etc/php/8.2/fpm/pool.d/.
COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY wp_setup.sh /usr/local/bin/wp_setup.sh
RUN chmod +x /usr/local/bin/wp_setup.sh
ENTRYPOINT ["/usr/local/bin/wp_setup.sh"]
# CMD ["php-fpm8.2", "-F"]
