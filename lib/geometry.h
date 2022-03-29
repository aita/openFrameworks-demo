#pragma once
#include "ofPoint.h"
#include <glm/gtx/exterior_product.hpp>

#define EPS 0.00001

using Point = glm::vec2;

struct Segment {
  Point p1, p2;
};

// signed area of a triangle
int signed_area(Point p0, Point p1, Point p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

enum {
  COUNTER_CLOCKWISE = -1,
  COLLINEAR = 0,
  CLOCKWISE = 1,
};

// counter-clockwise orientation test
int ccw(Point p0, Point p1, Point p2) {
  auto sa = signed_area(p0, p1, p2);
  if (sa > EPS)
    return COUNTER_CLOCKWISE;
  if (sa < -EPS)
    return CLOCKWISE;
  return COLLINEAR;
}

bool intersect(Point p0, Point p1, Point p2, Point p3) {
  return ccw(p0, p1, p2) * ccw(p0, p1, p3) <= 0 &&
         ccw(p2, p3, p0) * ccw(p2, p3, p1) <= 0;
}

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point cross_point(Segment s1, Segment s2) {
  auto base = s2.p2 - s2.p1;
  auto d1 = glm::abs(glm::cross(base, s1.p1 - s2.p1));
  auto d2 = glm::abs(glm::cross(base, s1.p2 - s2.p1));
  auto t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
