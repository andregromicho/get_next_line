*This project has been created as part of the 42 curriculum by abrandao.*

# get_next_line

## Description
The **get_next_line** project is a fundamental milestone in the 42 curriculum. Its primary objective is to implement a custom C function that reads a line from a file descriptor (`fd`), ending with a newline character (`\n`) or End-Of-File (EOF). Subsequent calls to `get_next_line` allow for reading the entire text content sequentially, one line at a time.

This project introduces and reinforces critical programming concepts:
* **Static Variables:** Learning how to persist state and data between discrete function calls in C.
* **Dynamic Memory Management:** Precise allocation and freeing of memory using `malloc` and `free` to prevent memory leaks and dangling pointers.
* **File I/O Operations:** Working with system calls (`read`) and understanding how data is buffered from streams.

### Returns:
- A line ending with '\n' when available
- The last line at EOF even without '\n'
- NULL on EOF or error

---

### Technical Approach & Algorithm Justification

#### 1. The Challenge
The core problem is reading data from a file descriptor (`fd`) using a fixed-size buffer (`BUFFER_SIZE`). Since newline characters (`\n`) rarely align with the buffer boundaries, the function must preserve any "surplus" text for the subsequent calls.

#### 2. Selected Strategy
The implementation uses a **static string buffer** (`static char *stored`). This approach avoids the memory and pointer overhead of complex data structures like linked lists, relying instead on clean, linear heap memory allocations.

#### 3. Algorithm Pipeline
* **Validation:** Checks for invalid parameters and runs a defensive `read(fd, 0, 0) < 0` check. If it fails, all static memory is safely freed to prevent leaks.

* **Accumulation (`read_and_store`):** Loops and reads from the `fd`, appending chunks to the static string using `ft_strjoin` until a `\n` or End-Of-File (EOF) is reached.

* **Extraction (`ft_strdup_len`):** Computes the exact length up to the first `\n` and isolates this single line into a newly allocated string to be returned.

* **Clean-up (`update_stored`):** Truncates the static buffer, keeping only the remaining bytes found *after* the extracted newline, while freeing the obsolete memory.

## Instructions

### Compilation
The project must be compiled with the `-D BUFFER_SIZE=n` flag to define the read buffer size. 

To compile the source files alongside your own `main.c`, run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## Execution Example
### Integrate get_next_line into your test suite as follows:
```bash
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Resources & AI Usage

### Essential References & Manuals
* Library functions manuals
* Francinette tester.
* AI was used exclusively as a technical assistant to structure this README.md and clarify some fundamental concepts.