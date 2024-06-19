# signals_cpp

[![License](https://img.shields.io/github/license/spjuanjoc/signals_cpp)](https://img.shields.io/github/license/spjuanjoc/signals_cpp)

Example of signals and slots in C++.

| Library       | Package       | Version | Docs                                                                     |
|:--------------|:--------------|:-------:|:-------------------------------------------------------------------------|
| libsigc++     | sigc++-3      |  3.0.7  | [libsigcplusplus](https://libsigcplusplus.github.io/libsigcplusplus/)    |
| Boost         | Signals2      | 1.84.0  | [Signals2](https://www.boost.org/doc/libs/1_84_0/doc/html/signals2.html) |
| signals-light | signals-light |   cci   | [signals-light](https://github.com/a-n-t-h-o-n-y/signals-light)          |

## Signals and slots

A signal is an object that may inform to others when something in its state
changes. It may be trackable, which means that objects may listen to a signal to
be emitted. It is observable. It may publish information. It may emit.

A slot is an object that may connect to a signal, to listen to it. It is a
tracer, an observer for a signal. It may subscribe for information.

They are used for asynchronous io.

## Not system signals

This example does not refer to the system signals std::signal, such as
SIGTERM, SIGSEGV, and so on.
