#include "ofApp.h"
#include "geometry.h"

namespace {
using namespace std;

vector<Segment> segments;

const int N = 20;

void random_segment() {
  for (int i = 0; i < N; ++i) {
    auto x = std::floor(ofRandom(0, ofGetWidth()));
    auto y = std::floor(ofRandom(0, ofGetHeight()));
    auto l = std::floor(200 + ofRandom(200));
    if (i % 2 == 0) {
      // horizontal
      if (x + l > ofGetWidth()) {
        l = -l;
      }
      segments.push_back({{x, y}, {x + l, y}});
    } else {
      // vertical
      if (y + l > ofGetHeight()) {
        l = -l;
      }
      segments.push_back({{x, y}, {x, y + l}});
    }
  }
}
} // namespace

//--------------------------------------------------------------
void ofApp::setup() { random_segment(); }

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto &segment : segments) {
    ofDrawLine(segment.p1, segment.p2);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  switch (key) {
  case 'r':
    segments.clear();
    random_segment();
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
