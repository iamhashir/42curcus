# Malik Hashir — Systems & Real-Time Software Engineering

A systems-focused archive of my 42 cursus work, culminating in a collaborative real-time multiplayer platform.

My work here covers **C/C++, Unix systems programming, networking, concurrency, Docker, TypeScript, Node.js, WebSockets, and frontend runtime design**.

[Full 42 Cursus Archive](./README_42.md)

---

## Flagship Project — ft_transcendence

**Real-time distributed multiplayer gaming platform built by a team of four.**

### My role

**Product Owner · Project Manager · Technical Architect**

I worked across product scope and technical architecture, coordinating frontend, backend, and game-engine work while contributing to the system design behind real-time gameplay and application state.

### Stack

- TypeScript
- Node.js / Fastify
- WebSockets
- Docker / NGINX
- Persistent application state
- Custom frontend runtime

### Source

The capstone is tracked in this cursus repository as a submodule pointing to the team repository:

- [ft_transcendence source](https://github.com/minapong/ft_transcendence/tree/198b26312e47a2c547f6ca319b46854e74a634e1)
- [Technical deep dive](./rank6/ft_transcendence/Readme.md)

---

## Reactor — Deterministic JSX Runtime

Within the capstone, I worked on **Reactor**, a compact custom JSX runtime designed to make rendering behavior explicit and predictable in a real-time application.

Instead of depending on a large UI framework, the runtime keeps state transitions and render behavior directly inspectable.

### Design goals

- Explicit state transitions
- Predictable hook execution order
- Synchronous render lifecycle
- No hidden scheduler or priority lanes
- Traceable DOM updates
- Small runtime surface area

The goal was not to replace React generally. It was to explore a frontend runtime where execution order and timing are easier to reason about in the context of a real-time multiplayer system.

### Reactor documentation

- [Reactor features](https://github.com/minapong/ft_transcendence/blob/198b26312e47a2c547f6ca319b46854e74a634e1/Frontend/src/core/Reactor/docs/reactor_features.md)
- [Reactor overview](https://github.com/minapong/ft_transcendence/blob/198b26312e47a2c547f6ca319b46854e74a634e1/Frontend/src/core/Reactor/docs/overview.md)

---

## Engineering Areas Demonstrated

### Systems programming

The earlier cursus projects build fundamentals around memory management, process behavior, file descriptors, signals, synchronization, networking, and Unix tooling.

### Concurrency and execution order

Projects involving threads, processes, and real-time state reinforced the importance of clear ownership, synchronization, and deterministic behavior.

### Networking and real-time applications

The capstone moves those fundamentals into application architecture through persistent WebSocket connections, multiplayer state synchronization, and service boundaries.

### Architecture and technical leadership

The final project required coordinating multiple domains rather than treating frontend, backend, infrastructure, and gameplay as isolated pieces.

---

## Repository Structure

- **`rank0` → `rank5`** — C/C++ and systems fundamentals
- **`rank6/ft_transcendence`** — real-time multiplayer capstone
- **[`README_42.md`](./README_42.md)** — complete academic project breakdown and evaluation history

---

## Related Work

For my full-stack, AI automation, and product engineering projects, see:

- [GitHub profile](https://github.com/iamhashir)
- [Engineering portfolio](https://cv-portfolio-five.vercel.app)
- [LinkedIn](https://linkedin.com/in/malikhashir)
