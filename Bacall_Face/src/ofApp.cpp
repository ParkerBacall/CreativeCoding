#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255,0,194); //sets color of background
    ofFill();
    
    ofFill();
    ofSetColor(255,0,194);
    ofBeginShape();  //Fill in hair with color
    ofVertex(100,275);
    ofVertex(25,100);
    ofVertex(118,210);
    ofVertex(90,65);
    ofVertex(166,155);
    ofVertex(150,25);
    ofVertex(216,145);
    ofVertex(225,20);
    ofVertex(266,140);
    ofVertex(300,10);
    ofVertex(330,155);
    ofVertex(380,24);
    ofVertex(370,200);
    ofVertex(450,90);
    ofVertex(397,280);
    ofEndShape();
    
    
    ofSetCircleResolution(50);
    ofSetColor(255,0,194); //sets color of face circle
    ofDrawCircle(250, 300, 150); //draws circle
    
    ofNoFill();
    ofSetLineWidth(10);
    ofSetColor(20,240,255);
    ofDrawCircle(250, 300, 150); //draws circle
    
    
    
    ofSetColor(255,0,194); //color in mouth
    ofFill();
    ofBeginShape();
    ofVertex(140,400);
    ofVertex(130,280);
    ofVertex(375,260);
    ofVertex(371,385);
    ofVertex(140,400);
    ofEndShape();
    
    
    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofBeginShape();
    ofVertex(140,400);  //outline of mouth
    ofVertex(130,280);
    ofVertex(375,260);
    ofVertex(371,385);
    ofVertex(140,400);
    ofEndShape();
    
    
    
                             //Outine of teeth crooked, different widths, uneven spacing//
    ofFill();
    ofSetLineWidth(8);
    ofSetColor(20,240,255);
    ofDrawLine(160,400,156,277);
    ofSetLineWidth(5);
    ofDrawLine(184,397,176,277);
    ofSetLineWidth(4);
    ofDrawLine(204,397,202,273);
    ofSetLineWidth(5);
    ofDrawLine(226,395,228,273);
    ofSetLineWidth(5);
    ofDrawLine(248,392,252,270);
    ofSetLineWidth(6);
    ofDrawLine(273,392,271,268);
    ofSetLineWidth(5);
    ofDrawLine(293,391,295,268);
    ofSetLineWidth(4);
    ofDrawLine(324,390,316,266);
    ofSetLineWidth(6);
    ofDrawLine(355,388,343,262);
    
    
    ofFill();
    ofSetColor(255,0,194);     //fill in left eye
    ofDrawEllipse(175,240,20,23);
    
    
    ofNoFill();       //left eye
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofDrawEllipse(175,240,20,23);
    
  
    
    
    
    ofFill();
    ofSetColor(20,240,255);
    ofDrawCircle(174,240,4);
    
    ofFill();
    ofSetColor(255,0,194);      //fill in right eye
    ofDrawEllipse(325,235,24,27);
    
    ofNoFill();       //right eye
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofDrawEllipse(325,235,24,27);
    
  
    
    ofFill();
    ofSetColor(20,240,255);
    ofDrawCircle(325,235,4);
    
    
    ofNoFill();
    ofSetLineWidth(9);
    ofSetColor(20,240,255);
    
    ofBeginShape();  //Hair 7 spikes 15 vertices
    ofVertex(100,275);
    ofVertex(25,100);
    ofVertex(118,210);
    ofVertex(90,65);
    ofVertex(166,155);
    ofVertex(150,25);
    ofVertex(216,145);
    ofVertex(225,20);
    ofVertex(266,140);
    ofVertex(300,10);
    ofVertex(330,155);
    ofVertex(380,24);
    ofVertex(370,200);
    ofVertex(450,90);
    ofVertex(397,280);
    ofEndShape();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
