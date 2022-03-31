#include "ofApp.h"
#include <vector>

namespace {
using namespace std;

vector<ofPoint> points;
vector<float> radius;
} // namespace

void ofApp::reset() {
  points.clear();
  radius.clear();
  for (int i = 0; i < number; i++) {
    points.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    radius.push_back(ofRandom(min_radius, max_radius));
  }
}

void ofApp::numberChanged(int &number) { reset(); }

void ofApp::minRadiusChanged(float &min_radius) {
  min_radius = min<float>(min_radius, max_radius);
  reset();
}

void ofApp::maxRadiusChanged(float &max_radius) {
  max_radius = max<float>(min_radius, max_radius);
  reset();
}

void ofApp::resetButtonPressed() { reset(); }

//--------------------------------------------------------------
void ofApp::setup() {
  ofEnableAlphaBlending();
  ofSetCircleResolution(64);

  number.addListener(this, &ofApp::numberChanged);
  min_radius.addListener(this, &ofApp::minRadiusChanged);
  max_radius.addListener(this, &ofApp::maxRadiusChanged);
  // color.addListener(this, &ofApp::colorChanged);
  reset_button.addListener(this, &ofApp::resetButtonPressed);

  gui.setup();
  gui.add(number.setup("number", 1000, 10, 5000));
  gui.add(min_radius.setup("min_radius", 10, 10, 300));
  gui.add(max_radius.setup("max_radius", 40, 10, 300));
  gui.add(color.setup("color", ofColor(31, 63, 255, 63), ofColor(0, 0, 0, 0),
                      ofColor(255, 255, 255, 255)));
  gui.add(reset_button.setup("reset"));

  reset();
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(color);
  for (size_t i = 0; i < points.size(); i++) {
    ofDrawCircle(points[i], radius[i]);
  }

  gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

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
