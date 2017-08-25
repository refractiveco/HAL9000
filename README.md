# HAL9000

### Status
[![Build Status](https://travis-ci.org/refractiveco/HAL9000.svg?branch=master)](https://travis-ci.org/refractiveco/HAL9000)

Development OS is Arch Linux. Language is C++.

### Dependencies

- OpenCV 3

Run ./dependencies_setup.sh to install on a new system.

### Libraries / Roadmap

- Gesture and body language recognition (in dev).
- Voice commands (not started).
- Passive behaviour recognition (not started).
- System self-extension (not started).
- Device (not started).

### Build

Build using the makefile.

```make```

### Manual compile

```g++ livecap.cpp ../libs/gestures.cpp -o livecap -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui -I ../libs -Wall -Wextra```

### Run

```cd ./build```

```./livecap```

### Licence

This project is open source to help build the adoption and community for ambient intelligence. As such all derivatives, improvements, and modifications should be released back to the community so we can keep building. No liability or warranty for use of this software. Full licence: [GNU Lesser General Public License v3.0](LICENSE)
