*This project has been created as part of the 42 curriculum by basayoub.*

# get_next_line

## Description

**get_next_line** is a C programming project from the 42 curriculum whose goal is to implement a function that reads and returns one line at a time from a file descriptor.

Reading line by line from a file descriptor using only low-level `read()` calls requires managing partial reads, arbitrary buffer sizes, and leftover data between function calls. This project introduces **static variables** in C, dynamic memory management, and file descriptor handling—including support for reading from regular files, standard input (`stdin`), and (in the bonus part) multiple file descriptors simultaneously without losing track of each descriptor's reading state.

### Features
- **Mandatory part:** Reads one line at a time from a single file descriptor, returning each line including its terminating `\n` (unless EOF is reached without a trailing newline).
- **Bonus part:** Manages multiple file descriptors concurrently using a single static variable (an array of pointers indexed by `fd`).
- Supports any positive `BUFFER_SIZE` defined at compile time via `-D BUFFER_SIZE=n`, with a default fallback defined in the header.

---

## Algorithm Explanation and Justification

The implementation uses a **persistent static stash (leftover buffer) paired with chunked `read()` calls**:

1. **Validation & Buffer Allocation:**
   - The function first checks that `fd` is valid (`fd >= 0`, and `fd < 2048` in the bonus) and that `BUFFER_SIZE > 0`.
   - A temporary read buffer of size `BUFFER_SIZE + 1` is allocated on the **heap** rather than the stack. This prevents stack overflow when compiled with very large `BUFFER_SIZE` values (e.g., `10000000`).

2. **Reading Loop (`looper`):**
   - While the static stash (`t2t`) does not contain a newline character (`\n`) and `read()` returns more than `0` bytes, the function reads up to `BUFFER_SIZE` bytes into the temporary buffer, null-terminates it, and appends it to the stash using `ft_stjoin`.
   - Stopping as soon as `\n` is found ensures the function reads as little as possible per call rather than loading the entire file into memory.

3. **Line Extraction (`iffer` & `get_line`):**
   - Once a newline is found or EOF is reached, the temporary read buffer is freed.
   - If the stash is empty, it is freed and `NULL` is returned.
   - If no newline is present (EOF reached with remaining characters), the entire stash is returned directly and the static pointer is reset to `NULL`.
   - Otherwise, `get_line()` copies everything up to and including the first `\n` into a newly allocated string.

4. **Preserving Leftover Data (`remeber_of_read`):**
   - Any characters after the first `\n` are copied into a new string stored in the static variable so the next call to `get_next_line()` resumes seamlessly from the exact next byte.

5. **Bonus Multi-FD Management:**
   - Instead of a single `static char *t2t`, the bonus version uses a single `static char *t2t[2048]`. Indexing directly by `fd` provides $O(1)$ lookup time for each file descriptor's reading state without needing a linked list or extra helper structures.

---

## Instructions

### Compilation

Compile the **mandatory** part with your own `main` (with or without `-D BUFFER_SIZE=n`):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Compile the **bonus** part (multiple file descriptors):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

> **Note:** If `-D BUFFER_SIZE` is omitted, `BUFFER_SIZE` defaults to `1` as defined in `get_next_line.h` / `get_next_line_bonus.h`.

---

## Resources

### References
- `man 2 read` — POSIX `read()` system call documentation.
- `man 3 malloc` / `man 3 free` — Dynamic memory allocation in C.
- [Static Variables in C (cppreference)](https://en.cppreference.com/w/c/language/storage_duration) — Storage duration and lifetime of `static` variables.
- [POSIX File Descriptors](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html) — Understanding file descriptors, `stdin`, and EOF behavior.

### AI Usage
- AI was used to review the completed C implementation for non-style bugs, edge cases (such as `malloc` failures and large `BUFFER_SIZE` behavior), and potential memory leaks.
- AI was also used to assist in structuring and drafting this `README.md` file in accordance with the 42 subject requirements.
