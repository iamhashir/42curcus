*This project has been created as part of the 42 curriculum by mhashir.*

# Inception

## Description

Inception is a system administration project focused on building a secure, containerized web infrastructure using **Docker** and **Docker Compose**, entirely inside a **Virtual Machine**.

The goal is to design and deploy a minimal but production-like stack composed of:
- **NGINX** acting as the single HTTPS entry point
- **WordPress** running with `php-fpm`
- **MariaDB** as the database backend

All services are isolated in dedicated containers, connected through a Docker network, and configured with persistent storage and secure secret handling. This project emphasizes understanding container runtime behavior, network isolation, TLS security, and infrastructure reproducibility.

---

## Instructions

### Requirements

- Linux Virtual Machine
- Docker and Docker Compose
- Make
- Git

### Installation & Execution

1. Clone the repository:
   ```bash
   git clone <REPO_URL>
   cd inception
   ```

2. Configure the environment:

   - Edit `srcs/.env` with your domain and credentials
   - Secrets are automatically managed by Docker (not committed to version control)

3. Build and start the infrastructure:

   ```bash
   make
   ```

4. Access the website:

   ```
   https://mhashir.42.fr
   ```

### Stopping the Infrastructure

```bash
make down
```

### Cleaning Up

```bash
make clean
```

---

## Project Description

### Overview

The Inception project is a containerized infrastructure deployed using Docker and Docker Compose. The architecture consists of three primary services, each running in its own container with isolated configurations and persistent storage.

### Services

- **NGINX**
  - Acts as the reverse proxy and TLS terminator
  - Handles HTTPS (TLS 1.2/1.3 only)
  - Exposes port 443 exclusively
  - Routes requests to WordPress backend

- **WordPress**
  - Runs `php-fpm` for PHP script execution
  - No built-in web server; relies on NGINX
  - Stores website files in a persistent volume
  - Connected to MariaDB for data persistence

- **MariaDB**
  - Provides relational database backend
  - Stores WordPress data persistently
  - Accessible only within the internal Docker network
  - Runs with secure root and user credentials

### Project Structure

```
srcs/
├── docker-compose.yml          # Orchestration configuration
├── requirements/
│   ├── nginx/
│   │   ├── Dockerfile
│   │   ├── .dockerignore
│   │   ├── conf/               # NGINX configuration files
│   │   └── tools/              # NGINX entrypoint scripts
│   ├── wordpress/
│   │   ├── Dockerfile
│   │   ├── .dockerignore
│   │   ├── conf/               # WordPress configuration
│   │   └── tools/              # WordPress entrypoint scripts
│   └── mariadb/
│       ├── Dockerfile
│       ├── .dockerignore
│       ├── conf/               # MariaDB configuration files
│       └── tools/              # MariaDB entrypoint scripts
```

### Persistent Storage

All persistent data is stored on the host machine under:

```
/home/mhashir/data/
```

Volumes used:
- `wordpress_volume`: Stores WordPress application files
- `mariadb_volume`: Stores MariaDB database files

This ensures data persistence across container restarts and VM reboots.

### Network Architecture

Services communicate through a custom Docker network (`inception`):
- Internal DNS resolution between services
- No direct access to the host network
- NGINX is the sole external entry point

---

## Design Choices

### Virtual Machines vs Docker

| Virtual Machines | Docker |
|---|---|
| Virtualize entire operating system | Virtualize only processes |
| Heavy resource usage (GB of RAM per VM) | Lightweight (MB per container) |
| Slow startup (minutes) | Fast startup (seconds) |
| Full isolation at OS level | Process-level isolation |

**Choice**: Docker was selected to focus on **process-level isolation** and efficient resource utilization, not full OS emulation. Docker provides sufficient isolation for multi-service deployments while maintaining performance and portability.

---

### Secrets vs Environment Variables

| Environment Variables | Docker Secrets |
|---|---|
| Plain text in containers | Encrypted at rest |
| Easy to inspect and expose | Mounted as temporary files |
| Suitable for non-sensitive config | Designed for passwords/credentials |
| Can be accidentally logged | Not exposed in logs or images |

**Choice**: Environment variables are used for **non-sensitive configuration** (domains, settings). Docker Secrets are used for **sensitive credentials** (database passwords, WordPress admin passwords) and are never committed to version control.

---

### Docker Network vs Host Network

| Host Network | Docker Network |
|---|---|
| Containers share host network stack | Each container has isolated network namespace |
| No internal DNS resolution | Internal DNS resolution available |
| Port conflicts possible | Clean port isolation |
| Security risk: direct access | Containers only accessible via defined ports |

**Choice**: A custom Docker network is mandatory for this project. It provides **clean service isolation** while maintaining inter-service communication through internal DNS (services reference each other by container name).

---

### Docker Volumes vs Bind Mounts

| Bind Mounts | Docker Volumes |
|---|---|
| Direct filesystem paths on host | Managed by Docker daemon |
| Environment-dependent paths | Portable across machines |
| Can cause permission issues | Consistent permissions |
| Tightly coupled to host | Decoupled from host |

**Choice**: Docker **Volumes** are used for all persistent data. They provide **portability**, **consistency**, and **ease of management** across different environments and machines. Volumes are the Docker-recommended approach for production deployments.

---

## Resources

### Official Documentation

- [Docker Documentation](https://docs.docker.com)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [MariaDB Documentation](https://mariadb.com/kb/en/documentation/)
- [WordPress Documentation](https://wordpress.org/documentation/)

### AI Usage

AI tools were used for:

- **Clarification of Docker concepts**: Understanding PID 1 behavior, volume management, and network isolation
- **Documentation review**: Verifying Chapter VI requirements and README format compliance
- **Architectural validation**: Confirming design decisions against Docker best practices

**Important**: No AI-generated code was blindly copied. All Dockerfiles, configuration files, and scripts were written, tested, and understood by the author. AI was used only for research and validation, not code generation.

---