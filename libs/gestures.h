/**
 *
 *  Gesture recognition library
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Gesture recognition class
class Gestures {
  public:
    string findGestures(Mat frame);
    string cnnRecognition(Mat frame);
    string occludedRecognition(Mat frame);
    string angledRecognition(Mat frame);
    Gestures();
};
