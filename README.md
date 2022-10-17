## printf

Simple project to recreate the printf function in C. 

### Authorised functions and macros
- write (man 2 write)
- malloc (man 3 malloc)
- free (man 3 free)
- va_start (man 3 va_start)
- va_end (man 3 va_end)
- va_copy (man 3 va_copy)
- va_arg (man 3 va_arg)

### General Requirements
- Allowed editors: vi, vim, emacs
- All files should end with a new line
- The code should use the Betty style
- Global variables are not allowed
- No more than 5 functions per file

### Header file
The prototypes of all functions are included in header file main.h, which has been include guarded.

### Compilation
The codes are compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

### Testing
The c file with the main function is in the directory `test`
While testing, compile the `_printf` with the extra gcc flag `-Wno-format`: 
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```
