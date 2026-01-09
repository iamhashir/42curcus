# From Notation to Reverse Polish Notation (RPN)

A ground‑up explanation of **notation**, **semantics**, and why **Reverse Polish Notation** exists at all. This document is written to move from human math intuition to machine‑level execution without gaps.

---

## 1. What Is Notation?

**Notation** is a symbolic system for expressing computation.

Every notation has two inseparable parts:

* **Syntax** — how symbols are arranged
* **Semantics** — what that arrangement *means*

Example:

* `3 + 4`
* `+ 3 4`
* `3 4 +`

Different syntax. Same semantics: *addition of 3 and 4*.

> Notation is the interface between thought and execution.

---

## 2. Infix Notation (Human‑First)

### Definition

**Infix notation** places the operator **between** operands.

```
3 + 4
```

### Why It Exists

* Mirrors natural language ("three plus four")
* Reads left‑to‑right
* Ideal for pen‑and‑paper math

### The Hidden Complexity

Infix requires extra rules:

* Operator precedence (`*` before `+`)
* Associativity (left vs right)
* Parentheses to remove ambiguity

Example:

```
3 + 4 * 5
```

Humans assume `*` binds tighter.
Machines must be **told**.

> Infix is intuitive but grammatically expensive.

---

## 3. Why Infix Is Hard for Machines

To evaluate infix, a machine must:

1. Tokenize symbols
2. Apply precedence tables
3. Handle parentheses
4. Build an internal tree anyway

That tree is the *real* computation.

So infix is not executed directly — it is **translated**.

---

## 4. Polish Notation (Prefix)

### Origin

Invented in the **1920s** by Polish logician **Jan Łukasiewicz**.

Goal: eliminate ambiguity in logical expressions.

### Definition

**Prefix notation** places the operator **before** operands.

```
+ 3 4
```

### Why It Works

* No parentheses
* No precedence rules
* Scope is explicit

Parsing rule:

> The first symbol defines the operation applied to what follows.

### Mental Model

Prefix matches **expression trees** naturally.

* Root first
* Children next

> Prefix is tree‑first thinking.

---

## 5. Reverse Polish Notation (Postfix)

### Origin

Developed in the **1950s** for early computers and stack machines.

Optimized for:

* Minimal memory
* Linear execution
* Simple hardware

### Definition

**Postfix notation** places the operator **after** operands.

```
3 4 +
```

### Core Property

RPN is evaluated using a **stack**.

Algorithm:

1. Read tokens left to right
2. Push numbers onto stack
3. On operator:

   * Pop operands
   * Apply operator
   * Push result back

No lookahead. No ambiguity.

> RPN is execution‑first thinking.

---

## 6. Timeline Summary

| Notation      | Era      | Designed For   |
| ------------- | -------- | -------------- |
| Infix         | ~300 BCE | Human math     |
| Prefix        | 1920s    | Logic & proofs |
| Postfix (RPN) | 1950s    | Computers      |

Notations evolved with **cognitive needs**.

---

## 7. Semantics vs Syntax (The Key Insight)

Consider:

```
(3 + 4) * 5
```

* Infix: `(3 + 4) * 5`
* Prefix: `* + 3 4 5`
* Postfix: `3 4 + 5 *`

All represent the **same semantic tree**.

What changes is the **order of traversal**:

* Infix → inorder
* Prefix → preorder
* Postfix → postorder

> Semantics live in the tree. Notation chooses the walk.

---

## 8. Why Compilers Love RPN

Compilers convert infix → postfix because:

* Stack machines are simple
* Evaluation is linear
* No precedence logic at runtime

RPN turns parsing into execution.

This is why:

* Your CPP09 exercise uses RPN
* Old HP calculators used RPN
* Virtual machines rely on stacks

---


## 9. Final Perspective

RPN is not clever.

It is **honest**.

It exposes the real mechanics of computation instead of hiding them behind grammar.
