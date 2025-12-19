FROM debian:bookworm
RUN apt-get update && apt upgrade && apt install -y \
    mariadb-server
CMD ["mysqld_safe"]
