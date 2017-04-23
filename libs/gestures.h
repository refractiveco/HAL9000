/**
 *
 *  Continuous gesture and body language recognition library
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Gesture recognition class
class Gestures {
  public:
    Mat findGestures(Mat frame);
    Mat hmmRecognition(Mat frame);
    string occludedRecognition(Mat frame);
    string angledRecognition(Mat frame);
    Gestures();
};
