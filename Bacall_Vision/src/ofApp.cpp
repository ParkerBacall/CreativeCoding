#include "ofApp.h"

using namespace ofxCv;
using namespace cv;
//--------------------------------------------------------------
void ofApp::setup(){
    
    width= 640;
    height= 480;
    
    //setup Frame Rate and Verticle Snyc
    ofSetVerticalSync(TRUE);
    ofSetFrameRate(60);
    
    //allocate Fbo to fit screen
    myFbo.allocate(width, height);
    
    //setup glitch textures in Fbo
    myGlitch.setup(&myFbo);
    
    // Set capture dimensions
    camWidth = width;
    camHeight = height;
    
    // Open an ofVideoGrabber for the camera
   myVideoGrabber.initGrabber (camWidth,camHeight);
    
    
  
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //begin Fbo
    myFbo.begin();
    
        //begin Pushview
        ofPushView();
   
            //update and draw the videoGrabber in Fbo
            myVideoGrabber.update();
            myVideoGrabber.draw(0,0);
            //contourFinder.findContours(myVideoGrabber);
    
        //end the pushView
        ofPopView();
        
    //end the Fbo
    myFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    myFbo.draw(0, 0);
    
    //contourFinder.draw();
   
    
   }
    

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
    
    if (key == 's') {
        
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
}

