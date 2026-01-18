## Quick notes: build, run, PID 1

### Build image
```bash
docker build -t tnginx .
```
- `-t`: tag name
- `tnginx`: tag value
- `.`: build context (where the Dockerfile lives)

### Run container
```bash
docker run --rm -it tnginx
```
- `--rm`: auto-remove container when it exits
- `-it`: interactive terminal (stdin + TTY)

### Dockerfile directives
- `RUN`: executes **while building** the image (creates new layer)
- `CMD`: default process **when the container starts**

### PID 1 rule
- The `CMD` (or `ENTRYPOINT`) process becomes PID 1.
- If PID 1 exits, the container stops, even if child processes remain.
- One-off helper commands in `CMD` will end the container; long-running service must stay in the foreground.

### Practical implication
- If the main service (e.g., web server) dies, the container stops and restart policy can relaunch it.
- Avoid multiple backgrounded commands in `CMD`; keep the primary service as the foreground PID 1.


 rsync -av --delete -e "ssh -p 4242" ~/Desktop/inception/ mhashir@localhost:~/Desktop/inception/

communcation between host and vm updating codebase
