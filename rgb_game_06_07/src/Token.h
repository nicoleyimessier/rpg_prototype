//
//  Token.h
//  mySketch
//
//  Created by Nicole Messier on 6/2/16.
//
//

#ifndef __mySketch__Token__
#define __mySketch__Token__

#include <iostream>

#endif /* defined(__mySketch__Token__) */

#include "ofMain.h"
#include "ofxJSON.h"

class Token{
public:
    
    int length, height; //max length and height
    int tokenLength, tokenHeight; //dynamic token length and height
    int value; //value of token
    int idValue; //id of token
    string title; //name of token
    ofColor tokenColor; //color for leaderboard
    
    void setup(int _id, int _size); //setup token
    void parseData (string _tokenName); //parse API data
    void draw(); //draw token
    void update(int tokenChange); //update token when button is pressed
    
    //parsing data
    ofxJSONElement response;
    string tokenName;
    
    //class font
    static ofTrueTypeFont _raleway14;
};
