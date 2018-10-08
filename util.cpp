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

int dot(const point &a, const point &b) {
    return (a.x * b.x) + (a.y * b.y);
}

int area2(const point &p, const point &q, const point &s) {
    return p.x * q.y - p.y * q.x
        + q.x * s.y - q.y * s.x
        + s.x * p.y - s.y * p.x;
}

bool between(const point &p, const point &k, const point &q) {
    return dot( p - k , k - q ) > 0;
}

bool to_left(const point &p, const point &q, const point &k) {
    int s = area2( p, q, k );
    if(s > 0) return true; // left
    if(s < 0) return false; //right
    return between( p, q, k ); // colinear
}

bool to_right(const point &p, const point &q, const point &k) {
    int s = area2( p, q, k );
    if(s > 0) return false; // left
    if(s < 0) return true; //right
    return between( p, q, k ); // colinear
}

bool degenerate_triangle(point a, point b, point c) {
  // returns true if the points a, b, c are colinear
  return (cross(a, b) == 0) && (cross(a, c) == 0);
}

int lowest_then_leftmost(vector<point> &A) {
    // returns the index of the lowest then leftmost point of the set of points
    int ltl = 0, n = A.size();

    for(int i=1; i<n; i++) {
        if((A[i].y < A[ltl].y) || (A[i].y == A[ltl].y && A[i].x < A[ltl].x))
            ltl = i;
    }

    return ltl;
}
