# Memory Leak Testing Guide

This guide explains how to compile and run the local sandbox test suite under `_noah_local` with memory leak and corruption detection enabled.

## Overview

The test suite uses **AddressSanitizer (ASan)**, a tool developed by Google that is built directly into Clang and GCC. It detects:
- Out-of-bounds accesses (buffer overflows)
- Use-after-free / double-free
- Memory leaks

---

## Running Leak Detection Tests

To build both the `libft` dependency and the test suite with AddressSanitizer instrumented, run the following command from the `_noah_local` directory:

```bash
make asan
```

This will:
1. Recompile `libft` with `-fsanitize=address -g`.
2. Compile the test runner (`noah_test`) with `-fsanitize=address -g`.

Once compiled, run the tests:

```bash
./noah_test
```

### Expected Behavior on Success

If there are no memory leaks or memory bugs, the test suite will complete normally:

```
╔══════════════════════════════════════════════════════╗
║           ALL PASSED ✓                               ║
╚══════════════════════════════════════════════════════╝
```

### Expected Behavior on Failure (Memory Leak Detected)

If a leak occurs, AddressSanitizer will intercept the exit of the program, print a detailed stack trace showing where the leaked memory was allocated, and exit with a non-zero exit status:

```
=================================================================
==12345==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 32 byte(s) in 1 object(s) allocated from:
    #0 0x7fff6... in malloc
    #1 0x10000... in new_node (new_node.c:12)
    ...
```

---

## Cleaning Up

To return `libft` and the workspace to a normal state without instrumentation, run:

```bash
# Clean sandbox tests
make fclean

# Rebuild libft normally
make -C ../libft re
```
