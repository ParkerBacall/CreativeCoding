#include "GlitchS1.h"

//--------------------------------------------------------------
void GlitchS1::setup(){
   
    maxPixel = 255;
    
    //add gui
    gui.setup();
    gui.add(iGlitch.setup("imageGlitch", 7, 0, 20));
    gui.add(bKeepGlitch.set("Keep Glitch", TRUE));
   
    bShowGui = TRUE;
    
    camWidth = ofGetWidth();
    camHeight = ofGetHeight();
    
    //Open a video grabber for the default camera
    myVideoGrabber.initGrabber(camWidth, camHeight);
    
    glitchVideoData = new unsigned char[camWidth * camHeight * 3];
    
    glitchTexture.allocate(camWidth, camHeight, GL_RGB);
    
    //allocate Fbo to fit screen
    myFbo.allocate(1200, 768);
    
    //setup glitch textures in Fbo
    myGlitch.setup(&myFbo);
    
    myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
}

//--------------------------------------------------------------
void GlitchS1::update(){
    
    //begin Fbo
    myFbo.begin();
    
    //begin Pushview
    ofPushView();
    
    //Ask the grabber to refresh the data
    myVideoGrabber.update();
    
    //if the grabber has fresh data
    if (myVideoGrabber.isFrameNew())
    {
        //Get pointer to the grabber's image data
        unsigned char* pixelData = myVideoGrabber.getPixels();
        
        int nTotalBytes = camHeight * camWidth * 3;
        
        for (int i = 0; i < nTotalBytes; i++)
        {
            if (pixelData[i] < 122)
                glitchVideoData[i] = pixelData[i] * iGlitch;
        }
        
            glitchTexture.loadData(glitchVideoData, camWidth, camHeight, GL_RGB);
}
    glitchTexture.draw(0,0);
    ofPopView();
    
    //end the Fbo
    myFbo.end();
    
}
//--------------------------------------------------------------
void GlitchS1::draw(){
    
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    myFbo.draw(0, 0);
    
    if(bShowGui){
        
        gui.draw();
    }
}

//--------------------------------------------------------------
void GlitchS1::keyPressed(int key){
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
    
    if( key == 'i')
        
        bShowGui ^= true;
    
   }

//--------------------------------------------------------------
void GlitchS1::keyReleased(int key){
    if(bKeepGlitch){
        
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

}

//--------------------------------------------------------------
void GlitchS1::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void GlitchS1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void GlitchS1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void GlitchS1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void GlitchS1::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void GlitchS1::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void GlitchS1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void GlitchS1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void GlitchS1::dragEvent(ofDragInfo dragInfo){ 

}
