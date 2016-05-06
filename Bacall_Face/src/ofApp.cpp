#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set up circle resolution
    ofSetCircleResolution(50);
    //set up color of background
    ofBackground(255,0,194);
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    //Draw outline face circle
    ofNoFill();
    ofSetLineWidth(10);
    ofSetColor(20,240,255);
    ofDrawCircle(250, 300, 150);
    
    
    
    //Draw mouth
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofBeginShape();
    ofVertex(140,400);
    ofVertex(130,280);
    ofVertex(375,260);
    ofVertex(371,385);
    ofVertex(140,400);
    ofEndShape();
    
    
    
    /*Draw tetch, crooked, 
    different widths, uneven spacing*/
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
    
    
   
    
    //Draw outer left eye
    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofDrawEllipse(175,240,20,23);
    
    //Draw left eyeball
    ofFill();
    ofSetColor(20,240,255);
    ofDrawCircle(174,240,4);
    
   
    //Draw right eye
    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(20,240,255);
    ofDrawEllipse(325,235,24,27);
    
  
    //Draw right eyeball
    ofFill();
    ofSetColor(20,240,255);
    ofDrawCircle(325,235,4);
    
    //Draw hair, 7 spikes, 15 vertices
    ofNoFill();
    ofSetLineWidth(9);
    ofSetColor(20,240,255);
    ofBeginShape();
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

