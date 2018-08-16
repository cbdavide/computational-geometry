/**
 * This algorithm indentifies which are the extreme points of the convex hull
 * of a set of points A.
 *
 * To identify which are the extreme points of A, it makes the assumption that
 * a point p is extreme iif that point doesn't lies inside any triangle formed
 * by some points a, b, c that belong to the set of points A.
 *
 * Complexity: O(n ^ 4)
 *
 * This algorithm doesn't ensure that the points are ordered in any way.
 * The order of the CH points will be the same that the order of the
 * input points
 */

#include "../util.cpp"

bool in_triangle(point a, point b, point c, point p) {
  if(degenerate_triangle(a, b, c)) return false;

  bool r = to_left(a, b, p);
  bool t = to_left(b, c, p);
  bool z = to_left(c, a, p);

  return (r == t) && (r == z);
}

vector<point> convex_hull(vector<point> A) {
  int n = A.size();
  vector<point> CH;
  bool non_extreme[n] = { 0 };

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {

        for(int l=0; l<n; l++) {
          if(l == i || l == j || l == k)
          continue;

          if(in_triangle(A[i], A[j], A[k], A[l]))
            non_extreme[l] = 1;
        }
      }
    }
  }

  for(int i=0; i<n; i++)
    if(!non_extreme[i]) CH.push_back(A[i]);

  return CH;
}

 int main() {
  int n, x, y;
  cin >> n;
  vector<point> A(n);
  for(int i=0; i<n; i++) {
    cin >> x >> y;
    A[i].x = x; A[i].y = y;
  }
  vector<point> CH = convex_hull(A);
  for(int i=0; i<CH.size(); i++) {
    cout << CH[i].x << ' ' << CH[i].y << endl;
  }
}
