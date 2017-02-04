/**
 *
 *  Video file capture
 *  @author rob.dunne@manchester.ac.uk
 *
 */

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    VideoCapture cap("./subject1_rgb/M_person_1_backgroud_1_illumination_1_pose_1_actionType_1.avi"); // open the video file for reading

    // if not success, exit program
    if (!cap.isOpened()) {
         cout << "Cannot open the video file" << endl;
         return -1;
    }

    double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

    cout << "Frame per seconds : " << fps << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while(1) {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        // if not success, break loop
        if (!bSuccess) {
          cout << "Cannot read the frame from video file" << endl;
          break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        // Gesture recognition
        string foundGesture = gesture.findGestures(cameraFrame);
        cout << ">>> Gesture found: "+foundGesture << endl;

        //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        if(waitKey(30) == 27) {
                cout << "esc key is pressed by user" << endl;
                break;
       }
    }

    return 0;

}
