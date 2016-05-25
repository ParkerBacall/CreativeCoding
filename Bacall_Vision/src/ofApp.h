//Parker Bacall
//EDP, University of Denver
//April 2016
//CC BY-SA


#pragma once

#include "ofMain.h"
#include "ofxAppUtils.h"
#include "ofxGui.h"


class ofApp : public ofxApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
   
    
        // handles the scenes
        ofxSceneManager sceneManager;
        int lastScene;
    
           bool debug;
    
    
};
