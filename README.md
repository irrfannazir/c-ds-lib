# Macro-Based Data Structure Libraries

A collection of C header files implementing common data structures using macros for generic programming. These headers provide type-safe, inline-able implementations without external dependencies.

## Features

- **Type-safe** generic programming using macros
- **Inline implementations** for optimal performance
- **No external dependencies** - pure C standard library
- **Self-contained headers** - just include and use

## Table of Contents

- [Installation](#installation)
- [Modules](#modules)
  - [Dynamic Type (dyn.h)](#dynamic-type-dynh)
  - [Linear Data Structures (linear.h)](#linear-data-structures-linearh)
  - [Linked List (list.h)](#linked-list-listh)
  - [File Handling (fh.h)](#file-handling-fhh)
  - [String Operations (sh.h)](#string-operations-shh)
- [Contributing](#contributing)
- [License](#license)

## Program

Simply copy the desired header files from the `include/` directory into your project:

```c
#include "include/dyn.h"
#include "include/linear.h"
#include "include/list.h"
#include "include/fh.h"
#include "include/sh.h"
