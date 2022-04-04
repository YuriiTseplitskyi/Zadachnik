#include "point.h"
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <cmath>

Point::Point()
{
    x=0;
    y=0;
}

Point::Point(int x,int y)
{
    this->x=x;
    this->y=y;
}

Point::~Point()
{
    //dtor
    //cout<<"Destrucktor"<<endl;
}

string Point::toString()const
{
    stringstream out;
    out<<"("<<x<<", "<<y<<") ";
    return out.str();
}

ostream& operator<<(ostream& out,const Point& point)
{
    out<<point.toString();
    return out;
}

Point *Point::createArray(int n)
{
    int from=-10;
    int to=10;
    srand(time(NULL));
    Point *a = new Point[n];
    for (int i = 0; i < n; i++)
    {
        a[i].x = (from*100 + rand() % ((to-from)*100))/100.0;
        a[i].y = (from*100 + rand() % ((to-from)*100))/100.0;
    }
    return a;
}

Point Point::createFromKBD()
{
    double x;
    double y;
    cout<<"X=";cin>>x;
    cout<<"Y=";cin>>y;
    return Point(x,y);
}

void Point::readFromKBD()
{
    cout<<"X=";cin>>x;
    cout<<"Y=";cin>>y;
}

double Point::getDistance(const Point &a,const Point &b)
{
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

double Point::getDistance(const Point &other)
{
    double dx=x-other.x;
    double dy=y-other.y;
    return sqrt(dx*dx + dy*dy);
}

int Point::getQuarter()const
{
    if(x>0 && y>0) return 1;
    if(x<0 && y>0) return 2;
    if(x<0 && y<0) return 3;
    if(x>0 && y<0) return 4;
    return 0;
}

bool Point::checkTwoPoints(const Point &a,const Point &b)
{
    if(a.x>b.x)return true;
    if(a.x==b.x) return a.y>b.y;
    return false;
}

double Point::getSumDistances(const Point &a,Point *points,int n)
{
    double sum=0;
    for(int j=0; j<n; j++)
    {
        double dist=Point::getDistance(points[j],a);
        sum+=dist;
    }
    return sum;
}

double Point::getTriangleArea(const Point &a,const Point &b,const Point &c)
{
    double A=getDistance(a, b);
    double B=getDistance(b, c);
    double C=getDistance(c, a);
    double p=(A+B+C)/2;
    return sqrt(p*(p-A)*(p-B)*(p-C));
}

void Point::Sort(Point *points, int n, Compare compare)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(compare(points[i],points[j]))
            {
                Swap(points[i],points[j]);
            }
        }
    }
}
