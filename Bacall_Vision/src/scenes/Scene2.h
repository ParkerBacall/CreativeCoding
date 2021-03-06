#pragma once

#include "ofxPostGlitch.h"
#include "ofxAppUtils.h"
#include "ofMain.h"

class visionScene2 : public ofxScene{
    
    
public:
    
    visionScene2() : ofxScene("Scene2") {}
    
    
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
