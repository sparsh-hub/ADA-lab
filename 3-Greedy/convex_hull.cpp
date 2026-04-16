#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

long long cross(Point A, Point B, Point C) {
    return 1LL*(B.x - A.x)*(C.y - A.y) -
           1LL*(B.y - A.y)*(C.x - A.x);
}

bool pointInsideTriangle(Point A, Point B, Point C, Point P) {
    long long c1 = cross(A, B, P);
    long long c2 = cross(B, C, P);
    long long c3 = cross(C, A, P);
    bool has_neg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool has_pos = (c1 > 0) || (c2 > 0) || (c3 > 0);
    return !(has_neg && has_pos); 
}

int main() {
    vector<Point> points = {
        {0,0}, {2,0}, {2,2}, {0,2},
        {1,1}, {1,0}
    };
    int n = points.size();
    vector<bool> isInterior(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                for (int p = 0; p < n; p++) {
                    if (p == i || p == j || p == k)
                        continue;
                    if (pointInsideTriangle(points[i], points[j], points[k], points[p])) {
                        isInterior[p] = true;
                    }
                }
            }
        }
    }
    cout << "Boundary Points:\n";
    for (int i = 0; i < n; i++) {
        if (!isInterior[i])
            cout << points[i].x << " " << points[i].y << endl;
    }
}