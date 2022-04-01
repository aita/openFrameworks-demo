#include "ofApp.h"
#include "geometry.h"

namespace {
using namespace std;

vector<ofPoint> drawPoints;
vector<Segment> segments;
} // namespace

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(ofColor::white);
  for (auto &p : drawPoints) {
    ofDrawRectangle(ofPoint(p) - 2, 4, 4);
  }
  if (segments.size() >= 2 && intersect(segments[0], segments[1])) {
    auto p = cross_point(segments[0], segments[1]);
    ofDrawRectangle(ofPoint(p) - 2, 4, 4);

    ofSetColor(255, 0, 0);
  } else {
    ofSetColor(0, 255, 0);
  }

  for (auto &seg : segments) {
    ofDrawLine(seg.p1, seg.p2);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  switch (key) {
  case 'r':
    drawPoints.clear();
    segments.clear();
    break;

  default:
    break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  if (drawPoints.size() >= 4) {
    drawPoints.clear();
    segments.clear();
  }
  drawPoints.push_back(ofPoint(x, y));
  if (drawPoints.size() % 2 == 0) {
    segments.push_back(Segment{drawPoints[drawPoints.size() - 2],
                               drawPoints[drawPoints.size() - 1]});
  }
}

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
