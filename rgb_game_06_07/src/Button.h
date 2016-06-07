//
//  Button.h
//  rgb_game_06_07
//
//  Created by Nicole Messier on 6/7/16.
//
//

#ifndef __rgb_game_06_07__Button__
#define __rgb_game_06_07__Button__

#include <iostream>

#endif /* defined(__rgb_game_06_07__Button__) */

#include "ofMain.h"

class Button{
public:
    
    void setup(int _bHeight, int _bLength,  int _xCenter, int _yCenter);
    void draw();
    void animate(int _mouseX, int _mouseY);
    void insideButton(int _mouseX, int _mouseY);
    
    
    int xCenter, yCenter;
    int xCorner, yCorner;
    int bHeight, bLength;
    int originalLength;
    int borderWidth;
    bool inButton;
};
