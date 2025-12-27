#!/bin/bash
cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
# wait until MariaDB is ready (prevents race on first boot)
until mysqladmin ping -h mariadb -u wpuser -ppassword --silent; do
  sleep 1
done

# 2) avoid failing if WP files are already there 
if [ ! -f wp-settings.php ]; then
  ./wp-cli.phar core download --allow-root
fi
if [ ! -f wp-config.php ]; then
  ./wp-cli.phar config create \
    --dbname=wordpress \
    --dbuser=wpuser \
    --dbpass=password \
    --dbhost=mariadb \
    --allow-root
fi
# 4) fix admin email flag name: --admin_email (underscore)
#    also: don’t reinstall if already installed 
#pw needed for loggin into wp-admin
if ! ./wp-cli.phar core is-installed --allow-root; then
  ./wp-cli.phar core install \
    --url=https://jasnguye.42.fr \
    --title=inception \
    --admin_user=jasnguye \
    --admin_password=jasnguye_pw \
    --admin_email=jasnguye@email.com \
    --allow-root
fi

# 5) use exec so php-fpm becomes PID 1
exec php-fpm8.2 -F
# enforce URL even if DB already existed
./wp-cli.phar option update siteurl "https://jasnguye.42.fr" --allow-root
./wp-cli.phar option update home    "https://jasnguye.42.fr" --allow-root
