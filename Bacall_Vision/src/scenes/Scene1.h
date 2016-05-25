#pragma once


#include "ofxPostGlitch.h"
#include "ofxAppUtils.h"
#include "ofMain.h"

class visionScene1 : public ofxScene{
    
public:
    
    visionScene1() : ofxScene("Scene1") {}
    
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    
    //initialize Fbo
    ofFbo  myFbo;
    
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    ofTexture		texture;
    
    //initialize videoGrabber and camWidth/ Height
    ofVideoGrabber myVideoGrabber;
    int camWidth;
    int camHeight;
  

};
