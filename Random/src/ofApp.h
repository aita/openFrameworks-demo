#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  void reset();

  void numberChanged(int &number);
  void minRadiusChanged(float &min_radius);
  void maxRadiusChanged(float &max_radius);
  void resetButtonPressed();

private:
  ofxIntSlider number;
  ofxFloatSlider min_radius;
  ofxFloatSlider max_radius;
  ofxColorSlider color;
  ofxButton reset_button;
  ofxPanel gui;
};
