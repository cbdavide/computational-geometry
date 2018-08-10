/**
 * This algorithm indentifies which are the extreme points of the convex hull
 * of a set of points A.
 *
 * To identify which are the extreme points of A, it makes the assumption that
 * a point p is extreme iif that point doesn't lies inside any triangle formed
 * by some points a, b, c that belong to the set of points A.
 *
 * Complexity: O(n ^ 4)
 */

 #include "../util.cpp"

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

   for(int i=0; i<n; i++) {
     if(!non_extreme[i]) CH.push_back(i);
   }
   return CH;
 }

 int main() {
   vector<point> A(10);
   convex_hull(A);
 }
