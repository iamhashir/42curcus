# shuf — Random number generator

## Purpose

> `shuf` generates numbers in random order.

It is used to quickly create randomized integer input for programs that
accept numbers as command-line arguments.

---

## Usage with a program

> ```bash
> ./PmergeMe $(shuf -i 1-1000 -n 3000 | tr "\n" " ")
> ```

This runs `PmergeMe` with 3000 randomly ordered integers.

---

## Parameters

### `-i LO-HI`

> ```bash
> -i 1-1000
> ```

- Defines the inclusive numeric range
- Generated values are between `LO` and `HI`

---

### `-n COUNT`

> ```bash
> -n 3000
> ```

- Specifies how many numbers to generate
- Duplicates may appear if `COUNT` exceeds the range size

---

### `|` (pipe)

> ```bash
> |
> ```

- Sends the output of one command into another command

---

### `tr "\n" " "`

> ```bash
> tr "\n" " "
> ```

- Replaces newline characters with spaces
- Produces space-separated output suitable for command-line arguments

---

### `$()` — command substitution

> ```bash
> $(command)
> ```

- Executes `command`
- Replaces `$()` with the command’s output
- Allows generated values to be passed as arguments to a program

---

## Result

> ```text
> 42 7 13 999 7 88 ...
> ```

The numbers are passed to the program exactly as if typed manually.
