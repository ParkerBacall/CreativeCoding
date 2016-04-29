#include "cas3.h"

#include "ofApp.h"

//--------------------------------------------------------------
void CAScene3::setup(){

	// numcells match 2d width*height
	ca3d.setup(256,150,16);
	ca3d.countself = false;
	
    
	//ca3d.setRule(69147582);
    ca3d.setRule(1063069);
    
	ofSetBackgroundAuto(false);
	ofBackground(255);
	ofSetFrameRate(60);
    
    myFbo.allocate(ofGetWidth(), ofGetHeight());
    myGlitch.setup(&myFbo);
}

//--------------------------------------------------------------
void CAScene3::update(){
	myFbo.begin();
    
    // here see 16 z layers as 4x4 grid
    
    vector<int> * cells = ca3d.get();
    
    for(int j=0; j<ofGetHeight(); j++){
        for(int i=0; i<ofGetWidth(); i++){
            
            int val = (cells->at(j*ca3d.dim.x + i));
            if(val > 0)
                ofSetColor(255);
            else
                ofSetColor(0);
            
            ofDrawRectangle(i, j, 1, 1);
        }
    }

	ca3d.update();
    myFbo.end();
}


//--------------------------------------------------------------
void CAScene3::draw(){

    /* Apply effects */
    myGlitch.generateFx();
    myFbo.draw(0, 0);
    
    ofApp *app = (ofApp *)ofxGetAppPtr();
    if(app->debug) {
        ofSetColor(255);
        ofDrawBitmapStringHighlight("rule:"+ofToString(ca3d.getRule()), 10, 20);
    }
}

//--------------------------------------------------------------
void CAScene3::keyPressed  (int key){

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
    
	if (key == 'a') {
    ca3d.setRules(ofRandom(9999999));
    }
}

//--------------------------------------------------------------
void CAScene3::keyReleased(int key){

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

