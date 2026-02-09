# Malik Hashir — Systems & Real-Time Full-Stack Engineer

I build performance-critical software from first principles: systems where memory, latency, and failure modes are explicit, and correctness matters more than convenience.

---

**Core Domains**

- Low-level systems (C / C++)
- Concurrency & real-time behavior
- Full-stack architecture under constraints

**Capstone System**

- 🏆 **ft_transcendence (MINA GAMES)**
- Real-time multiplayer platform
- Custom frontend runtime (Reactor)

**Training Environment**

- 42 Network — peer-evaluated, no-library, failure-intolerant

---

────────────────────────  
**Below is the complete archive of my 42 Cursus work**  
────────────────────────

## 🏆 Capstone System — ft_transcendence (MINA GAMES)

**ft_transcendence is a real-time, distributed multiplayer gaming platform**, developed as the final capstone of the 42 curriculum.

### Why this project matters

This system combines:
- Real-time game loops
- Network synchronization
- Stateful frontend rendering
- Backend orchestration
- Persistent competitive data

All under **hard constraints**:
- No frontend frameworks
- Deterministic behavior required
- Latency and desynchronization treated as critical bugs

### System Architecture (High-Level)

**Frontend**
- Reactor (custom runtime)
- Deterministic rendering pipeline
- Explicit state ownership per game instance

**Backend**
- Node.js (Fastify)
- WebSocket-based real-time messaging
- Authoritative game state enforcement

**Data Layer**
- SQLite + Prisma
- Player stats, matchmaking, tournaments

**DevOps**
- Dockerized services
- Environment parity for evaluation & defense

### Engineering Challenges Solved
- Preventing state divergence between clients
- Handling reconnects without corrupting game state
- Synchronizing physics-like systems over unreliable networks
- Avoiding frontend race conditions without a virtual DOM

**→** [Full ft_transcendence Documentation](./rank6/ft_transcendence)

---

## ⚛️ Reactor — Custom Frontend Runtime

**Reactor is a custom frontend framework built from scratch** to support deterministic, real-time applications where mainstream frameworks become liabilities.

### Why Reactor exists

Mainstream frameworks:
- Hide rendering cost
- Abstract away timing
- Optimize for UI flexibility, not determinism

For real-time games, this causes:
- Frame drift
- Race conditions
- Unpredictable state updates

Reactor was designed to **make those costs explicit**.

### What Reactor implements (from first principles)
- Custom JSX runtime
- Hook system (`useState`, `useEffect`, `useRef`, `useMemo`)
- File-based routing
- Explicit lifecycle control
- No virtual DOM

### What Reactor deliberately avoids
- Implicit re-renders
- Opaque reconciliation
- Framework-level magic

**This is not "reinventing React for fun."**  
**This is controlling the execution model.**

---

## 📂 Purpose

This repository is a **complete, chronological archive** of all projects completed during the 42 Cursus, preserved in their original form for transparency and evaluation integrity.

## 🎓 Evaluation Reality

At 42, projects generally must be built **without** external libraries (building your own `printf`, `malloc`, or game engine first). All code is subject to:
*   **Peer Defense:** Explained line-by-line to 3 random peers.
*   **Strict Norms:** Code style enforced by an automated checker (the "Norm").
*   **No Partial Credit:** A single critical memory error (leak, invalid access, undefined behavior) can result in a failing grade (0%).

## 📈 Skill Evolution Map

The 42 Cursus is structured as increasing ranks, each enforcing new technical constraints. This repository reflects that progression **without retroactive cleanup**.

*   **Rank 0–1 (C Fundamentals):** Manual memory management, libc recreation, system administration.
*   **Rank 2–3 (Systems & Concurrency):** Algorithms, UNIX signals, process control, threads/mutexes.
*   **Rank 4–5 (C++ & Architecture):** Object-Oriented Programming, networking, Docker, containerization.
*   **Rank 6 (Full-Stack Capstone):** Distributed real-time systems, WebSocket architecture, SPA design.

## 🗂 Repository Structure (Intentional, Unmodified)

This repository mirrors the **official 42 rank progression**.  
Early work is preserved to show **growth**, not perfection.

```
rank0–1  → C fundamentals, memory, system basics
rank2–3  → algorithms, IPC, concurrency
rank4–5  → C++, networking, containers
rank6    → distributed real-time system
```

