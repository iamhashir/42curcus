Subtree helper — importing a local repo into this workspace

Purpose
- Document the helper command used to import an external/local Git repository into this workspace using `git subtree`.

Example command
- git subtree add --prefix=rank5/cpp09 ../CPP09 master

What this does
- `--prefix=rank5/cpp09`: destination path inside this repository where the subtree content will be placed.
- `../CPP09`: the source repository (can be a relative path, absolute path, or a remote URL/remote name).
- `master`: the branch in the source repository to import.

Notes & prerequisites
- Run the command from this repository's root directory (or adjust paths accordingly).
- The source (`../CPP09`) must be an accessible Git repository. For local imports, a relative path like `../CPP09` is fine.
- `git subtree` preserves the imported repository's history and creates a commit(s) in this repository.
- The operation creates a merge commit in this repo; treat it like a normal merge (resolve conflicts if they occur).

Common follow-ups
- Update the imported subtree later:
  - `git subtree pull --prefix=rank5/cpp09 ../CPP09 master`
- Push changes from the subtree back to the source repo:
  - `git subtree push --prefix=rank5/cpp09 <remote-or-url> master`
- Remove the subtree (irreversible to recover history here without backup):
  - `git rm -r rank5/cpp09` and commit the removal.

Best practices
- Prefer using a remote URL or adding the source as a remote (`git remote add cpp09 <url>`) and using that remote name in the subtree command.
- Ensure you have a clean working tree and a backup branch before running `git subtree add` so you can recover if results aren't as expected.

Troubleshooting
- If you see conflicts, resolve them like a merge conflict and commit.
- If the source repository isn't found, confirm the path or URL and that you have necessary permissions.

If you want, I can run the import command for you or adjust the README to include different source/branch examples.
