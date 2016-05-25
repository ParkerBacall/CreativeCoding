/*
 * Copyright (c) 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxAppUtils for documentation
 *
 */
#include "ofApp.h"

#include "scenes/scenes.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetColor(200);
    
	// setup for nice jaggy-less rendering
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
   
    
	// load scenes
    sceneManager.add(new GlitchS1());
	sceneManager.setup(true); // true = setup all the scenes now (not on the fly)
	ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside
	
	// start with a specific scene
	// set now to true in order to ignore the scene fade and change now
	sceneManager.gotoScene("GS1", true);
	lastScene = sceneManager.getCurrentSceneIndex();
	
	// overlap scenes when transitioning
	sceneManager.setOverlap(true);
	
	// attach scene manager to this ofxApp so it's called automatically,
	// you can also call the callbacks (update, draw, keyPressed, etc) manually
	// if you don't set it
	//
	// you can also turn off the auto sceneManager update and draw calls with:
	// setSceneManagerUpdate(false);
	// setSceneManagerDraw(false);
	//
	// the input callbacks in your scenes will be called if they are implemented
	//
	setSceneManager(&sceneManager);
    
    debug = false;
}

//--------------------------------------------------------------
void ofApp::update() {

	// the current scene is automatically updated before this function

	
}

//--------------------------------------------------------------
void ofApp::draw() {

	// the current scene is automatically drawn before this function

	// show the render area edges with a white rect

	
	// draw current scene info using the ofxBitmapString stream interface
	// to ofDrawBitmapString
	
    
    if(debug == true) {
     myFbo.begin();
       
       
        myFbo.end();

        myFbo.draw(0,0);
    }

	


	// the warp editor is drawn automatically after this function
}

// current scene input functions are called automatically before calling these
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	switch (key) {
	
		case 'd':
			bDebug = !bDebug;
			break;
			
		case 'a':
			transformer.setAspect(!transformer.getAspect());
			break;
			
		case 'c':
			transformer.setCentering(!transformer.getCentering());
			break;
			
		case 'm':
			transformer.setMirrorX(!transformer.getMirrorX());
			break;
			
		case 'n':
			transformer.setMirrorY(!transformer.getMirrorY());
			break;
			
		case 'q':
			transformer.setWarp(!transformer.getWarp());
			break;
			
		case 'f':
			ofToggleFullscreen();
			break;
	
        case 'p':
            sceneManager.runToggle();
            break;
            
		case OF_KEY_LEFT:
			sceneManager.prevScene();
			break;
			
		case OF_KEY_RIGHT:
			sceneManager.nextScene();
			break;
			
		case OF_KEY_DOWN:
			if(sceneManager.getCurrentScene()) { // returns NULL if no scene selected
				lastScene = sceneManager.getCurrentSceneIndex();
			}
			sceneManager.noScene();
			break;
			
		case OF_KEY_UP:
			sceneManager.gotoScene(lastScene);
			break;
			
		
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	
}
