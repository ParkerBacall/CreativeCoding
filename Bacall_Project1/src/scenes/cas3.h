#pragma once

#include "ofxAppUtils.h"
#include "ofxPostGlitch.h"
#include "ofxCellularAutomata.h"

class CAScene3 : public ofxScene{
    
public:
    
    CAScene3() : ofxScene("cas3") {}
    
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

	
	CA3d ca3d;
	

	
};


