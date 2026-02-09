alias desk='cd ~/Desktop'
alias des='cd ~/Desktop'
alias doc='cd ~/.Documents'
alias dow='cd ~/.Downloads'
alias down="cd ~/.Download"
alias cclean="~/Cleaner_42.sh"
alias dock="~/Desktop/val-container/install"
alias c="clear"
alias cls="clear"
alias grademe='bash -c "$(curl https://grademe.fr)"'
alias dock-run="~/Desktop/val-container/run"
export PATH="$HOME/node/bin:$PATH"
export PATH="$HOME/bin:$PATH"
export HOMEBREW_PREFIX="/goinfre/mhashir/homebrew"
export HOMEBREW_CELLAR="$HOMEBREW_PREFIX/Cellar"
export HOMEBREW_REPOSITORY="$HOMEBREW_PREFIX"
alias brewi='brew install'
alias brewl='brew list'
alias brewu='brew update && brew upgrade'
cppwatch() { ls "$1" | entr sh -c "clear; echo \"[1;31m== 🔥 Hot Reloading $1 🔥 ==[0m\"; g++ \"$1\" && ./a.out"; }

source /Users/mhashir/.docker/init-zsh.sh || true # Added by Docker Desktop
PATH=$PATH:/Users/mhashir/Desktop/val-container
PATH=$PATH:/Users/mhashir/Desktop/val-container
alias find_chpp='find . \( -name "*.hpp" -o -name "*.cpp" \) -exec sh -c "echo "====={}=====";cat "{}";" \;'
alias entr_chpp='ls *.cpp *.hpp | entr -c sh -c "**/*.cpp **/*.hpp && ./a.out"'

