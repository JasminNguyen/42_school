
*This project has been created as part of the 42 curriculum by jasnguye.*


# Inception

## Description

This project is a system administration exercise whose goal is to design and deploy a small, secure infrastructure using **Docker** and **Docker Compose**.  
The infrastructure runs entirely inside a virtual machine and is composed of multiple isolated services, each hosted in its own container.

The mandatory setup includes:
- an NGINX container acting as the sole HTTPS entry point,
- a WordPress container running PHP via php-fpm,
- a MariaDB container used as the database backend,
- persistent storage using Docker volumes,
- a dedicated Docker network enabling inter-container communication.

---

## Instructions

### Prerequisites

- A Linux virtual machine
- Docker
- Docker Compose
- Make

### Setup and Execution

1. Clone the repository:
   git clone <repository_url>
   cd inception
   add secrets and .env
   make
   Access the website:https://jasnguye.42.fr

   make up        - build and start containers
   make down      - stop containers
   make rebuild   - make down and up
   make clean     - remove containers and volumes

### Project Architecture and Design Choices
### Use of Docker

Docker is used to isolate each service into its own container, ensuring:

reproducibility,

separation of concerns,

simplified deployment,

controlled networking and persistence.

Each service has its own Dockerfile and is built locally, without using pre-built images (except base Alpine/Debian images).

### Virtual Machines vs Docker

Virtual Machines

Run a full operating system with its own kernel

Heavier in resource usage

Slower startup times

Docker

Shares the host kernel

Lightweight and fast

Designed for process isolation rather than full OS virtualization

This project uses Docker because it is more suitable for service-oriented architectures and aligns with modern infrastructure practices.

### Secrets vs Environment Variables

Environment Variables

Used for non-sensitive configuration (domain name, service names)

Easy to inject at runtime

Docker Secrets

Used for sensitive data (passwords, credentials)

Not hardcoded in Dockerfiles

Not committed to the repository

This separation improves security and follows the subject requirements.

### Docker Network vs Host Network

Host Network

Containers share the host’s network stack

Reduces isolation

Forbidden by the subject

### Docker Network

Containers communicate via internal DNS

Isolated from the host

Explicitly defined in docker-compose.yml

A custom Docker network is used to ensure controlled and secure communication between services.

### Docker Volumes vs Bind Mounts

Bind Mounts

Direct mapping to arbitrary host paths

Less portable

More error-prone

Docker Volumes

Managed by Docker

More portable and safer

Recommended for persistent data

Docker volumes are used to store:

the WordPress database,

WordPress website files.
### Resources
https://docs.docker.com/ - docker documentation
https://www.ibm.com/de-de/think/topics/containerization - explains containerization
https://kinsta.com/de/blog/was-ist-docker/  - explains docker
https://medium.com/@ssterdev/inception-guide-42-project-part-i-7e3af15eb671 - helpful guide 

Use of AI

AI tools were used only as a support tool, in accordance with the 42 AI guidelines:

to clarify Docker concepts and best practices,

to help structure documentation,

to assist in understanding configuration errors.

All generated content was reviewed, tested, and fully understood before being integrated.
No AI-generated code was used without manual verification and comprehension.



