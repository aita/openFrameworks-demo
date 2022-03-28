#include "ofApp.h"
namespace {

class Line {
public:
  ofPoint a;
  ofPoint b;
};

vector<ofPoint> drawnPoints;
vector<Line> lines;
} // namespace

//--------------------------------------------------------------
void ofApp::setup() { ofBackground(255, 255, 255); }

//--------------------------------------------------------------
void ofApp::update() {
  //   for (auto &vert : line.getVertices()) {
  //     vert.x += ofRandom(-1, 1);
  //     vert.y += ofRandom(-1, 1);
  //   }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofEnableAlphaBlending();
  ofSetColor(30, 30, 30, 30);

  for (auto line : lines) {
    ofDrawLine(line.a, line.b);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  switch (key) {
  case 'r':
    lines.clear();
    drawnPoints.clear();
    break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
  for (auto point : drawnPoints) {
    ofPoint mouse;
    mouse.set(x, y);
    float dist = (mouse - point).length();
    if (dist < 30) {
      Line lineTemp;
      lineTemp.a = mouse;
      lineTemp.b = point;
      lines.push_back(lineTemp);
    }
  }
  drawnPoints.push_back(ofPoint(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
