NODE_VERSION="v22.21.1"
echo "🟢 [NODE] Installing Node.js $NODE_VERSION (manual, no root)..."
cd ~

if [ ! -d "$HOME/node" ]; then
    echo "⬇️  Downloading Node.js archive..."
    curl -L -O "https://nodejs.org/dist/$NODE_VERSION/node-$NODE_VERSION-darwin-x64.tar.xz"

    echo "📦 Extracting..."
    tar -xf "node-$NODE_VERSION-darwin-x64.tar.xz" || {
        echo "❌ [ERROR] Extraction failed. Possibly corrupted download."
        exit 1
    }

    mv "node-$NODE_VERSION-darwin-x64" node
    rm "node-$NODE_VERSION-darwin-x64.tar.xz"
    echo 'export PATH="$HOME/node/bin:$PATH"' >> ~/.zshrc
    source ~/.zshrc
    echo "✅ [NODE] Installed Node.js to ~/node"
else
    echo "📦 [NODE] Node.js already installed in ~/node"
fi
