#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

// Cross product for orientation test
long long cross(const Point& O, const Point& A, const Point& B) {
    return (long long)(A.x - O.x) * (B.y - O.y) - (long long)(A.y - O.y) * (B.x - O.x);
}

// Distance squared between two points
long long distSq(const Point& a, const Point& b) {
    return (long long)(a.x - b.x) * (a.x - b.x) + (long long)(a.y - b.y) * (a.y - b.y);
}

// Convex Hull using Andrew's Monotone Chain Algorithm
vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n <= 1) return points;
    
    // Sort points lexicographically
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    
    // Build lower hull
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // Build upper hull
    int t = hull.size() + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() >= t && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    hull.pop_back(); // Remove last point as it's same as first
    return hull;
}

// Calculate polygon area using shoelace formula
double polygonArea(const vector<Point>& polygon) {
    int n = polygon.size();
    if (n < 3) return 0.0;
    
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (long long)polygon[i].x * polygon[j].y;
        area -= (long long)polygon[j].x * polygon[i].y;
    }
    return abs(area) / 2.0;
}

// Point in polygon test using ray casting algorithm
bool pointInPolygon(const Point& point, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / 
                      (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector<vector<Point>> kingdoms;
    vector<vector<Point>> hulls;
    vector<Point> powerStations;
    
    // Read kingdoms
    while (cin >> n && n != -1) {
        vector<Point> kingdom;
        Point powerStation;
        
        // Read power station
        cin >> powerStation.x >> powerStation.y;
        powerStations.push_back(powerStation);
        kingdom.push_back(powerStation);
        
        // Read houses
        for (int i = 1; i < n; i++) {
            Point house;
            cin >> house.x >> house.y;
            kingdom.push_back(house);
        }
        
        kingdoms.push_back(kingdom);
        // Calculate convex hull for this kingdom
        vector<Point> hull = convexHull(kingdom);
        hulls.push_back(hull);
    }
    
    // Read missiles and determine which kingdoms are hit
    vector<bool> destroyed(kingdoms.size(), false);
    Point missile;
    
    while (cin >> missile.x >> missile.y) {
        for (int i = 0; i < kingdoms.size(); i++) {
            if (!destroyed[i] && pointInPolygon(missile, hulls[i])) {
                destroyed[i] = true;
            }
        }
    }
    
    // Calculate total area of destroyed kingdoms
    double totalArea = 0.0;
    for (int i = 0; i < kingdoms.size(); i++) {
        if (destroyed[i]) {
            totalArea += polygonArea(hulls[i]);
        }
    }
    
    cout << fixed << setprecision(2) << totalArea << endl;
    
    return 0;
}