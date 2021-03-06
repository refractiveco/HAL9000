/**
 *
 *  Live video capture
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

// Include framework libraries
#include <gestures.h>

using namespace cv;
using namespace std;

int main() {
  // Gestures object
  Gestures gesture;

  // 0 is the id of video device. 0 if you have only one camera.
  VideoCapture stream1(0);

  // Check the video stream is open
  if(!stream1.isOpened()) {
    cout << "Error: Cannot open the camera.";
  }

  // Loop over the frames
  while(true) {
    Mat cameraFrame;
    Mat processedFrame;
    stream1.read(cameraFrame);
    //imshow("cam", cameraFrame);

    //string foundGesture = gesture.findGestures(cameraFrame);
    //cout << ">>> Gesture found: "+foundGesture << endl;

    processedFrame = gesture.findGestures(cameraFrame);

    // Save a screenshot on spacebar press
    if(waitKey(30) == 32) {
        imwrite("../screenshots/HAL9000.jpg", processedFrame);
    }

    imshow("camera", processedFrame);

    waitKey(30);
  }

  return 0;
}
