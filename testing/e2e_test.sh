#!/bin/bash

# End-to-end test runner for push_swap using checker_Mac
# Tests correctness (checker OK/KO) and operation counts

set -e

PUSH_SWAP_DIR="/Users/noah/Code/PUSH_SWAP/PUSH_SWAP04"
CHECKER="/Users/noah/Code/PUSH_SWAP/checker_Mac"
PUSH_SWAP="$PUSH_SWAP_DIR/push_swap"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test counters
PASSED=0
FAILED=0

# Run a single test case
# Args: test_name, args, expected_result, max_ops (optional)
run_test() {
    local test_name="$1"
    local args="$2"
    local expected="$3"
    local max_ops="${4:-}"
    
    local result
    local ops_count
    local stderr_output
    
    # Capture stderr separately to detect Error messages
    stderr_output=$(mktemp)
    result=$("$PUSH_SWAP" $args 2>"$stderr_output" | "$CHECKER" $args 2>/dev/null || true)
    ops_count=$("$PUSH_SWAP" $args 2>/dev/null | wc -l | tr -d ' ')
    
    # Check if program printed Error to stderr (indicates input validation failure)
    if grep -q "Error" "$stderr_output" 2>/dev/null; then
        result="Error"
    fi
    rm -f "$stderr_output"
    
    if [ "$result" = "$expected" ]; then
        if [ -n "$max_ops" ] && [ "$ops_count" -gt "$max_ops" ]; then
            echo -e "${RED}FAIL${NC} $test_name: OK but $ops_count ops > max $max_ops"
            FAILED=$((FAILED + 1))
        else
            local ops_info=""
            [ -n "$max_ops" ] && ops_info=" ($ops_count ops, max $max_ops)"
            echo -e "${GREEN}PASS${NC} $test_name$ops_info"
            PASSED=$((PASSED + 1))
        fi
    else
        echo -e "${RED}FAIL${NC} $test_name: expected $expected, got $result ($ops_count ops)"
        FAILED=$((FAILED + 1))
    fi
}

# Generate random numbers without duplicates
generate_random_args() {
    local count="$1"
    local range="$2"
    
    # Use shuf if available, otherwise fallback to python
    if command -v shuf >/dev/null 2>&1; then
        shuf -i "-$range-$range" -n "$count" | tr '\n' ' '
    elif command -v python3 >/dev/null 2>&1; then
        python3 -c "
import random
nums = random.sample(range(-$range, $range + 1), $count)
print(' '.join(map(str, nums)))
"
    else
        echo "Error: need shuf or python3 for random tests" >&2
        exit 1
    fi
}

# Run random test with operation count
run_random_test() {
    local count="$1"
    local max_ops="$2"
    local iterations="${3:-1}"
    
    for i in $(seq 1 "$iterations"); do
        local args
        args=$(generate_random_args "$count" 1000000)
        
        local result
        local ops_count
        local stderr_output
        
        stderr_output=$(mktemp)
        result=$("$PUSH_SWAP" $args 2>"$stderr_output" | "$CHECKER" $args 2>/dev/null || true)
        ops_count=$("$PUSH_SWAP" $args 2>/dev/null | wc -l | tr -d ' ')
        
        if grep -q "Error" "$stderr_output" 2>/dev/null; then
            result="Error"
        fi
        rm -f "$stderr_output"
        
        if [ "$result" = "OK" ]; then
            if [ "$ops_count" -le "$max_ops" ]; then
                echo -e "${GREEN}PASS${NC} random_$count[$i]: $ops_count ops <= $max_ops"
                PASSED=$((PASSED + 1))
            else
                echo -e "${RED}FAIL${NC} random_$count[$i]: $ops_count ops > $max_ops (still sorted OK)"
                FAILED=$((FAILED + 1))
            fi
        else
            echo -e "${RED}FAIL${NC} random_$count[$i]: $result ($ops_count ops)"
            FAILED=$((FAILED + 1))
        fi
    done
}

echo "=== push_swap End-to-End Tests ==="
echo ""

# Check binary exists
if [ ! -f "$PUSH_SWAP" ]; then
    echo "Error: push_swap not found at $PUSH_SWAP"
    echo "Run 'make' in $PUSH_SWAP_DIR first"
    exit 1
fi

if [ ! -f "$CHECKER" ]; then
    echo "Error: checker_Mac not found at $CHECKER"
    exit 1
fi

echo "--- Edge Cases ---"
run_test "empty" "" "Error"
run_test "single" "42" "OK"
run_test "two_sorted" "1 2" "OK" 1
run_test "two_rev" "2 1" "OK" 1
run_test "three_sorted" "1 2 3" "OK" 0
run_test "three_rev" "3 2 1" "OK" 3
run_test "dup" "1 2 2" "Error"
run_test "non_num" "1 two 3" "Error"
run_test "overflow" "2147483648" "Error"

echo ""
echo "--- Small Sets ---"
run_test "five_sorted" "1 2 3 4 5" "OK" 0
run_test "five_rev" "5 4 3 2 1" "OK" 12
run_test "five_random" "2 5 1 4 3" "OK" 12

echo ""
echo "--- Operation Count Limits (42 subject) ---"
run_random_test 3 3 5
run_random_test 5 12 10
run_random_test 100 700 20
run_random_test 500 5500 10

echo ""
echo "=== Results ==="
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

if [ "$FAILED" -gt 0 ]; then
    exit 1
fi
