/**
 *
 *  Continuous gesture and body language recognition library
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include "gestures.h"

using namespace std;

Gestures::Gestures(void) {
   // Constructor
   cout << "Initialising gesture recognition library..." << endl;

}

Mat Gestures::findGestures(Mat frame) {
  // Find gestures or body language from the stream of video frames
  Mat gestureResult = hmmRecognition(frame);
  return gestureResult;
  /*
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
  */
}

Mat Gestures::hmmRecognition(Mat frame) {
  // Process the frame(s) using a HMM for continuous gesture recognition
  cout << "Processing frame using HMM..." << endl;
  rectangle(frame, Point(0, 0), Point(240, 35), Scalar(0, 0, 0), CV_FILLED);

  string gestureResult = "none";
  vector<double> weights;
  vector<int> levels;

  // Var for list of rectangles when gesture detected
  vector<Rect> hands;

  // Feature extraction: Greyscale, threshold, background subtraction (separate method?).
  Mat frame_gray;
  cvtColor(frame, frame_gray, CV_BGR2GRAY);
  equalizeHist(frame_gray, frame_gray);

  // Load the classifiers
  String hand_cascade_file = "../haars/hand.xml";
  CascadeClassifier hand_cascade;

  if(!hand_cascade.load(hand_cascade_file)) {
    cout << "------(!)Error loading cascade file\n";
  };

  // Classify the gesture with Haar (previously trained classifiers - XML files for each gesture).
  hand_cascade.detectMultiScale(frame_gray, hands, levels, weights, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(100, 100), Size(), true);

  // Draw a circle around the gesture
  for(size_t i = 0; i < hands.size(); i++) {
    Point center(hands[i].x + hands[i].width*0.5, hands[i].y + hands[i].height*0.5 );
    ellipse(frame, center, Size(hands[i].width*0.5, hands[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0);
  }

  // Found a gesture
  if(hands.size() > 0) {
    gestureResult = "fist";
    String frameText = gestureResult+":"+to_string(weights[0]);
    cout << "Found a "+gestureResult+"..." << endl;

    putText(frame, frameText, Point(10,15), FONT_HERSHEY_COMPLEX_SMALL, 1.0, Scalar(255, 255, 255), 1, CV_AA);
  }

  // Check against HMM sequence classification.

  // If not found add the gesture to the current HMM sequence.

  // End sequence if gesture classified. Execute an action based on the gesture.

  return frame;
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
