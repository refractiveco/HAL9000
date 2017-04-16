# NOTES

Development platform Arch Linux.

## Dependencies

- OpenCV 3

Run ./dependencies_setup.sh to install.

## Compile
```
g++ livecap.cpp ../libs/gestures.cpp -o livecap -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui -I ../libs -Wall -Wextra
```
