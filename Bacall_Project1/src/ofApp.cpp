#include "ofApp.h"

#include "scenes/scenes.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
    
    // setup for nice jaggy-less rendering
    ofSetVerticalSync(true);
    
    ofSetBackgroundAuto(false);
    ofBackground(255);
    ofSetFrameRate(60);

    // load scenes
    sceneManager.add(new CAScene2());
    sceneManager.add(new CAScene1());
    sceneManager.add(new CAScene3());
    sceneManager.setup(true); // true = setup all the scenes now (not on the fly)
    ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside
    
    sceneManager.gotoScene("cas1", true);
    lastScene = sceneManager.getCurrentSceneIndex();
    
    // overlap scenes when transitioning
    sceneManager.setOverlap(true);
    
    // attach scene manager to this ofApp so it's called automatically,
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
void ofApp::update(){
    for (int i = 0; i < image.size(); i++) {
        image[i].draw(0, 0, 600, 600);
      }

    
    // the current scene is automatically updated before this function
}

//--------------------------------------------------------------
void ofApp::draw(){
    //the current scene is automatically drawn before this function
    
    if(debug == true) {
    // draw current scene info using the ofxBitmapString stream interface
    // to ofDrawBitmapString
    ofSetColor(200);
    ofDrawBitmapStringHighlight("Current Scene: " + ofToString(sceneManager.getCurrentSceneIndex()) + " " + sceneManager.getCurrentSceneName(), 12, ofGetHeight()-8);
    ofDrawBitmapStringHighlight("fps: "+ofToString(ofGetFrameRate()), ofGetWidth()-110, 20);
    }
}


// current scene input functions are called automatically before calling these


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
            
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
            
        case 'd':
            debug = !debug;
            break;
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
    if (dragInfo.files.size() > 0) {
       image.assign(dragInfo.files.size(), ofImage());
       for (int i = 0; i < dragInfo.files.size(); i++) {
         image[i].load(dragInfo.files[i]);
       }
     }
}
