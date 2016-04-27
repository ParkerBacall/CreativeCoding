#pragma once

#include "ofxAppUtils.h"
#include "ofxPostGlitch.h"
#include "ofxCellularAutomata.h"

class CAScene2 : public ofxScene{

	public:
    
        CAScene2() : ofxScene("cas2") {}
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
    ofFbo			myFbo;
    ofEasyCam		camera;
    
    ofTexture		texture;
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    
    
        CA2d ca2d;
};
