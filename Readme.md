# CTwist Compiler and runtime library

## Contents

0. License
1. Introduction
2. Basic infrastructure
3. ...

## 0. License

All files related to the CTwist compiler and runtime library are essentially
placed in public domain under the "CC0 Public Domain Dedication", unless
otherwise stated. You should have received a copy of the CC0 Public Domain
Dedication along with this software. If not, see
http://creativecommons.org/publicdomain/zero/1.0/

## 1. Introduction

CTwist (aka Twisted C) is a language inspired by C++, but improving on
everything associated with the development process, from the language's syntax,
library, build process, etc. The build tools are heavily based on LLVM, which
provides the necessary infrastructure to immediately generate optimized native
code for a large number of platforms without much hassle. It is an intermediate
layer that is well-documented, stable, and widely applied.

Twisted C is meant to be a natively compiled language, but can use LLVM's JIT
techniques to run semi-compiled, which improves the developer's experience and
allows less time to be spent linking, and more time spent debugging the actual
problem.

Concretely, Twisted C features:

 - Strong, static typing
 - An extensive and wide-featured library
 - Function overloading
 - Strong typedefs
 - User-defined operators?
 - Classes
 - Generics (think C++ templates)
 - Low-level memory access
 - No preprocessor
 - Fully integrated Unicode support in language and runtime
 - Type inference?
 - Exceptions
 - Flexible documentation system to replace readable header files?
 
Twisted C's specification is freely available and distributed alongside the
compiler and runtime library.

# Basic infrastructure

Twisted C throws overboard the old compilation model introduced in C and kept
in C++ and similar languages. Leveraging the power of LLVM, and CTwist's
independence from C, a new compilation model is applied, based on hybrid
"Twisted Object .to" files, which contain a symbol table, LLVM bytecode, and
a compiler representation of code traditionally kept in a C/C++ "header".

A user's redistributable library will thus consist of one Twisted Object file,
which is transparently "import"ed into a project. The code contained in such a
library is platform independent, and can be used on any platform supported by
CTwist.

Such a library, or more generally object file (there is no difference between
the two), can be linked in statically, or dynamically. Static linking works
as usual, dynamic linking works in two distinct and very different ways:

 - Soft linking: the application uses the LLVM JIT to execute the library's
                 code. Linking is fast, execution is expected to be slower.
 - Hard linking: the library's bytecode and generics are compiled into native
                 machine code, and placed in a regular so or dll file, meant
                 to be redistributed with the application or OS.

Soft linking provides a means to quickly test an application without extensive
linking times, while execution speed suffers (which shouldn't matter too much
when debugging). Hard linking is more useful when releasing a final application
to the more general public.
