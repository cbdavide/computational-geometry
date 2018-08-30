/**
 * This algorithm indentifies the points that belong to the convex hull by
 * identifying the extreme edges of a set of points A. this extreme
 * edges are the ones that conform the convex hull.
 *
 * An edge P formed by the points p, q is said to be extreme iff for all the points r
 * belonging to A (except p and q) are in the same side of the plane divided by P.
 *
 * Complexity: O(n ^ 4)
 *
 * This algorithm doesn't ensure that the points are ordered in any way.
 * The order of the CH points will be the same that the order of the
 * input points
 */

#include "../util.cpp"

void check_edge(const vector<point> &A, vector<bool> & extreme, int i, int j) {
  int n = A.size();
  bool lempty = true, rempty = true;
  for(int k=0; k<n && (lempty || rempty); k++) {
    if(k == i || k == j) continue;

    if(to_left(A[i], A[j], A[k])) lempty = false;
    else rempty = false;
  }

  if(lempty || rempty)
    extreme[i] = extreme[j] = true;
}

vector<point> convex_hull(const vector<point> &A) {
  int dir, n = A.size();
  vector<point> CH;
  vector<bool> extreme(n);

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++)
      if(!(A[i] == A[j])) check_edge(A, extreme, i, j);
  }

  for(int i=0; i<n; i++)
    if(extreme[i]) CH.push_back(A[i]);

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
