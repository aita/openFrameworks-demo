#include "ofApp.h"

namespace {
float octavePerlin(float x, float y, float z, int octaves, float persistence) {
  float total = 0;
  float frequency = 1;
  float amplitude = 1;
  float maxValue = 0;
  for (int i = 0; i < octaves; i++) {
    total += ofNoise(x * frequency, y * frequency, z * frequency) * amplitude;
    maxValue += amplitude;
    amplitude *= persistence;
    frequency *= 2;
  }
  return total / maxValue;
}

} // namespace

void ofApp::updateImage() {
  for (int y = 0; y < image.getHeight(); y++) {
    for (int x = 0; x < image.getWidth(); x++) {
      image.setColor(
          x, y,
          octavePerlin(x * scale, y * scale, 1.0, octaves, persistence) * 255);
    }
  }
  image.update();
}

//--------------------------------------------------------------
void ofApp::setup() {
  gui.setup();
  gui.add(scale.setup("scale", 0.01, 0, 0.1));
  gui.add(octaves.setup("octaves", 6, 1, 20));
  gui.add(persistence.setup("persistence", 0.5, 0, 1));

  scale.addListener(this, &ofApp::onScaleChanged);
  octaves.addListener(this, &ofApp::onOctavesChanged);
  persistence.addListener(this, &ofApp::onPersistenceChanged);

  scale.setUpdateOnReleaseOnly(true);
  octaves.setUpdateOnReleaseOnly(true);
  persistence.setUpdateOnReleaseOnly(true);

  image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
  updateImage();
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  image.draw(0, 0, ofGetWidth(), ofGetHeight());

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
