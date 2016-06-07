//
//  Button.cpp
//  rgb_game_06_07
//
//  Created by Nicole Messier on 6/7/16.
//
//

#include "Button.h"

void Button::setup(int _bLength, int _bHeight, int _xCenter, int _yCenter){
    
    xCenter = _xCenter;
    yCenter = _yCenter;
    borderWidth = 1;
    bHeight = _bHeight;
    bLength = _bLength;
    originalLength = _bLength;
    xCorner = xCenter - bLength/2;
    yCorner = yCenter - bHeight/2;
    inButton = false;
    
}

void Button::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetLineWidth(borderWidth);
    ofNoFill();
    ofDrawRectangle(xCenter, yCenter, bLength, bHeight);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
}

void Button::animate(int _mouseX, int _mouseY){
    
    if(_mouseX > xCorner && _mouseX < (xCorner + bLength) && _mouseY > (yCorner) && _mouseY < (yCorner + bHeight)){
        borderWidth = 3;
    } else {
        borderWidth = 1;
    }
    cout<< inButton << endl;
}

void Button::insideButton(int _mouseX, int _mouseY){
    
    if(_mouseX > xCorner && _mouseX < (xCorner + bLength) && _mouseY > (yCorner) && _mouseY < (yCorner + bHeight)){
        inButton = true;
    } else {
        inButton = false;
    }
    
    cout<< inButton << endl;
}