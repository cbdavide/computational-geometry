/**
 * Jarvis March Algorithm - (Gift Wrapping)
 *
 * This algorithms finds the Convex Hull of a set of points A, identifying a
 * pivot point (the lowest then leftmost one), and finding the next point from it.
 *
 * To select the next point that belongs to the CH, it takes the point that makes
 * the minimum left turn from the actual point.
 *
 * ¿ How to find the next point s that achieves the minimum left turn ?
 *
 * Being k the current point (last point founded by the algorithm), and a point s
 * that is partially selected, for each point different from s and p, called t, if
 * t is to the right of the segment ks then t takes a minor left turn than s
 * so we should  update s to t.
 *
 * This implementations returns the CH ordered in CW with respect the lowest then
 * leftmost point.
 *
 * Complexity: O(n ^ 2)
 * This algorithm is output-sensitive (It's time execution depends of the size
 * of the output CH)
 */
#include "../util.cpp"

vector<point> convex_hull(vector<point> &A) {

    int n = A.size();
    vector<point> CH;
    int ltl = lowest_then_leftmost(A), k = ltl;

    do {
        CH.push_back(A[k]);
        int s = -1;
        for(int t=0; t<n; t++) {
            if(t != k && t != s && (s == -1 || !to_left(A[k], A[s], A[t])))
                s = t;
        }
        k = s;
    } while(k != ltl);

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
