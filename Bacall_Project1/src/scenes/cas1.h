#pragma once

#include "ofxAppUtils.h"
#include "ofxCellularAutomata.h"
#include "ofxPostGlitch.h"


class CAScene1 : public ofxScene{

	public:
   
    CAScene1() : ofxScene("cas1") {}
    
		void setup();
		void update();
		void draw();
    
        void updateEnter();

		void keyPressed(int key);
		void keyReleased(int key);
		
    int y;
    ofFbo			myFbo;
    ofEasyCam		camera;
    
    ofTexture		texture;
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    
  

    CA1d ca1d;
    
};
