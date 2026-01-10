#!/bin/bash

BIN=./RPN

RED="\033[31m"
GREEN="\033[32m"
CYAN="\033[36m"
RESET="\033[0m"

if [ ! -x "$BIN" ]; then
    echo -e "${RED}Error:${RESET} RPN binary not found or not executable"
    exit 1
fi

echo -e "${CYAN}========== CPP09 ex01 — RPN Evaluation Tests ==========${RESET}"

pass=0
fail=0

run_test() {
    expr="$1"
    expected="$2"

    output=$($BIN "$expr" 2>&1 | tr -d '\n')

    if [ "$output" = "$expected" ]; then
        echo -e "${GREEN}[OK]${RESET} \"$expr\" → $output"
        pass=$((pass+1))
    else
        echo -e "${RED}[KO]${RESET} \"$expr\""
        echo -e "     expected: $expected"
        echo -e "     got     : $output"
        fail=$((fail+1))
    fi
}

echo -e "\n${CYAN}--- Valid expressions ---${RESET}"
run_test "3 4 +" "7"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "-3 5 +" "2"
run_test "7 2 /" "3"

echo -e "\n${CYAN}--- Error handling ---${RESET}"
run_test "1 2 3 +" "Error: too many operands."
run_test "+ +" "Error: not enough operands."
run_test "4 0 /" "Error: division by zero."
run_test "1 a +" "Error"
run_test "1.5 2 +" "Error"
run_test "(1 2 +)" "Error"

echo -e "\n${CYAN}--- Spacing & formatting ---${RESET}"
run_test "   3   4    +   " "7"
run_test "3 4 +" "7"
run_test $'3 4 +\n' "7"

echo -e "\n${CYAN}--- Argument handling ---${RESET}"
output=$($BIN 2>&1 | tr -d '\n')
if [[ "$output" == Error* ]]; then
    echo -e "${GREEN}[OK]${RESET} no argument → $output"
    pass=$((pass+1))
else
    echo -e "${RED}[KO]${RESET} no argument"
    echo -e "     got: $output"
    fail=$((fail+1))
fi

echo -e "\n${CYAN}========== SUMMARY ==========${RESET}"
echo -e "${GREEN}Passed:${RESET} $pass"
echo -e "${RED}Failed:${RESET} $fail"

if [ $fail -eq 0 ]; then
    echo -e "${GREEN}✔ Passed"
else
    echo -e "${RED}✘ Failed"
fi
