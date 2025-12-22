#!/bin/zsh
# =====================================
# Homebrew + Node.js setup for macOS (42 Labs)
# Rootless, /goinfre compatible
# =====================================

BREW_DIR="/goinfre/$USER/homebrew"
BIN_LINK="$HOME/bin"
NODE_VERSION="v18.20.3"
CHANGES_MADE=false
ALIAS_ADDED=false

echo "🧠 [SETUP] Starting Homebrew + Node.js setup..."

# STEP 1 — Check or install Homebrew
if [ -d "$BREW_DIR" ]; then
    echo "📦 [SETUP] Homebrew already exists at $BREW_DIR."
else
    echo "📥 [SETUP] Cloning Homebrew..."
    git clone https://github.com/Homebrew/brew "$BREW_DIR"
fi

# STEP 2 — Ensure ~/bin exists
mkdir -p "$BIN_LINK"

# STEP 3 — Brew symlink
if [ ! -L "$BIN_LINK/brew" ]; then
    ln -s "$BREW_DIR/bin/brew" "$BIN_LINK/brew"
    echo "🔗 [LINK] Symlink created: $BIN_LINK/brew"
fi

# STEP 4 — Add environment lines to .zshrc
add_to_zshrc() {
    local line="$1"
    if ! grep -qxF "$line" ~/.zshrc 2>/dev/null; then
        echo "$line" >> ~/.zshrc
        echo "➕ [ZSHRC] Added: $line"
        CHANGES_MADE=true
    fi
}

add_to_zshrc 'export PATH="$HOME/bin:$PATH"'
add_to_zshrc "export HOMEBREW_PREFIX=\"$BREW_DIR\""
add_to_zshrc 'export HOMEBREW_CELLAR="$HOMEBREW_PREFIX/Cellar"'
add_to_zshrc 'export HOMEBREW_REPOSITORY="$HOMEBREW_PREFIX"'

# STEP 5 — Aliases
echo "\n📌 [STEP] Adding handy brew aliases..."
add_alias() {
    local name="$1"
    local command="$2"
    local alias_line="alias $name='$command'"
    if ! grep -qxF "$alias_line" ~/.zshrc 2>/dev/null; then
        echo "$alias_line" >> ~/.zshrc
        echo "🔖 [ALIAS] Added: $name → $command"
        ALIAS_ADDED=true
    fi
}
add_alias "brewi" "brew install"
add_alias "brewl" "brew list"
add_alias "brewu" "brew update && brew upgrade"

# STEP 6 — Dark mode
echo "🌙 [THEME] Ensuring macOS is in dark mode..."
if defaults read -g AppleInterfaceStyle 2>/dev/null | grep -q "Dark"; then
    echo "✅ [THEME] Already in dark mode."
else
    osascript -e 'tell application "System Events" to tell appearance preferences to set dark mode to true' 2>/dev/null
    echo "🌚 [THEME] Switched to dark mode."
fi

# STEP 7 — Environment summary
if [ "$CHANGES_MADE" = true ]; then
    echo "✅ [ZSHRC] Environment variables updated."
fi
if [ "$ALIAS_ADDED" = true ]; then
    echo "✅ [ZSHRC] New aliases added."
fi

# STEP 8 — Run Node setup (if node.sh exists)
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
NODE_SCRIPT="$SCRIPT_DIR/node.sh"

if [ -f "$NODE_SCRIPT" ]; then
    echo "🟢 [NODE] Running node.sh ..."
    bash "$NODE_SCRIPT"
else
    echo "⚠️ [NODE] node.sh not found next to $(basename "$0")"
fi

# STEP 10 — Clean Dock
echo "🧼 [DOCK] Resetting Dock..."
defaults write com.apple.dock persistent-apps -array
killall Dock 2>/dev/null

# STEP 11 — Add essential apps
echo "📌 [DOCK] Adding essential apps..."
add_to_dock() {
    local app="$1"
    if [ -e "$app" ]; then
        defaults write com.apple.dock persistent-apps -array-add \
        "{\"tile-type\"=\"file-tile\";\"file-data\"={\"_CFURLString\"=\"$app\";\"_CFURLStringType\"=0;};}"
        echo "✅ [DOCK] Added: $(basename "$app")"
    else
        echo "⚠️ [DOCK] Not found: $app"
    fi
}
add_to_dock "/Applications/Visual Studio Code.app"
add_to_dock "/Applications/Google Chrome.app"
killall Dock 2>/dev/null

#Step 13 - Enable docker usage
rm -rf ~/Library/Containers/com.docker.docker
mkdir -p ~/goinfre/com.docker.docker
ln -s ~/goinfre/com.docker.docker ~/Library/Containers/com.docker.docker

# STEP 12 — Final summary
echo "\n🎉 [COMPLETE] Homebrew + Node.js setup finished!"