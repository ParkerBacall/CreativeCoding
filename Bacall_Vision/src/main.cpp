//Parker Bacall
//EDP, University of Denver
//May 2016
//CC BY-SA


#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 640,480, OF_WINDOW);
    

    ofRunApp( new ofApp());
    
}
