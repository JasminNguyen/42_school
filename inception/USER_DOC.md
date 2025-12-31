# User Documentation — Inception

## Purpose of This Document

This document explains how to use the Inception project as an **end user or administrator**.  
It focuses on understanding the provided services, operating the stack, and performing basic checks without requiring in-depth Docker knowledge.

---

## Services Provided by the Stack

The project deploys the following services:

- **NGINX**
  - Acts as the single entry point
  - Handles HTTPS connections (TLSv1.2 / TLSv1.3 only)

- **WordPress**
  - Provides the website and administration interface
  - Runs PHP via php-fpm

- **MariaDB**
  - Stores WordPress data (users, posts, configuration)

All services run in isolated Docker containers and communicate through a private Docker network.

---

## Starting and Stopping the Project

All operations are managed through the `Makefile`.

### Start the project

make or make up

Stop the project: make down
This stops the containers without deleting persistent data.

Accessing the Website and Admin Panel

Open a browser and go to:
https://jasnguye.42.fr

WordPress Administration Panel
Access the admin interface at:

https://jasnguye.42.fr/wp-admin

Credentials Management (Credentials are not stored in the repository)

Sensitive data is located in: secrets/
Typical files include: database user password, database root password, WordPress credentials
(These files are read at container startup and injected securely)

Check container status: docker ps
You should see containers for: nginx, wordpress, mariadb





