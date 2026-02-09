# 🧠 My Personal FD Table Adventure — From Zero to Black Hat with UNIX I/O

> A raw, hands-on journey into the guts of file descriptors, buffering, and terminal manipulation.  
> This repo is not a tutorial — it's my brain dump, every question I asked, every lightbulb moment I had, and every horror I accidentally unleashed by closing stdin, stdout, and stderr.  
> Documented with real experiments, confusion, and ultimate clarity.

---

## 🎬 Origin Story

I started with this innocent question:

> **"What is `fd` at the OS level? What’s the deal with `stdin`, and why are `fd` and `stdin` always together?"**

I didn’t want a theory dump — I wanted to see the beast **in action**.  
So I wrote a small program to open 10 files and just print their file descriptors. Here’s what I learned from that:

- File descriptors start from **3**, because `0`, `1`, and `2` are **already taken** by:
  - `0`: stdin (keyboard)
  - `1`: stdout (terminal)
  - `2`: stderr (error stream)

So basically, the OS gives every process **3 pre-wired connections**, like:

```bash
stdin ← keyboard  
stdout → terminal  
stderr → terminal (errors)
```

---

## 🛠️ I Wrote This Program to See the FDs

Here’s the code snippet that puzzled me:

```c
snprintf(filename, sizeof(filename), "test%d.txt", i + 1);
```

### What I Learned:
- `filename` is a **char array of 20 bytes**, just a temporary memory bucket.
- `snprintf()` safely formats strings into memory, e.g., `test1.txt`, `test2.txt`, etc.

💡 **Key Insight**: We’re not printing to the screen — we’re formatting into memory!

---

## 🔪 Then I Got Violent: Closed 0, 1, and 2

> Just to see what happens... and the OS didn’t even blink 😳

### Code:

```c
close(0); // stdin
close(1); // stdout
close(2); // stderr
```

Then I opened some files:

```c
int fd = open("test1.txt", O_WRONLY | O_CREAT);
```

👀 It returned fd = **0**.

💡 **AHA!** The OS reuses the lowest available FD number — so it gave my file `fd = 0`, effectively hijacking `stdout`. From this point on:

```c
printf(...) → writes to test1.txt
write(0, ...) → writes to test1.txt
```

No more terminal output.

---

## 😵 Why `write(0, ...)` Showed Up *Before* `printf(...)`

This was my *what-the-heck* moment.

Turns out:

- `write()` is **unbuffered** — outputs instantly.
- `printf()` is **buffered** — waits for newline or flush.

So even if I wrote:

```c
printf("Hello\n");
write(0, "Raw\n", 4);
```

I’d see:

```
Raw
Hello
```

Unless I added:

```c
fflush(stdout);
```

Which forces `printf()` to dump its buffer right away.

---

## 🧪 Duplicating FDs: `dup()` vs Just Copying the Int

Another experiment I ran:

```c
int fd2 = fd1;       // just copies the int
int fd3 = dup(fd1);  // asks OS for a new tracked FD
```

I closed `fd1` and tried reading with `fd2` and `fd3`.

### Result:
- `fd2` crashed — because it's just a raw number, not managed.
- `fd3` worked — because it’s **a real OS-backed FD**.

✨ **Lightbulb moment**: `dup()` creates a new pointer to the same file offset — like a sibling with shared memory.

---

## 🔗 Internal Anatomy (My Mental Model Now)

| Layer       | What it does                            |
| ----------- | --------------------------------------- |
| FD Table    | Maps 0, 1, 2, ... to File Table entries |
| File Table  | Tracks file offset, mode, flags         |
| Inode/Vnode | Tracks actual file on disk (metadata)   |

So multiple FDs (via `dup()` or `fork()`) can point to **the same file table entry**, meaning they share **offsets** — they move together.

This is why file seeking, reading, and writing **moves the cursor** across all shared FDs.

---

## 🧠 Learnings Locked In

- `fd` is not a file — it's just a key into the FD table.
- `close(1)` → makes OS give `1` to the next opened file.
- `write()` = instant, `printf()` = lazy.
- `dup()` = real OS-level clone, not just copying an int.
- Buffering matters! Always `fflush(stdout)` if output order is important.
- The OS **always gives you 0, 1, 2** — stdin, stdout, stderr — by default.

---

## 💥 What I Broke for Fun

- Closed all 3 system FDs (`0`, `1`, `2`).
- Hijacked `stdout` into a file.
- Made `printf()` unknowingly write to a file.
- Used `dup()` to create cloned file pointers with shared offset.
- Rewrote my mental model of I/O forever.

---

## 🪓 Things I Want to Explore Next

- `dup2()` and redirecting to specific FDs.
- `pipe()`, `fork()`, and inter-process FD sharing.
- Restoring terminal after closing 0,1,2 (pro-level hack).
- How the shell restores your FD table when launching processes.

---

## 📜 This README = My Brain on Fire

I asked dumb questions, made weird observations, broke everything, and **now I understand UNIX like a surgeon with a flashlight.**

This is the real learning path — not StackOverflow copy-paste.

---

🧠 *– mhashir@lab1r4s2*
