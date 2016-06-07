#pragma once

#include "ofMain.h"
#include "Token.h"
#include "ofxTextSuite.h"
#include "ofxXmlSettings.h"
#include "Button.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void gameOverScreen();
    
    //------------API Data------------
    vector<Token> dashboardTokens;
    ofxJSONElement response2;
    
    
    //------------Setting Up Buttons------------
    int bHeight1, bLength1;
    Button yesButton;
    Button noButton;
    
    //------------Setting Up Questions------------
    int questionCounter;
    int questionID;
    string question;
    string questionText;

    //------------Setting Up Text------------
    ofxTextBlock leaderBoard;
    ofxTextBlock  questionText1;
    ofxTextBlock  yes;
    ofxTextBlock  no;
    ofxTextBlock  questionNumber;
    ofxTextBlock  roundsNumber;
    ofxTextBlock  gameOver;
    TextBlockAlignment  alignmentLeaderboard;
    TextBlockAlignment  alignmentQuestion;
    
    //------------Setting Up XML Data-----------
    ofxXmlSettings XML;
    int questionsPerRound;
    int questionsPerGame;
    
    int roundsCounter; //count the number of rounds
};
