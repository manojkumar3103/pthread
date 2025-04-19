# POSIX Threads (pthreads) Examples

This repository contains a collection of simple and educational examples demonstrating the use of **POSIX Threads (pthreads)** in **C**.  
These examples cover fundamental concepts such as:

- ✅ Thread creation using `pthread_create()`
- 🔄 Thread synchronization using `pthread_mutex_t`
- 📦 Shared data handling across threads
- 🛑 Avoiding race conditions

## 📁 Repository Contents

Creating and joining threads
Synchronizing with mutex
Demonstrating race conditions and how to avoid them

## 🛠 How to Compile and Run

### Requirements

- GCC or any standard C compiler
- POSIX-compliant system (Linux, Unix, macOS)

### Compile

```bash
gcc -pthread filename.c -o output
