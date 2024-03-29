//Parker Bacall
//EDP, University of Denver
//April 2016
//CC BY-SA


#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "ofxCellularAutomata.h"
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector<ofImage> image;

        // handles the scenes
        ofxSceneManager sceneManager;
        int lastScene;

    ofFbo			myFbo;
    ofEasyCam		camera;
    
    ofTexture		texture;
    
    /*Addon instance*/
    ofxPostGlitch	myGlitch;
    
    
    //float x, y;
    
    CA2d ca2d;
    
    bool debug;
};
