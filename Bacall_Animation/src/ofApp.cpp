#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x= 200;
    y=300;
    degrees = 0;
    ofBackground(255,255,181);
    ofSetBackgroundAuto(false);
    //isMoving = true;
    isRotating = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
        if( isRotating){
        degrees= degrees - 2;
    
    }
        }

//--------------------------------------------------------------
void ofApp::draw(){
    
    float x = ofMap( ofNoise( ofGetElapsedTimef()/3.5, -1000), 0, 1, 0, ofGetWidth());
    float y = ofMap( ofNoise( ofGetElapsedTimef()/3.5, 1000), 0, 1, 0, ofGetHeight());

    
    ofSetLineWidth(2);
   
    ofTranslate(x, y);
   
  
        
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
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //if(key == 'q'){
        
        //isMoving =false;
    //}
    
    //if(key == 'w'){
        
      //  isMoving = true;
        
    //}
    
    
    
    if (key == 'c') {
        isRotating = false;
}
    
    if (key == 'v') {
        isRotating = true;
    }
    
    if (key == 's') {
        
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
    }

    
   if (key == 'x') {
       
       ofSetBackgroundAuto(true);
       
   }
    
    if (key == 'z') {
        
        ofSetBackgroundAuto(false);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    ofBackground(255,255,181);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
