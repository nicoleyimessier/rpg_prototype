//
//  Token.cpp
//  mySketch
//
//  Created by Nicole Messier on 6/2/16.
//
//

#include "Token.h"


ofTrueTypeFont Token::_raleway14;

void Token::setup(int _id, int _size){
    idValue = _id;
    length = 2*ofGetWidth()/3;
    height = ofGetHeight()/(_size+1);
    tokenLength = 30;
    value = 30;
    tokenColor = ofColor((255/_size)*idValue, 0, (255/_size)*idValue);
    
    //load font
    _raleway14.load("raleway.ttf", 14, true, true);
}

void Token::parseData (string _tokenName){
    tokenName=_tokenName;
    
}

void Token::draw(){
    
    //draw token value
    ofSetColor(tokenColor);
    ofFill();
    ofDrawRectangle(0, height*idValue, value, height);

    
    //draw titles
    ofSetColor(255);
    ofFill();
    _raleway14.drawString(tokenName, 10,  height*idValue + height/2);
    
    //draw value number
    ofSetColor(255);
    ofFill();
    _raleway14.drawString(ofToString(value), 2*ofGetWidth()/3-100,  height*idValue + height/2);
    
}

void Token::update(int tokenChange){
    
    value += tokenChange; //update value number
    
}

