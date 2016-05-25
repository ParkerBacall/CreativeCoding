//Parker Bacall
//EDP, University of Denver
//April 2016
//CC BY-SA

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		void mousePressed(int x, int y, int button);
		
		
    float x, y , xpos, ypos;
    float degrees;
   bool isMoving;
    bool isRotating;
    
    
};
