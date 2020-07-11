# cservice_template
Service for ...

**cservice_template** is the software designed for ... It is developed based on C++17 and provides easy-to-use API. With **cservice_template**, users can quickly connect to ..., receive ... data and transmit decision via ....

---

## Task

The task consists of several steps:

1. Physical connection of the sensor via RS 485 to USB converter.
2. Software connection to the port and capture lidar points.
3. Interpretation of data in the form of determining deviations from normalized values.
4. The issuance of the result of the occupation of the zone on the UDP at the localhost port 9000. (0 - no obstacles, 1 - are obstacles, 2 - wrong lidar connection).

---

## Dependencies

- GCC [5.x.x]
- CMake [3.2]
- GoogleTest
- LibUSB

---

## Installation

The installation procedures in Linux Ubuntu 16.04/14.04 32-bit LTS or Linux Mint 19.* 64-bit are shown here as examples.

Describing how to install all development dependencies and how to run an automated test-suite of some kind. Potentially do this for multiple platforms.

```sudo apt-get install gcc-5 g++-5 libusb-1.0  ```

---

For trace service messages change:<br/>
```
DEFINES -= TRACE
```
to
```
DEFINES += TRACE
```

---

## [Tests](./test/TEST.md)

Google Tests used for Unit-testing.<br />

For installation it is necessary to run:<br />

```
sudo apt install libgtest-dev
cd /usr/src/gtest/
sudo cmake -DBUILD_SHARED_LIBS=ON
sudo make
sudo cp *.so /usr/lib
```

---

### Submodules:

[LeddarTech SDK](https://github.com/dleliuhin/LeddarSDK) requires [CMake 3.0.0+](https://cmake.org/) as dependencies. You need to install cmake using apt:
```
sudo apt install cmake
```

### Compile Livox SDK

No need to compile library.

```
git clone ssh://git@bb.niias:7999/~d.leliuhin/door_detector.git
cd door_detector
git checkout develop
./scripts/update_submodules.sh
```
---

## Run


```
cd door_detector
git checkout master
./scripts/build.sh
./scripts/run.sh
```

Or using Qt Creator:

**Projects->Run->.*-c ../LivoxDriver/cfg/livox_driver.cfg -p /tmp/niias/door_detector

---

Optional:<br />

```--help``` - print arg help.<br />
```-p pid-name``` - pid name.<br />
```-c config-path``` - configuration file path.<br />
```--print-conf``` - print config & exit.<br />
```--save-conf``` - save config alongside the binary & exit.<br />

---

### Configuration file setup

    ---

## [Release History](dox/HISTORY.md)

---

## Contributing

1. Clone it (<ssh://git@bb.niias:7999/~d.leliuhin/cservice_template.git>)
2. Create your feature branch (`git checkout -b feature/name`)
3. Commit your changes (`git add . & git commit -m "Feature. Add some fooBar."`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request to `develop`

---

## Support

Reach out to me at one of the following places!

- Telegram at - <a href="http://https://telegram.org" target="_blank">`@DLeliuhin`</a>
- Email at - dleliuhin@gmail.com.

---

## [FAQ](doc/FAQ.md)

---
