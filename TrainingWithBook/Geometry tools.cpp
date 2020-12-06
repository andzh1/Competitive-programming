#include <bits/stdc++.h>
using namespace std; 

typedef long double type;

#define x real()
#define y imag()
#define complex complex <type>

type multiplication(complex v, complex u){
    type answer = (conj(v)*u).y;
    return answer;
}

bool isHigher(complex P, complex S1, complex S2){//checks whether point P is higher then line S1-S2(returns true), unless returns false;
    type mult = multiplication(P - S1, P - S2);
    return mult >= 0;
}

type minimalDistanceFromPointToLine(complex P, complex S1, complex S2)//With gived point P & line S1-S2 returns minimal distance from P to S1-S2
{
    return abs(multiplication(S2 - P, S1 - P) / abs(S2 - S1)); //abs(v) returns length of vector v
}

/* Description
Given vector is vector of ordered polygons' vertices (ordered means that for each vertex i vertices 'i-1' & 'i+1' are ends of edges {i, i-1} & {i, i+1} in real polygon).
 */
type getAreaOfPolygon(vector <complex> polygon)
{
    type areaOfPolygon = 0;
    for(int i = 0; i < polygon.size(); i++){
        areaOfPolygon += multiplication(polygon[i], polygon[(i+1)%polygon.size()]);
    }
    return abs(areaOfPolygon/2);
}

type EuclidianDistance(complex P1, complex P2){
    return abs(P2 - P1);
}


/* Description
With given vector of complex points (i.x >= (i-1).x for each i) returns minimal Euclidian distance between 2 points*/
type findClosestPoints(vector <complex> points){
    int n = points.size();
    type minDistance = EuclidianDistance(points[0], points[1]);
    for(int i = 2; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(points[i].x - points[j].x > minDistance) break;
            if(abs(points[j].y - points[i].y) > minDistance) continue;
            minDistance = min(minDistance, EuclidianDistance(points[j], points[i]));
        }
    }
    return minDistance;
}

/* Description
We have to find convex hull ("выпуклая оболочка") for given set of points.
Given vector has to be sorted by .x coordinate. We can sort it as a vector <pair<type, type>>, & then convert into vector <complex>
(Actually, its A.M.Andrew algorithm)*/
vector <complex> getConvexHull(vector <complex> points) 
{
    vector <complex> convexHull;
    convexHull.push_back(points[0]);
    convexHull.push_back(points[1]);
    for(int ip = 2; ip < points.size(); ip++){
        while ((convexHull.size() > 1) && (multiplication(convexHull[convexHull.size() - 1] - convexHull[convexHull.size() - 2], points[ip] - convexHull[convexHull.size() - 1]) > 0))
            convexHull.pop_back();
        convexHull.push_back(points[ip]);
    }
    return convexHull;
}  

int main()
{}
