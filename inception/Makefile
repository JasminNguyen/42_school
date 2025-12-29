
# Default Docker Compose file
DC := docker compose -f ./srcs/docker-compose.yml 

# Default target
all: up

# (Re)Build the Docker images and start
build:
	@$(DC) up   -d --build

# Start the services in detached mode (without rebuilding, it assumes images are already built)
up:
	@$(DC) up -d

# Stop the services
down:
	@$(DC) down

# Remove containers, volumes, and networks
clean:
	@$(DC) down -v

# Rebuild the Docker images and restart services
rebuild:
	@$(DC) down
	@$(DC) up -d --build
	
.PHONY: all build up down clean rebuild
