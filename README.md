![42banner](https://github.com/user-attachments/assets/27732cd3-5d14-4895-ad2f-a4b68fb2016c)

# 42_ft_printf

The goal of this project is pretty straightforward: recode (a simplified version of) [printf()](https://man7.org/linux/man-pages/man3/printf.3.html) from the Standard C library.

This exercise has been instrumental in learning to handle variadic functions (functions with a variable number of arguments).

Format specifiers handled by the project: cspdiuxX%

For detailed information, refer to [the subject of this project](https://github.com/frenzla/42_ft_printf/blob/main/ft_printf.pdf).

Part of my coding mastering journey 🥷


## 42

[42 is a world class computer programming school](https://42.fr/en/homepage/) that proposes a new way of learning computer science:
- No teachers
- No classrooms
- Open 24/7, 365 days/year
- Students are trained through peer-to-peer pedagogy, and project-based learning.
- Methodology that develops both tech & life skills.
- The 42 cursus is free for whoever is approved in its selection process.


## How to Install and Run the Project 

`make` from root. This will create a library file `ft_printf.a` that you can use in other projects


## How to Use

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/ft_printf.a -I path/to/ft_printf.h
```
