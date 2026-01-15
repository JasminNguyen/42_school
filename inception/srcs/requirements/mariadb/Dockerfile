FROM debian:bookworm
RUN apt-get update && apt upgrade && apt install -y \
    mariadb-server
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY init.sql /etc/mysql/init.sql
COPY entrypoint_script.sh .
RUN mkdir /run/mysqld && chmod +x entrypoint_script.sh
CMD ["./entrypoint_script.sh"]
