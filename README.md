# stdwrap: a set of wrapper libraries conforming to the STL naming scheme
wraps some commonly used c library so that people could use them in a
more c++ way (RAII, templates, type-traits, type-safety etc.).

## about the project
this project might be a big wheel (as in "don't reinvent wheels"), but,
c++ is such a strange language that, most of its users don't conform their
coding style and naming scheme to the standard library (in this case,
the STL), while users of almost all the other programming languages do.
this project is here to correct that error.

all the wrappers from this project will conform heavily to the STL coding
style and naming scheme, using templates most of the time with type-traits.

## some conformance on c++
c++ is never, and will never be, an OOP language. c++ is always a
multi-paradigm language, whose users can choose to use any technique of
functional programming, object-oriented programming, meta programming
and/or general programming etc when it's the most suitable, simple and
elegant solution to the problem. design patterns exists only because
the useless restrictions to do some task using a certain programming
language and/or a certain programming technique. we will avoid design
patterns as possible as we can. because of the nature of c++, we can
usually find a better solution using another programming technique
rather than falling back to design patterns. on the other hand, we may
use common c++ idioms when appropriate.

### memory management in c++
in c++, memory management is all about ownership.

