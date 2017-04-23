# HAL9000

Development OS is Arch Linux.

## Dependencies

- OpenCV 3

Run ./dependencies_setup.sh to install on a new system.

### Libraries

- Continous gesture and body language recognition (in dev).
- Passive behaviour recognition (not started).
- System self-extension (not started).

### Build

```make```

## Manual compile

```g++ livecap.cpp ../libs/gestures.cpp -o livecap -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui -I ../libs -Wall -Wextra```

### Run

```cd ./build```

```./livecap```
