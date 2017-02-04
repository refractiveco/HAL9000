/**
 *
 *  Gesture recognition library
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include "gestures.h"
#include <iostream>

using namespace std;

Gestures::Gestures(void) {
   // Constructor
   cout << "Initialising gesture recognition library..." << endl;

}

string Gestures::findGestures(Mat frame) {
  // Try to find gestures or body language
  string gestureResult = cnnRecognition(frame);

  // Try CNN first
  if(gestureResult != "none") {
    return gestureResult;

  } else {
    // No match, try occlusion
    gestureResult = occludedRecognition(frame);

    if(gestureResult != "none") {
      return gestureResult;

    } else {
      // No match, finally try angled. Return either way.
      return angledRecognition(frame);

    }
  }
}

string Gestures::cnnRecognition(Mat frame) {
  // Process the frame(s) using a CNN for gesture recognition
  cout << "Processing frame using CNN..." << endl;

  string gestureResult = "none";

  /*
   * TODO: This is where the magic happens
   */

  return gestureResult;
}

string Gestures::occludedRecognition(Mat frame) {
  // Process the frame(s) for an occluded gesture
  cout << "Processing frame with occlusion algorithm..." << endl;

  string gestureResult = "none";

  /*
   * TODO: This is where the magic happens
   */

  return gestureResult;
}

string Gestures::angledRecognition(Mat frame) {
  // Process the frame(s) for an occluded gesture
  cout << "Processing frame with angled algorithm..." << endl;

  string gestureResult = "none";

  /*
   * TODO: This is where the magic happens
   */

  return gestureResult;
}
