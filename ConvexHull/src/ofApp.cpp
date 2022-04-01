#include "ofApp.h"
#include "geometry.h"
#include <algorithm>
#include <vector>

namespace {
using namespace std;

const int POINT_SIZE = 4;

vector<ofPoint> points;
ofPolyline line;

vector<ofPoint> convexHull(vector<ofPoint> points) {
  vector<ofPoint> hull;
  if (points.size() < 3) {
    return hull;
  }

  // find the left most point
  auto p0 = points[0];
  for (auto p : points) {
    if (p.x < p0.x) {
      p0 = p;
    }
  }

  auto pi = p0;
  do {
    hull.push_back(pi);

    auto pj = points[0];
    for (auto pk : points) {
      if (pi == pj || ccw(pi, pk, pj) == COUNTER_CLOCKWISE) {
        pj = pk;
      }
    }
    pi = pj;
  } while (pi != p0);
  return hull;
}

} // namespace

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  line.draw();
  for (auto point : points) {
    ofDrawRectangle(point.x - POINT_SIZE / 2, point.y - POINT_SIZE / 2,
                    POINT_SIZE, POINT_SIZE);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  switch (key) {
  case 'r':
    points.clear();
    line.clear();
    break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  points.push_back(ofPoint(x, y));
  auto hull = convexHull(points);
  if (!hull.empty()) {
    line.clear();
    for (auto p : hull) {
      line.addVertex(p);
    }
    line.close();
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
