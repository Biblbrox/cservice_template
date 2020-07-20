# cservice_template

[[Build status](http://bamboo.niias/browse/TOOL-CSERVICEBUILD/latest)]
[[Tests status](http://bamboo.niias/browse/TOOL-CSERVICEBUILD/test)]
[[License](./doc/LICENSE.md)]


Service for ...

**cservice_template** is the software designed for ... It is developed based on C++17 and provides easy-to-use API. With **cservice_template**, users can quickly connect to ..., receive ... data and transmit decision via ....

---

## Overview

A service is a template for proper use by developers within a company. The number of services is constantly growing, however, their base remains unchanged. In the current repository, the author has tried to simplify many routine tasks when creating a new repository, including: automatic code documentation, static analysis, code coverage with Unit-tests, the use of generally accepted company submodules to interact with other services in the system.

---

## Dependencies

Basic:<br>

- [build-essential](https://packages.debian.org/ru/sid/build-essential)
- [C++17 (GCC-8, G++-8)](https://en.cppreference.com/w/cpp/17)
- [CMake (> 3.10)](https://cmake.org)
- [Make (> 4.2)](https://en.wikipedia.org/wiki/Make_(software))
- [LCov (> 1.14)](http://ltp.sourceforge.net/coverage/lcov.php)
- [CLang-Tidy (> 10.0)](https://clang.llvm.org/extra/clang-tidy/)
- [CLang-Format (> 10.0)](https://clang.llvm.org/docs/ClangFormat.html)
- [Ninja (> 1.10)](https://ninja-build.org)

Third-party (for visualization):<br>

- [Doxygen (> 1.8)](https://www.doxygen.nl/index.html)
- [Graphviz](https://graphviz.org)
- [Latex](https://www.latex-project.org/get/)
- [Tree](https://pingvinus.ru/note/tree)
- [PCL (> 1.10)](https://pointclouds.org)

---

## Installation

The installation procedures in Linux Ubuntu 16.04/14.04 32-bit LTS or Linux Mint 19.* /20. * 64-bit are shown here as examples.

Describing how to install all development dependencies and how to run an automated test-suite of some kind. Potentially do this for multiple platforms.

For embedded :<br/>
```./scripts.install.sh```

```./scripts.install-third-party.sh```

---

## Run

Make changes according to task in [configuration file](./cfg).

Without visualization:

```
cd cservice_template
git checkout release
```
Without visualization: ```./scripts/build.sh``` <br>
With visualization: ```./scripts/build-gui.sh```

```
./scripts/run.sh
```

Or using [Qt Creator IDE](https://www.qt.io/download):


Without visualization: **Projects->Run->.*-c ../cservice_template/cfg/cservice_template.cfg -p /tmp/niias/cservice_template<br>

With visualization: <br>
- *Projects->Build->CMake->GUI->ON->Apply Configuration Changes* <br>
- *Projects->Run->* ```-c ../cservice_template/cfg/cservice_template.cfg -p /tmp/niias/cservice_template``` <br>

You can find more scripts in [scripts/](./scripts).

---

## [Tests](./tests/README.md)

---

## [Release History](./doc/HISTORY.md)

---

## Contributing

1. Fork it (<ssh://git@bb.niias:7999/tool/cservice_template.git>).
2. Read [Readme](./README.md), [License](./doc/LICENSE.md), [Code of Conduct](./doc/CODE_OF_CONDUCT.md) and [Condributing Guidelines](./doc/CONTRIBUTING.md).
3. Create your fix or feature branch (`git checkout -b feature/name`).
4. Make changes according to [Condributing Guidelines](./doc/CONTRIBUTING.md).
5. Make unit tests.
6. Build repo and tests.
7. Correct Readmes for whole directories.
8. Ensure that it is likely to be merged.
9. Commit your changes (```git add . & git commit -m "Feature. Add wrapper class WrapperClass."```).
10. Push to the branch (```git push origin feature/new-wrapper-class```)
11. Create a new Pull Request to `develop`

---

## Support

Reach out to me at one of the following places!

- Telegram at - <a href="http://https://telegram.org" target="_blank">`@DLeliuhin`</a>
- Email at - dleliuhin@gmail.com.

---

## [License](./doc/LICENSE.md)

---

## [FAQ](doc/FAQ.md)

---

**JSC NIIAS**