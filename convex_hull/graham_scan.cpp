#include "../util.cpp"

point p0;

bool cmp(point a, point b) {
    return to_left( p0, a, b );
}

point next_to_top(stack<point> &A) {
    assert(A.size() >= 2);
    point f = A.top(); A.pop();
    point s = A.top(); A.pop();
    A.push(s); A.push(f);
    return s;
}

vector<point> stack_to_vector(stack<point> &A) {
    int n = A.size();
    vector<point> B(A.size());
    for(int i=0; i<n; i++)
        B[n - i - 1] = A.top(), A.pop();
    return B;
}

vector<point> convex_hull(vector<point> &A) {
    int ltl, n = A.size();

    ltl = lowest_then_leftmost(A);
    swap(A[ltl], A[0]);

    p0 = A[0];
    sort(A.begin() + 1, A.end(), cmp);

    // cout << "LTL " << p0.x << ' ' << p0.y << endl;

    // cout << "SORTED POINTS" << endl;
    // for(point p : A)
        // cout << p.x << ' ' << p.y << endl;
    // cout << "END OF SORTED POINTS" << endl;

    stack<point> S, T;
    S.push(A[0]); S.push(A[1]);

    for(int i=n-1; i>1; i--)
        T.push(A[i]);

    while(!T.empty()) {
        if(to_left( next_to_top( S ), S.top(), T.top() ))
            S.push(T.top()), T.pop();
        else
            S.pop();
    }

    return stack_to_vector(S);
}

int main() {
    int n; cin >> n;

    vector<point> A(n);
    for(int i=0; i<n; i++)
        cin >> A[i].x >> A[i].y;

    vector<point> CH = convex_hull(A);
    cout << CH.size() << endl;
    for(int i=0; i<CH.size(); i++) {
        cout << CH[i].x << ' ' << CH[i].y << endl;
    }
}
