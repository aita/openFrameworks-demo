#pragma once
#include "ofMain.h"

class Walker {
public:
  int x;
  int y;

  Walker() {
    x = ofGetWidth() / 2;
    y = ofGetHeight() / 2;
  }

  void draw() {
    ofFill();
    ofDrawRectangle(x, y, 1, 1);
  }

  void update() {
    float stepx = round(ofRandom(-1, 1));
    float stepy = round(ofRandom(-1, 1));
    x += stepx;
    y += stepy;
  }
};
