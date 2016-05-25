#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "ofxAppUtils.h"
#include "ofxGui.h"

class GlitchS1 : public ofxScene{

	public:
    
    GlitchS1() : ofxScene("GS1") {}
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxFloatSlider iGlitch;
    ofParameter<bool> bKeepGlitch;
    ofxPanel gui;
    
    bool bShowGui;
    
   	ofVideoGrabber myVideoGrabber;
    ofTexture glitchTexture;
    
    unsigned char* glitchVideoData;
    
    int camWidth, camHeight, maxPixel;
    
    //initialize Fbo
    ofFbo  myFbo;
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    ofTexture		texture;
    
    
};
