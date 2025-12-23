# Scripts Repository

Welcome to the **Scripts Repository**, a collection of powerful and customizable scripts designed to enhance your macOS experience and streamline your workflow. This repository contains two main folders: `zshrc` and `brew`, each serving distinct purposes.

---

## 📂 Folder Structure

### 1. **mac/zshrc**
This folder contains configurations and aliases for the Zsh shell, tailored for macOS users. The `.zshrc` file is the heart of this folder, providing shortcuts and environment variables to optimize your terminal experience.

#### Key Features:
- **Aliases**: Simplify common commands like navigating directories, editing `.zshrc`, and using Visual Studio Code.
- **Environment Variables**: Pre-configured paths for Homebrew and custom binaries.
- **Customizations**: Easily extendable for personal preferences.

#### Usage:
1. Copy the `.zshrc` file to your home directory:
   ```bash
   cp /Users/mhashir/Desktop/scripts/mac/zshrc/.zshrc ~/.zshrc
   ```
2. Reload the shell configuration:
   ```bash
   source ~/.zshrc
   ```
3. Enjoy the enhanced terminal experience with handy aliases and optimized settings.

---

### 2. **mac/brew**
This folder contains a comprehensive script (`brew.sh`) for setting up and managing Homebrew on macOS, specifically tailored for 42 School environments.

#### Key Features:
- **Automated Setup**: Clone Homebrew to a custom directory (`/goinfre`) and create symlinks for easy access.
- **Environment Configuration**: Automatically updates `.zshrc` with Homebrew paths and aliases.
- **Dark Mode Activation**: Switches macOS to dark mode for a modern aesthetic.
- **Dock Cleanup**: Resets the macOS Dock to a clean state.
- **Tool Installation**: Installs essential tools like `fzf` for enhanced productivity.

#### Usage:
1. Run the script:
   ```bash
   bash /Users/mhashir/Desktop/scripts/mac/brew/brew.sh
   ```
2. Follow the on-screen instructions to complete the setup.
3. Use the provided aliases for efficient Homebrew management:
   - `brewi`: Install packages.
   - `brewu`: Update and upgrade packages.
   - `brewfix`: Diagnose and clean up Homebrew issues.
   - `brews`: Search for packages.
   - `bls`: List installed packages.
   - `binfo`: Get information about packages.

---

## 💡 Tips for Customization
- **Extend `.zshrc`**: Add your own aliases and environment variables to suit your workflow.
- **Modify `brew.sh`**: Customize the script to install additional tools or change macOS settings.

---

## 🛠️ Requirements
- macOS
- Zsh shell
- Homebrew (installed via `brew.sh`)

---

## 📜 License
This repository is open-source and free to use. Feel free to modify and share it as needed.

---

## 🤝 Contributions
Contributions are welcome! If you have ideas for improving these scripts, feel free to submit a pull request or open an issue.

---

## 📧 Contact
For questions or support, reach out to **mhashir** at [ihashirr@gmail.com].

---
