# Malik Hashir — Systems & Real-Time Full-Stack Engineer

I build performance-critical software from first principles: systems where memory, latency, and failure modes are explicit, and correctness matters more than convenience.

---

**Core Domains**

- Low-level systems (C / C++)
- Concurrency & real-time behavior
- Full-stack architecture under constraints

**Capstone System**

- 🏆 **ft_transcendence (MINA GAMES)**
- Real-time multiplayer gaming platform
- Reactor Framework Architect (designed & built custom 3kb JSX runtime)

**Training Environment**

- 42 Network — peer-evaluated, no-library, failure-intolerant

---

────────────────────────  
**Below is the complete archive of my 42 Cursus work**  
────────────────────────

## 🏆 Capstone System — ft_transcendence (MINA GAMES)

**ft_transcendence is a real-time, distributed multiplayer gaming platform**, developed as the final capstone of the 42 curriculum.

### Why this project matters

This system integrates:
- **Real-time games**: Pong (2-player, 4-player, AI modes), Connect 4 with matchmaking
- **Network synchronization**: WebSocket-based state management with authoritative server
- **Stateful frontend**: Custom Reactor framework with isolated hook contexts per page
- **Persistent data**: Player stats, tournaments, match history, achievements
- **Social features**: Friends system, real-time presence tracking

All under **hard constraints**:
- No frontend frameworks (built Reactor from scratch)
- Deterministic behavior required (no Virtual DOM unpredictability)
- Desync and latency treated as critical bugs, not edge cases

### System Architecture (High-Level)

**Frontend**
- Reactor (~3kb custom JSX runtime, React-like API)
- File-based routing with dynamic params (`pages/user/[id].tsx` → `/user/:id`)
- Hook system: `useState`, `useEffect`, `useRef`, `useMemo`, `useLocation`
- Modal system with focus trapping and accessibility
- Direct DOM manipulation (no Virtual DOM)
- Page-scoped hook contexts (isolated state per route)

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
- **State synchronization**: Authoritative server pattern prevents client-side cheating and desync
- **Reconnection handling**: Graceful reconnects without corrupting active game state
- **Real-time physics**: Ball/paddle collision over WebSockets with <50ms latency targets
- **Custom routing**: File-based router with dynamic params and regex matching
- **Hook isolation**: Per-page hook contexts prevent state leaks during navigation
- **Modal accessibility**: Focus trapping, scroll lock, keyboard navigation (Escape to close)
- **No Virtual DOM**: Direct DOM updates with deterministic lifecycle control

**→** [Full ft_transcendence Documentation](./rank6/ft_transcendence)

---

## 👥 Technical Leadership

### Malik Hashir (mhashir)
**Founder • Product Owner • System Architect • Lead Engineer**

Malik drove the project end-to-end: defining the product vision, system boundaries, and technical direction while actively engineering core components across the stack.

He:
- Architected the overall system design, aligning real-time constraints across frontend, backend, and networking layers
- Designed and implemented **Reactor**, a custom JSX runtime and hook system to ensure deterministic frontend behavior
- Defined the execution model, data flow, and failure handling strategy for real-time multiplayer gameplay
- Structured the project roadmap, decomposed work into frontend/backend domains, and coordinated delivery
- Reviewed and validated all major features for correctness, performance, and architectural coherence
- Contributed directly to backend core logic, real-time game loops, and state synchronization mechanisms

This role combined **technical leadership, architectural ownership, and hands-on systems engineering**—not coordination alone.

---

## ⚛️ Reactor — Custom Frontend Runtime (React-like, 3kb, Zero Dependencies)

**Reactor is a lightweight JSX framework built from scratch** with pure DOM manipulation and React-like ergonomics. No React, no Preact, no dependencies.

### Why Reactor exists

Mainstream frameworks (React, Vue):
- Hide rendering costs behind Virtual DOM diffing
- Abstract timing via schedulers and Fiber reconciliation
- Optimize for component flexibility, not predictability

For **real-time multiplayer games**, this causes:
- **Frame drift**: Unpredictable re-render timing
- **State races**: Hook execution order ambiguity
- **Debugging friction**: Opaque reconciliation algorithms

Reactor was designed to **make execution deterministic and costs explicit**.

### What Reactor implements (from first principles)

**JSX Runtime**
- Custom factory: `createReactor(tag, props, children)`
- Fragment support: `<>...</>` (no wrapper elements)
- Direct DOM creation: `document.createElement()`, no Virtual DOM

**Hook System** (React-compatible API)
- `useState`: State with functional updates
- `useEffect`: Side effects with dependency tracking and cleanup
- `useRef`: Mutable refs persisting across renders
- `useMemo`: Value memoization with shallow comparison
- `useLocation`: Reactive URL subscriptions

**File-Based Routing** (no config files)
- Static routes: `pages/dashboard.tsx` → `/dashboard`
- Dynamic routes: `pages/user/[id].tsx` → `/user/:id` with regex matching
- Param injection: Route params passed as component props
- O(1) static lookup, regex patterns for dynamic routes

**Modal System**
- Focus trapping (Tab cycles within modal)
- Scroll lock (`overflow: hidden` on body)
- Keyboard navigation (Escape to close)
- Accessibility: `role="dialog"`, `aria-modal="true"`

**Rendering Pipeline**
```
1. resetHooks(pageKey)     → Cleanup old effects, set hook context
2. renderFn()              → Execute component, collect DOM
3. container.replaceChildren() → Write to DOM
4. runPendingRefs()        → Assign ref.current values
5. flushEffects()          → Execute queued effects
```

### What Reactor deliberately avoids
- **Virtual DOM**: No diffing, no reconciliation overhead
- **Fiber scheduler**: No concurrent rendering, no priority lanes
- **Implicit behavior**: Every re-render is triggered explicitly via `setState`
- **Component memoization**: Full page re-render on state change (intentional)

### Architecture Characteristics

**What's fast:**
- Direct DOM writes (no diff algorithm)
- Hook lookup: O(1) via index
- Static route resolution: O(1) hash lookup
- Bundle size: **~3kb** vs React's ~40kb

**Trade-offs:**
- Full page re-render on any state change (acceptable for small pages)
- No component-level optimization (use `useMemo` manually)
- No server-side rendering
- Isolated hook contexts per page (prevents cross-page state leaks)

**This is not "reinventing React for fun."**  
**This is controlling the execution model** to ensure deterministic behavior for real-time systems where frame timing and state consistency are non-negotiable.

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
