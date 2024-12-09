![] (https://zupimages.net/up/24/50/q16f.png)


Requirements 🚀
General

> - Allowed editors: vi, vim, emacs
> - All your files will be interpreted/compiled on Ubuntu 14.04 LTS
> - Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
> - All your files should end with a new line
> - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
> - You are not allowed to use global variables
> - No more than 5 functions per file
> - In the following examples, the main.c files are shown as examples.
You can use them to test your functions, but you don�t have to push them to your repo (if you do we wont > - take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called sort.h
> - Don't forget to push your header file
> - All your header files should be include guarded

## Task 👩‍💻
### 0. Simple RegEx

Mandatory
Score: 100.00% (Checks completed: 100.00%)

Write a function that checks whether a given pattern matches a given string.
Function Prototype:

int regex_match(char const *str, char const *pattern);

### Parameters:

    str: The string to scan.
    pattern: The regular expression.

Return Value:

    Returns 1 if the pattern matches the string, or 0 otherwise.

Rules:

    str can be empty and can contain any ASCII character except . and *.
    pattern can be empty and can contain any ASCII character, including . and *.
    The regular expression matching must support the following:
        . matches any single character.
        * matches zero or more of the preceding character.

Example Usage

``` sh
main.c

#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

#define TEST_MATCH(s, p) do { \
    { \
        int res = regex_match(s, p); \
        printf("%s -> %s = %d\n", s, p, res); \
    } \
} while (0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");

    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");

    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");

    TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

    return (EXIT_SUCCESS);
}
```
Compilation and Execution:
``` sh
gcc -Wall -Wextra -Werror -pedantic main.c regex.c -o regex
./regex
```
Expected Output:
``` sh
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
```

✏ ## Author  :   **Sabrina PAPEAU** - [Github](https://github.com/Holbiwan)