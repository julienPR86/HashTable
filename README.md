# My simple hash table library

## Description

This is a simple hash table library that I use in my personal projects.

## Instructions

To make the library useable, you have to clone the needed submodules.

You can do it while cloning the project:

```bash
git clone ----recurse-submodules https://github.com/julienPR86/libhashtable.git
```

If you already cloned the project, you can run this command:

```bash
git submodule update --init
```

You cant then add the header in the necessary files, and add `#define LIBHASHTABLE_IMPLEMENTATION` in **only one** of them to get access to the function definitions.

It should look something like:

```c
#define LIBHASHTABLE_IMPLEMENTATION
#include "libhashtable.h"
```
