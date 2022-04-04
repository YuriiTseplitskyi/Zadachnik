#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>

using namespace std;
template<class T>
void Swap(T &a, T &b)
{
    T c=a;
    a=b;
    b=c;
}
class Point;
typedef bool (*Compare)(const Point &a,const Point &b);
class Point
{
public:
    double x;
    double y;
    Point();
    Point(int x,int y);
    virtual ~Point();
    static Point* createArray(int n);
    string toString()const;
    static Point createFromKBD();
    void readFromKBD();
    static double getDistance(const Point &a,const Point &b);
    double getDistance(const Point &other);
    int getQuarter()const;
    static bool checkTwoPoints(const Point &a,const Point &b);
    static double getSumDistances(const Point &a,Point *points,int n);
    static double getTriangleArea(const Point &a,const Point &b,const Point &c);
    static void Sort(Point *points, int n, Compare compare);
};

ostream& operator<<(ostream& out,const Point& point);
#endif // POINT_H
