#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);

    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    camera.setDistance(400);
    ofSetCircleResolution(10);
    
    boog.load("boog.png");
    bDrawBoog = false;
    bShowHelp  = false;
    bShowGui = false;
    myFbo.allocate(512, 512);
    
    myGlitch.setup(&myFbo);
    
    gui.setup();
    gui.add(angle.setup("angle", 2, 1, 10));
    //gui.add(bDrawBoog.setup45("2D / 3D",false,false,true));
}

//--------------------------------------------------------------
void ofApp::update(){
    myFbo.begin();
    ofClear(0, 0, 0,255);
    
    if (!bDrawBoog){
        camera.begin();
        
        degrees= degrees - angle;
        
        ofSetLineWidth(2);
        
        ofTranslate(20, 50);
        
        
        
        ofRotate(degrees);
        
        
        
        ofFill();
        ofSetColor(255);
        ofDrawCircle(-32.5,30,6.5);
        ofDrawCircle(17.5,30,6.5);
        
        ofNoFill();
        ofSetColor(0);
        ofDrawCircle(-32.5,30,6.5);
        ofDrawCircle(17.5,30,6.5);
        
        
        ofFill();
        ofSetColor(255, 150, 181);
        ofDrawEllipse(-8 ,20 ,93, 20);
        
        ofNoFill();
        ofSetColor(0);
        ofDrawEllipse(-8 ,20 ,93, 20);
        
        
        //Color a dog
        
        ofFill();
        ofSetColor(120, 226, 255);
        
        ofBeginShape();
        ofVertex(15,-4);
        ofVertex(40,-10);
        ofVertex(10,-18);
        ofVertex(5,-35);
        ofVertex(3,-17);
        ofVertex(-5, -37);
        ofVertex(-7, -16);
        ofVertex(-35, -17);
        ofVertex(-40,-18);
        ofVertex(-40.5, -2);
        ofVertex(-52, -3);
        ofVertex(-52, 0);
        ofVertex(-40, 3);
        ofVertex(-40, 8);
        ofVertex(-39, 20);
        ofVertex(-35, 20);
        ofVertex(-33, 8);
        ofVertex(-25, 8);
        ofVertex(-25, 20);
        ofVertex(-20, 21);
        ofVertex(-19, 7);
        ofVertex(4,8);
        ofVertex(1,20);
        ofVertex(8,21);
        ofVertex(9,8);
        ofVertex(13,23);
        ofVertex(19,20);
        ofVertex(13,8);
        ofVertex(38,5);
        ofVertex(15,-4);
        ofEndShape();
        
        //Draw a dog outline
        
        ofSetLineWidth(1.75);
        ofSetColor(0);
        ofNoFill();
        
        ofBeginShape();
        ofVertex(15,-4);
        ofVertex(40,-10);
        ofVertex(10,-18);
        ofVertex(5,-35);
        ofVertex(3,-17);
        ofVertex(-5, -37);
        ofVertex(-7, -16);
        ofVertex(-35, -17);
        ofVertex(-40,-18);
        ofVertex(-40.5, -2);
        ofVertex(-52, -3);
        ofVertex(-52, 0);
        ofVertex(-40, 3);
        ofVertex(-40, 8);
        ofVertex(-39, 20);
        ofVertex(-35, 20);
        ofVertex(-33, 8);
        ofVertex(-25, 8);
        ofVertex(-25, 20);
        ofVertex(-20, 21);
        ofVertex(-19, 7);
        ofVertex(4,8);
        ofVertex(1,20);
        ofVertex(8,21);
        ofVertex(9,8);
        ofVertex(13,23);
        ofVertex(19,20);
        ofVertex(13,8);
        ofVertex(38,5);
        ofVertex(15,-4);
        ofEndShape();
        
        ofSetLineWidth(3);
        ofDrawEllipse(10, -10, 4.5, 11);
        ofDrawEllipse(3, -10, 4.5, 11);
        
        ofSetLineWidth(2);
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(10, -10, 4.5, 11);
        ofDrawEllipse(3, -10, 4.5, 11);
        ofSetColor(230,10,10);
        ofDrawCircle(11, -9.5, 2.5);
        ofDrawCircle(4, -9.5, 2.5);
        
        
        //for (int i = 0;i < 100;i++){
        //	if		(i % 5 == 0)ofSetColor(50 , 255, 100);
        //	else if (i % 9 == 0)ofSetColor(255, 50, 100);
        //	else				ofSetColor(255, 255, 255);
        
        //			ofPushMatrix();
        //			ofRotate(ofGetFrameNum(), 1.0, 1.0, 1.0);
        ///			ofTranslate((ofNoise(i/2.4)-0.5)*1000,
        //					(ofNoise(i/5.6)-0.5)*1000,
        //					(ofNoise(i/8.2)-0.5)*1000);
        //		ofCircle(0, 0, (ofNoise(i/3.4)-0.5)*100+ofRandom(3));
        //		ofPopMatrix();
        //}
        
        camera.end();
    }else{
        ofSetColor(255);
        boog.draw(0, 0);
    }
    myFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* draw normal view */
    //ofSetColor(255);
    //myFbo.draw(0, 0);
    
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    ofSetColor(255);
    myFbo.draw(0, 0);
    
    
    /* show information*/
    string info = "";
    info += "1 - 0 : Apply glitch effects.\n";
    info += "q - u : Apply color remap effects.\n";
    info += "L key : Switch 3Dview / 2DImage.\n";
    info += "H key : Hide or show this information.";
    
    if (bShowHelp){
        ofSetColor(0, 200);
        ofDrawRectangle(25, 17, 320, 60);
        ofSetColor(255);
        ofDrawBitmapString(info, 30,30);
    }
    if (bShowGui){
        
    gui.draw();

    }
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
    
    if (key == 'l') bDrawBoog ^= true;
    if (key == 'h') bShowHelp ^= true;
    if (key == 'g') bShowGui ^= true;
    
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

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}