> **How to Read This Repository**
>
> * Start with **ft_transcendence** to see end-to-end system design.
> * Jump to ⭐ projects to evaluate depth.
> * Early ranks demonstrate fundamentals; later ranks demonstrate synthesis.

<details>
<summary>Full Directory Tree</summary>

```text
.
├── Contributing.md
├── rank0
│   └── libft
├── rank1
│   ├── born2beroot
│   ├── ft_printf
│   └── get_next_line
├── rank2
│   ├── fract-ol
│   ├── minitalk
│   └── push_swap
├── rank2_exam
│   ├── rank_1
│   ├── rank_2
│   ├── rank_3
│   └── rank_4
├── rank3
│   ├── minishell
│   └── philosphers
├── rank4
│   ├── cpp00
│   ├── cpp01
│   ├── cpp02
│   ├── CPP03
│   ├── cpp04
│   ├── cub3d
│   └── netpractice
├── rank5
│   ├── CPP05
│   ├── CPP06
│   ├── CPP07
│   ├── CPP08
│   ├── CPP09
│   ├── ft_irc
│   └── inception
├── rank5_exam
│   ├── cpp_module00
│   ├── cpp_module01
│   └── cpp_module02
├── rank6
│   └── ft_transcendence
└── README.md
```

</details>

---

## 📚 Projects Archive

> ⭐ marks projects that best represent my engineering depth for external reviewers.

### Rank 0

- ⭐ **[libft](./rank0/libft)** *(Foundation)*: My very first own library. A collection of standard C library functions and other utility functions.

### Rank 1

- **[born2beroot](./rank1/born2beroot)**: System Administration related exercises.
- **[ft_printf](./rank1/ft_printf)**: Recreating the printf function.
- **[get_next_line](./rank1/get_next_line)**: A function that reads a line ended by a newline character from a file descriptor.

### Rank 2

- **[fract-ol](./rank2/fract-ol)**: A 2D fractal rendering program.
- **[minitalk](./rank2/minitalk)**: A client-server communication program using UNIX signals.
- ⭐ **[push_swap](./rank2/push_swap)** *(Algorithmic optimization)*: Sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.

### Rank 3

- ⭐ **[minishell](./rank3/minishell)** *(Process control & parsing)*: A simple shell implementation.
- **[philosphers](./rank3/philosphers)**: A project about threading, mutexes, and semaphores (The Dining Philosophers Problem).

### Rank 4

- **[CPP Modules 00-04](./rank4)**: Introduction to C++ and Object-Oriented Programming.
  - [CPP00](./rank4/cpp00): Namespaces, classes, member functions, stdio streams.
  - [CPP01](./rank4/cpp01): Memory allocation, pointers to members, references.
  - [CPP02](./rank4/cpp02): Ad-hoc polymorphism, operator overloading.
  - [CPP03](./rank4/CPP03): Inheritance.
  - [CPP04](./rank4/cpp04): Subtype polymorphism, abstract classes, interfaces.
- **[netpractice](./rank4/netpractice)**: IP addressing, masks, and subnets.
- ⭐ **[cub3d](./rank4/cub3d)** *(Graphics & Math)*: A 3D game using raycasting (Wolfenstein 3D style).

### Rank 5

- **[CPP Modules 05-09](./rank5)**: Advanced C++ content.
  - [CPP05](./rank5/CPP05): Repetition and Exceptions.
  - [CPP06](./rank5/CPP06): C++ casts.
  - [CPP07](./rank5/CPP07): Templates.
  - [CPP08](./rank5/CPP08): Templated containers, iterators, algorithms.
  - [CPP09](./rank5/CPP09): STL.
- **[inception](./rank5/inception)**: System Administration including Docker.
- ⭐ **[ft_irc](./rank5/ft_irc)** *(Networking & Protocol Design)*: Creating an IRC server from scratch.

### Rank 6

- 🏆 **[ft_transcendence](./rank6/ft_transcendence)** *(Capstone — see dedicated section above)*

## 📝 Exams

- **[Rank 2 Exam](./rank2_exam)**
- **[Rank 5 Exam](./rank5_exam)**

## 🛠 Utils

- **[Utils](./Utils)**: Various utilities, scripts, and evaluation sheets used throughout the curriculum.

---

## 🧠 Engineering Philosophy

- Prefer explicit control over convenience
- Understand abstractions by rebuilding them
- Treat undefined behavior as a design failure
- Optimize for correctness before elegance

---

**Status:** Open to systems, backend, or performance-critical full-stack roles.
