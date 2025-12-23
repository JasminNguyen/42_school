<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'aLILq0Z:/g(3>u_0m&X<oN[/v2]?;2R*nwl!#8~;nY]3oO*SXF>G%;6W)$AKm)Qk' );
define( 'SECURE_AUTH_KEY',   ';3]KF?3Join)AO0f76EBl?vylZH1wFRs59e74gQd4.x):T`AoWEq=T;9O+I{T-rZ' );
define( 'LOGGED_IN_KEY',     't8i>DMjKn[?V`BhhK/,{(3[I::Jw);y2QyRTbS`IwYQkFyZ18WdqjcI0{4yGt{1M' );
define( 'NONCE_KEY',         '-p&9SOt:Z!je`.+ecLBsY!g+352Ds.$Oi-Y;7WoW(coeFYv:InH<H*w~]e7`8Ipl' );
define( 'AUTH_SALT',         'H 1x[{9aRE&O9%Q54FL7{4Y<03Uy$Tn/^$0&3.0(0H7|]$)g)MF@RLOnV~O!7[ S' );
define( 'SECURE_AUTH_SALT',  '6ok}6pJI>;*h* a]FrYA8=iL4HN)H&Ir}{Rlp?A%  3,:b<:rYHn>05yAcr}D`?}' );
define( 'LOGGED_IN_SALT',    ';-;IlyMzVc-6GB$?2gMpB #;Z$SUC]tb^h[kngWqwzfZs6kb*rLb!(Q1c]|B>3a.' );
define( 'NONCE_SALT',        'LwB{c6OHE!+emhFSL*=c}}>[~;f$zm$M Wa}qf*yG3q&=IE$?Q&4rS%/56BjrtlI' );
define( 'WP_CACHE_KEY_SALT', '3GC9V%5nZe,{jmWPCccCS<mm|X}W+1~&UHbr^=#eE1dQ>)*f;]Sg[:*pm>{,H|CF' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
