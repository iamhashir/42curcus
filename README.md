# Malik Hashir — Systems & Real-Time Full-Stack Engineer

I work on systems where **latency**, **memory layout**, and **execution order** are first-class concerns. If I can’t explain a behavior down to control flow and allocation, I don’t ship it.

---

### [👉 Full 42 Cursus Archive (Academic Record)](./README_42.md)
> *Evaluation & Detailed Project History*

---

## 🏆 Flagship System: [ft_transcendence](./rank6/ft_transcendence)
**Real-time distributed multiplayer gaming platform.**

*   **Roles:** Product Owner · Project Manager · Technical Architect (Team of 4)
    *Defined system architecture, feature roadmap, and coordinated cross-domain execution across frontend, backend, and game engine streams.*
*   **Tech Stack:** TypeScript, Node.js (Fastify), WebSockets, Mutex-guarded State.

## ⚙️ Signature Engineering: Reactor (Deterministic JSX Runtime)

Reactor is a 3kb custom JSX runtime built to enforce deterministic rendering in a real-time environment.

Modern UI frameworks introduce schedulers, reconciliation layers, and implicit batching. These abstractions improve developer velocity, but they obscure execution order and introduce timing variance under load.

In a 60fps multiplayer system, rendering is not a background concern. It is part of the simulation boundary.

Reactor enforces:

* **No virtual DOM**
* **No scheduler**
* **No reconciliation phase**
* **Explicit state transitions**
* **Synchronous render → commit → effect lifecycle**


Each state update results in a full page re-render by design. Predictability was chosen over partial diff optimization. Pages are intentionally small; cost is bounded.

This model guarantees:

* Deterministic hook execution order
* No frame drift from deferred work
* No priority lanes or hidden batching
* Traceable DOM mutations

Reactor was not built to compete with React.
It was built to control execution timing in a real-time multiplayer system.

### [👉 VIEW TECHNICAL DEEP DIVE (Architecture & Implementation)](./rank6/ft_transcendence/Readme.md)

---

## 🧠 Core Philosophy
*   **Systems First:** I don’t just use tools; I rebuild them to understand their costs.
*   **Determinism:** Latency handling and state synchronization are explicit architectural choices, not afterthoughts.
*   **Zero Magic:** If I can't explain how it works down to the syscall, I don't use it.

> **I don’t optimize for developer convenience at the cost of runtime certainty.**

---

### 📂 Repository Structure
*   **[`/rank0` - `/rank5`](./README_42.md#repository-structure-intentional-unmodified):** The C/C++ formative years (Libc, TCP/IP, Docker, Kernel basics).
*   **[`/rank6`](./rank6/ft_transcendence):** The Capstone (Distributed Systems).

**Looking for the full academic breakdown?**
[**→ Go to README_42.md**](./README_42.md)
