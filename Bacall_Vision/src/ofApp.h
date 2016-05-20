#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    
    //initialize Fbo
    ofFbo  myFbo;
    
    ofxCv::ContourFinder contourFinder;
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    ofTexture		texture;
    
    //initialize videoGrabber and camWidth/ Height
    ofVideoGrabber myVideoGrabber;
    int camWidth;
    int camHeight;
  
    int width;
    int height;

};
