#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //------------Loading XML------------
    //loading XML data to configure the number of questions per round and questions per game
    if( XML.loadFile("mySettings.xml") ){
		cout << "mySettings.xml loaded!" << endl; ;
	}else{
		cout << "unable to load mySettings.xml check data/ folder" << endl;
	}
    
    questionsPerRound = XML.getValue("GAME:ROUND", 3);
    questionsPerGame = XML.getValue("GAME:QUESTIONS", 9);
    
    
    //------------API Data------------
    
    //string apiUrl = "http://127.0.0.1:8081/listQuestions"; // prototype1
    string apiUrl = "http://localhost:3000/questionlist";
    
    if(!response2.open(apiUrl)){
        cout << "failed to parse" << endl;
    } else {
        cout << response2 << endl;
    }
    
    questionCounter = 1; //counts the number of questions from start to game end
    questionID = 1; //used to pull question from API
    
    
    //------------set up dashboard of tokens------------
    for(int i=0; i<response2[0]["Tokens"].size(); i++){
        Token tempToken;
        tempToken.setup(i + 1, response2[0]["Tokens"].size());
        dashboardTokens.push_back(tempToken);
    }
    
    
    //prase data
    for(int i=0; i<dashboardTokens.size(); i++){
        int id = i + 1;
        //tokens
        string token = "Token" + ofToString(id);
        string tokenName = response2[0]["Tokens"][token]["name"].asString();
        cout << "TokenName: " << tokenName << endl;
        dashboardTokens[i].parseData(tokenName);
    }
    
    //------------Setting Up Text------------
    //loading font
    leaderBoard.init("raleway.ttf", 25);
    leaderBoard.setText("Leaderboard");
    questionText1.init("raleway.ttf", 14);
    questionNumber.init("raleway.ttf", 14);
    roundsNumber.init("raleway.ttf", 14);
    gameOver.init("raleway.ttf", 30);
    yes.init("raleway.ttf", 14);
    no.init("raleway.ttf", 14);
    
    gameOver.setText("Game Over! Thanks for playing!");
    yes.setText("YES");
    no.setText("NO");
    
     //------------Setting Up Buttons------------
    bLength1 = (ofGetWidth() - dashboardTokens[0].length)/2 - 20;
    bHeight1 = 45;
    yesButton.setup(bLength1, bHeight1, (ofGetWidth() - (ofGetWidth() - dashboardTokens[0].length)/4), ofGetHeight()/2+20);
    noButton.setup(bLength1, bHeight1, (ofGetWidth() - 3*(ofGetWidth() - dashboardTokens[0].length)/4), ofGetHeight()/2+20);
    
    roundsCounter = 1; 
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::gameOverScreen(){
    ofSetColor(255);
    ofFill();
    ofDrawRectangle(dashboardTokens[0].length, 0, ofGetWidth() - dashboardTokens[0].length, ofGetHeight());
    gameOver.wrapTextX(ofGetWidth() - dashboardTokens[0].length);
    gameOver.drawCenter(dashboardTokens[0].length+ (ofGetWidth() - dashboardTokens[0].length)/2, ofGetHeight()/3);
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    //------------Draw Leaderboard------------
    ofSetColor(51, 57, 83);
    ofFill();
    ofDrawRectangle(0, 0, dashboardTokens[0].length, ofGetHeight());
    leaderBoard.setColor(255, 255, 255,255);
    leaderBoard.drawCenter(dashboardTokens[0].length/2,  dashboardTokens[0].height/3);
    
    //draw dashboard tokens
    for(int i=0; i<dashboardTokens.size(); i++){
        dashboardTokens[i].draw();
    }
    
    //------------Draw User interface------------
    
    //Draw Questions
    questionText = response2[questionID]["question"].asString();
    questionText1.setText(questionText);
    questionText1.setColor(51, 57, 83, 255);
    questionText1.wrapTextX(ofGetWidth() - dashboardTokens[0].length);
    questionText1.drawCenter(dashboardTokens[0].length+ (ofGetWidth() - dashboardTokens[0].length)/2, ofGetHeight()/3);
    
    //draw number of questions + round
    questionNumber.setText("Number of Questions: " + ofToString(questionCounter));
    roundsNumber.setText("Number of Rounds: " + ofToString(roundsCounter));
    questionNumber.setColor(51, 57, 83, 255);
    questionNumber.draw(dashboardTokens[0].length, 0);
    roundsNumber.setColor(51, 57, 83, 255);
    roundsNumber.draw(dashboardTokens[0].length, 20);
    roundsCounter = questionCounter/questionsPerRound + 1;
    
    //------------Draw Buttons-------------------------
    
    ofSetColor(51, 57, 83);
    yesButton.draw();
    noButton.draw();
    yesButton.animate(mouseX, mouseY);
    noButton.animate(mouseX, mouseY);
    yesButton.insideButton(mouseX, mouseY);
    noButton.insideButton(mouseX, mouseY);
    
    //button text
    yes.setColor(51, 57, 83, 255);
    yes.drawCenter(yesButton.xCenter, yesButton.yCenter - bHeight1/4);
    no.setColor(51, 57, 83, 255);
    no.drawCenter(noButton.xCenter, noButton.yCenter - bHeight1/4);
    
    ofSetRectMode(OF_RECTMODE_CORNER);

    
    //------------Game Over Screens-------------------------
    //game over when tokens goes below 0
    for(int i=0; i<dashboardTokens.size(); i++){
        if(dashboardTokens[i].value<0){
            gameOverScreen();
        }
    }
    
    //game over when user reaches the max number of questions per game
    if(questionCounter > questionsPerGame){
        gameOverScreen();
    }
    
    //game over when any token reaches the max value on the leaderBoard
    //used when the questions per game is high
    for(int i=0; i<dashboardTokens.size(); i++){
        dashboardTokens[i].draw();
    
        if(dashboardTokens[i].value > dashboardTokens[i].value){
           gameOverScreen();
        }
    }
    
    
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
    //------------animate buttons when mouse is pressed------------
    
    if(yesButton.inButton == true){
        yesButton.bLength -= 20;
    }
    
    if(noButton.inButton == true){
        noButton.bLength -= 20;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    //yes button
    if(yesButton.inButton == true){
        yesButton.bLength = yesButton.originalLength; //return button to original length
        
        //update leaderboard
        for(int i=0; i<dashboardTokens.size(); i++){
            string thisString = response2[questionID]["Tokens"]["Token" + ofToString(i + 1)]["yes"].asString();
            int thisValue = ofToInt(thisString);
            dashboardTokens[i].update(thisValue);
        }
        
        //change question number and increase counter
        questionID =  ofRandom(1, response2.size());
        questionCounter++;
    }
    
    //no button
    if(noButton.inButton == true){
        noButton.bLength = noButton.originalLength;
        
        //update leaderboard
        for(int i=0; i<dashboardTokens.size(); i++){
            string thisString = response2[questionID]["Tokens"]["Token" + ofToString(i + 1)]["no"].asString();
            int thisValue = ofToInt(thisString);
            dashboardTokens[i].update(thisValue);
        }
        
        //change question number and increase counter
        questionID =  ofRandom(1, response2.size());
        questionCounter++;
    }
    

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
