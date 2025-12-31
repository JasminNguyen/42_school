# Developer Documentation — Inception

## Purpose of This Document

This document describes how a **developer** can set up, build, run, and maintain the Inception project from scratch.  
It focuses on infrastructure design, Docker usage, data persistence, and operational commands.

This document is intended for developers, maintainers, and evaluators who need to understand how the project works internally.

---

## Project Overview

The Inception project deploys a small web infrastructure using **Docker** and **Docker Compose**, running entirely inside a **virtual machine**.

The stack is composed of:
- an NGINX container acting as the sole HTTPS entry point,
- a WordPress container running PHP via php-fpm,
- a MariaDB container used as the database backend.

Each service runs in its **own dedicated container**, built from a custom Dockerfile, and communicates over a private Docker network.

---

## Prerequisites

The following must be installed on the virtual machine before starting:

- Docker
- Docker Compose
- Make
- Git

The project **must not** be run directly on the host system.  
All execution takes place inside a virtual machine, as required by the subject.

---

## Repository Structure

.
├── Makefile
├── DEV_DOC.md
├── USER_DOC.md
├── secrets/
│   ├── db_password.txt
│   ├── db_root_password.txt
│   └── credentials.txt
└── srcs/
    ├── docker-compose.yml
    ├── .env
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            └── tools/



Environment Setup from Scratch 
1. Clone the Repository
git clone <repository_url>
cd inception

2. Environment Variables
Non-sensitive configuration values are defined in: srcs/.env


Typical variables include:

domain name
database name
database user

Example:

DOMAIN_NAME=login.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser

This file is read by Docker Compose at runtime.

3. Secrets Management

Sensitive data must not be committed to the repository.
Secrets are stored in the following directory: secrets/


Examples:

database user password
database root password
WordPress credentials

These files are mounted or read at container startup and injected using environment variables or Docker secrets mechanisms.

Building and Launching the Project

All project operations are centralized in the Makefile.

Build and start the infrastructure:
make or explicitly: make up


This command:

builds all Docker images locally,
creates the Docker network,
creates and mounts volumes,
starts all containers.

Stop the infrastructure
make down

This stops all containers without removing persistent data.

Full cleanup:
make clean


This removes:

containers,
images,
volumes,
networks.

This allows a full rebuild from a clean state.

Docker Compose Usage

The file:
srcs/docker-compose.yml


defines:
all services,
volumes,
networks,
restart policies.

Each service:

uses a custom Dockerfile,
runs in a dedicated container,
is connected to a private Docker network.

The use of network: host, links, or deprecated networking features is explicitly avoided.

Managing Containers
List running containers
docker ps

View logs
docker logs nginx
docker logs wordpress
docker logs mariadb

Execute a command inside a container
docker exec -it wordpress sh

Data Persistence

Persistent data is stored using Docker volumes, not bind mounts.

Persisted data includes:

MariaDB database files
WordPress website files

Volumes are mounted to directories under:

/home/<login>/data/


This ensures:

data persistence across container restarts,
separation between container lifecycle and data,
portability and safety.

Networking

A custom Docker network is defined in docker-compose.yml

Containers communicate using service names (Docker internal DNS)

Only the NGINX container exposes a port to the host

External access is restricted to HTTPS (port 443)

Process Management and PID 1

Each container:

runs a single main process,
avoids infinite loops (while true, sleep infinity, tail -f),
uses entrypoint scripts only for initialization.

The final service process replaces PID 1 using exec, ensuring:

proper signal handling,

clean shutdowns,

Docker best-practice compliance.

Docker Image Constraints

Images are built from Alpine or Debian (non-latest tag)

No pre-built service images are used

No credentials are hardcoded in Dockerfiles

Configuration is injected at runtime

Development and Evaluation Notes

The project can be rebuilt entirely using the Makefile

Containers restart automatically in case of failure

The structure allows live modification during evaluation

All design choices follow the official Inception subject constraints