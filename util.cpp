#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
  point(int _x, int _y) : x(_x), y(_y) {}
  point() {}

  bool operator==(const point &a)const {
    return (x == a.x) && (y == a.y);
  }

  point operator+(const point &a)const {
    return point(x + a.x, y + a.y);
  }

  point operator-(const point &a)const {
    return point(x - a.x, y - a.y);
  }
};

int cross(const point &a, const point &b) {
  return (a.x * b.y) - (b.x * a.y);
}

bool to_left(const point &o, const point &p, const point &q) {
  // returns true if oq is to the left (ccw) of op
  return cross(p - o, q - o) > 0;
}

bool degenerate_triangle(point &a, point &b, point &c) {
  // returns true if the points a, b, c are colinear
  return (cross(a, b) == 0) && (cross(a, c) == 0);
}
