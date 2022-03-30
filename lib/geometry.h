#pragma once
#include "ofApp.h"

#define EPS 0.00001

struct Segment {
  ofPoint p1, p2;
};

float cross(ofPoint p0, ofPoint p1) { return p0.x * p1.y - p0.y * p1.x; }

// signed area of a triangle
int signed_area(ofPoint p0, ofPoint p1, ofPoint p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

enum {
  COUNTER_CLOCKWISE = -1,
  COLLINEAR = 0,
  CLOCKWISE = 1,
};

// counter-clockwise orientation test
int ccw(ofPoint p0, ofPoint p1, ofPoint p2) {
  auto sa = signed_area(p0, p1, p2);
  if (sa > EPS)
    return COUNTER_CLOCKWISE;
  if (sa < -EPS)
    return CLOCKWISE;
  return COLLINEAR;
}

bool intersect(ofPoint p0, ofPoint p1, ofPoint p2, ofPoint p3) {
  return ccw(p0, p1, p2) * ccw(p0, p1, p3) <= 0 &&
         ccw(p2, p3, p0) * ccw(p2, p3, p1) <= 0;
}

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

ofPoint cross_point(Segment s1, Segment s2) {
  auto base = s2.p2 - s2.p1;
  auto d1 = std::fabs(cross(base, s1.p1 - s2.p1));
  auto d2 = std::fabs(cross(base, s1.p2 - s2.p1));
  auto t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
