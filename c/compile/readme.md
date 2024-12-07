## Compile in C

Compiling in C can be 4 steps.

1. Preprocessing
2. Compilation
3. Assembly
4. Linking 

### Preprocessing

Preprocessor insert contents of header file into `.c` file.
It transform preprocessor directives into headers declares in `.h` files.
directives can be : 
```
#define, #error, #include ...
```

- Example:
```c
#include "a.h" /* this transformed into declares. */
```
```c
void function_declares_in_a_header_file(void);
```

### Compilation

The compilation step takes the preprocessed code and translates into **assembly code**.
This process involves syntax check.
The important thing in this step is that this step doesn't need **definition** of any function.

### Assembly

### Linking

## Include guard

The include guard defend circular import of headers.

```c
#ifndef FOO_H
#define FOO_H

#endif /* FOO_H */
```
This code can be interpreted as:
`If FOO_H constant doesn't be defined, define it as constant which is between include guard.`