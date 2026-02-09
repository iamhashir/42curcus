
# External Project Integration Guide

This repository uses **two methods** to integrate external projects:

1. **Git Submodules**
2. **Git Subtree**

Below you will find which projects use which method, and the process for initializing, updating, and contributing to each.

---

## Project Integration Table

| Project Path                | Integration Type | Source URL/Repo                                    |
|-----------------------------|------------------|----------------------------------------------------|
| rank5/ft_irc                | Submodule        | https://github.com/ihashirr/IRC.git                |
| rank6/ft_transcendence      | Submodule        | https://github.com/minapong/ft_transcendence.git   |
| rank2_exam                  | Submodule        | https://github.com/iamhashir/42_examRank2.git      |
| rank5_exam                  | Submodule        | https://github.com/ihashirr/42_exam_rank_5.git     |
| rank5/CPP09                 | Subtree          | (example: ../CPP09 or remote)                      |

---

## 1. Git Submodule Projects

### Initialization (First Clone)

After cloning this repository, run:

```sh
git submodule update --init --recursive
```

This will fetch all submodule content into the correct folders.

### Adding a New Submodule

```sh
git submodule add <repo-url> <path>
git commit -m "Add submodule <name>"
```

### Updating Submodules (to latest remote commit)

```sh
git submodule update --remote --merge
```
Or, for a specific submodule:
```sh
git submodule update --remote --merge <path>
```

### Making Changes in a Submodule

1. `cd <submodule-path>`
2. Make your changes and commit them **inside the submodule**.
3. Push changes to the submodule's remote repository.
4. Return to the main repo and commit the submodule pointer update:
   ```sh
   git add <submodule-path>
   git commit -m "Update submodule <name>"
   ```

### Removing a Submodule

```sh
git submodule deinit -f <path>
git rm -f <path>
rm -rf .git/modules/<path>
git commit -m "Remove submodule <name>"
```

---

## 2. Git Subtree Projects

### Adding a Subtree

```sh
git subtree add --prefix=<path> <repo-url-or-path> <branch>
```
Example:
```sh
git subtree add --prefix=rank5/CPP09 ../CPP09 master
```

### Updating a Subtree (pull changes from source)

```sh
git subtree pull --prefix=<path> <repo-url-or-path> <branch>
```
Example:
```sh
git subtree pull --prefix=rank5/CPP09 ../CPP09 master
```

### Pushing Changes Back to Source (if you want to contribute upstream)

```sh
git subtree push --prefix=<path> <repo-url-or-remote> <branch>
```

### Removing a Subtree

```sh
git rm -r <path>
git commit -m "Remove subtree <name>"
```

---

## Best Practices

- Always ensure your working tree is clean before running subtree or submodule commands.
- For submodules, always push changes to the submodule's own repository, then update the pointer in the main repo.
- For subtrees, you can push changes back upstream if you have write access.
- Make a backup branch before major subtree or submodule operations.

---

## Troubleshooting

- **Submodule not found:** Check the path/URL and permissions.
- **Subtree conflicts:** Resolve as you would a normal merge conflict, then commit.
- **Submodule pointer out of sync:** Run `git submodule update --init --recursive`.

---

If you want, I can run the import or update commands for you, or adjust this guide for your specific needs.
