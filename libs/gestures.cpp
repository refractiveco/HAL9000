/**
 *
 *  Continuous gesture and body language recognition library
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
  // Find gestures or body language from the stream of video frames
  string gestureResult = hmmRecognition(frame);

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

string Gestures::hmmRecognition(Mat frame) {
  // Process the frame(s) using a HMM for continuous gesture recognition
  cout << "Processing frame using HMM..." << endl;

  string gestureResult = "none";

  // Feature extraction: Greyscale, threshold, background subtraction (separate method?).
  Mat processedFrame =

  // Classify the gesture with Haar (previously trained classifiers - XML files for each gesture).

  // Check against HMM sequence classification.

  // If not found add the gesture to the current HMM sequence.

  // End sequence if gesture classified. (Needs a time out)

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
