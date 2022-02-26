#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

using namespace std;

void Mean(double x,double y,double *AMean,double *GMean)
{
    *AMean=(x+y)/2;
    *GMean=sqrt(x*y);
}

void proc3()
{
    double a,b;
    cout<<"a= ";cin>>a;
    cout<<"b= ";cin>>b;

    double AMean,GMean;
    Mean(a,b,&AMean,&GMean);

    cout<<"AMean= "<<AMean<<endl;
    cout<<"GMean= "<<GMean<<endl;
}

void TrianglePS(double a, double *s,double *p)
{
    *p = 3 * a;
    *s = a * a * sqrt(3) / 4;
}

void TrianglePS1(double a, double &s,double &p)
{
    p = 3 * a;
    s = a * a * sqrt(3) / 4;
}

void proc4()
{
    double a;
    cout<<"a= ";cin>>a;
    double p, s;
    TrianglePS(a,&s,&p);

    cout << "P= " << p << endl;
    cout << "S= " << s << endl;

    double p1, s1;
    TrianglePS1(a,s,p);

    cout << "P= " << p1 << endl;
    cout << "S= " << s1 << endl;

}

void RectPS(double x1,double y1,double x2,double y2,double *p,double *s)
{
    double a=fabs(x2-x1);
    double b=fabs(y2-y1);

    *p= (a+b) * 2;
    *s= a*b;
}

void RectPS1(double x1,double y1,double x2,double y2,double &p,double &s)
{
    p= (abs(x2-x1) + abs(y2-y1)) * 2;
    s= abs(x2-x1) * abs(y2-y1);
}

void proc5()
{
    double x1, y1, x2, y2;
    cout<<"x1= ";cin>>x1;
    cout<<"x2= ";cin>>x2;
    cout<<"y1= ";cin>>y1;
    cout<<"y2= ";cin>>y2;

    double p, s;
    RectPS(x1, y1, x2, y2,&p,&s);

    cout << "P= " << p << endl;
    cout << "S= " << s << endl;

    double p1, s1;
    RectPS1(x1, y1, x2, y2,p1,s1);

    cout << "P= " << p1 << endl;
    cout << "S= " << s1 << endl;

}


void DigitCountSum (int digit, int *count, int *sum)
{
    *count=0;
    *sum=0;

    while(digit!=0)
    {
        *sum+=digit%10;
        *count++;
        digit/=10;
    }
}

int DigitCount (int digit)
{
    if(digit==0)return 1;
    int counter=0;

    while(digit!=0)
    {
        counter++;
        digit /= 10;
    }

    return counter;
}

void proc6()
{
    int a;
    cout<<"a= ";cin>>a;
    int sum,count;
    DigitCountSum(a,&count,&sum);

    cout << "Sum= " << sum << endl;
    cout << "Count= " << count << endl;
}

void InvertDigits(int &k)
{
    int s=0;
    while(k!=0)
    {
        int d=k%10;
        s=s*10+d;
        k=k/10;
    }

    k=s;
}

void proc7()
{
    int a;
    cout<<"a= ";cin>>a;
    InvertDigits(a);

    cout<<"Invert Digit= "<<a<<endl;
}

void AddRightDigit(int d,int *k)
{
    int s = *k * 10 + d;
    *k = s;
}

void proc8()
{
    int a,d;
    cout<<"a= ";cin>>a;
    cout<<"d= ";cin>>d;

    AddRightDigit(d,&a);

    cout<<"Digit= "<<a<<endl;
}

void AddLeftDigit(int d,int *k)
{
//    int mult = 1;
//    int n=DigitCount(*k);
//    for (int i = 0; i <n; i++)
//    {
//        mult *= 10;
//    }
//
//    int s = *k + mult * d;
//    *k = s;

    InvertDigits(*k);
    AddRightDigit(d,k);
    InvertDigits(*k);
}

void proc9()
{
    int a,d;
    cout<<"a= ";cin>>a;
    cout<<"d= ";cin>>d;

    AddLeftDigit(d,&a);

    cout << "Digit= " << a << endl;
}

template <class T>
void Swap(T *x,T *y)
{
    T z = *x;
    *x = *y;
    *y = z;
}

void proc10()
{
    double x,y;
    cout<<"x= ";cin>>x;
    cout<<"y= ";cin>>y;

    Swap<double>(&x, &y);

    cout << "X= " << x << endl;
    cout << "Y= " << y << endl;
}

void MinMax(double *x,double *y)
{
    if(*x>*y)
    {
        Swap<double>(x,y);
    }
}

void proc11()
{
    double x,y;
    cout<<"x= ";cin>>x;
    cout<<"y= ";cin>>y;

    MinMax(&x, &y);

    cout << "min X= " << x << endl;
    cout << "max Y= " << y << endl;
}

void SortInc3(double *a,double *b,double *c)
{
//    if(*b > *c)
//        {
//            double k = *b;
//            *b = *c;
//            *c = k;
//        }
//    if(*a > *c)
//        {
//            double k = *a;
//            *a = *c;
//            *c = k;
//        }
//    if(*a > *b)
//        {
//            double k = *a;
//            *a = *b;
//            *b = k;
//        }

    MinMax(a,b);
    MinMax(b,c);
    MinMax(a,b);
}

void proc12()
{
    double a,b,c;
    cout<<"a= ";cin>>a;
    cout<<"b= ";cin>>b;
    cout<<"c= ";cin>>c;

    SortInc3(&a,&b,&c);

    cout << "A= " << a << endl;
    cout << "B= " << b << endl;
    cout << "C= " << c << endl;
}


void ShiftRight(double *a,double *b,double *c)
{
    double k = *a;
    *a = *b;
    *b = *c;
    *c = k;
}

void proc14()
{
    double a,b,c;
    cout<<"a= ";cin>>a;
    cout<<"b= ";cin>>b;
    cout<<"c= ";cin>>c;

    SortInc3(&a,&b,&c);

    cout << "A= " << a << endl;
    cout << "B= " << b << endl;
    cout << "C= " << c << endl;
}

void ShiftLeft(double *a,double *b,double *c)
{
    double k=*c;
    *c = *a;
    *a = *b;
    *b = k;
}

void proc15()
{
    double a,b,c;
    cout<<"a= ";cin>>a;
    cout<<"b= ";cin>>b;
    cout<<"c= ";cin>>c;

    ShiftLeft(&a,&b,&c);

    cout << "A= " << a << endl;
    cout << "B= " << b << endl;
    cout << "C= " << c << endl;
}

void TimeToHMS(int t, int &h,int &m,int &s)
{
    h=t/3600;
    int rest=t%3600;
    m=rest/60;
    s=rest%60;
}

void proc50()
{
    int t;
    cout<<"t= ";cin>>t;

    int h,m,s;
    TimeToHMS(t,h,m,s);

    printf("%02d:%02d:%02d\n",h,m,s);

    cout.fill('0');
    cout<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;

    cout << "H= " << h << endl;
    cout << "M= " << m << endl;
    cout << "S= " << s << endl;
}

bool isYearLeap(int year)
{
    int days=365;
    if(year%4==0)
    {
        days=366;
        if(year%100==0&&year%400!=0)
        {
            days=365;
        }
    }
    return days==366;
}

int getMonthDays(int month, int year)
{
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(isYearLeap(year))days[1]=29;
    return days[month-1];
}

void PrevDate(int &d,int &m,int &y)
{
    if(d>1)
    {
        d--;
    }
    else
    {
        m--;
        if (m == 0)
        {
            m = 12;
            y--;
        }
        d = getMonthDays(m, y);
    }

}

void PrevDate1(int *d,int *m,int *y)
{
    if(*d>1)
    {
        //(*d)--;
        *d = *d - 1;
    }
    else
    {
        (*m)--;
        if (*m == 0)
        {
            *m = 12;
            (*y)--;
        }
        *d = getMonthDays(*m, *y);
    }

}

void proc54()
{
    int d, m, y;
    cout << "Day= " ; cin>> d;
    cout << "Month= " ; cin>> m;
    cout << "Year= " ; cin>> y;

    PrevDate1(&d, &m, &y);

    cout << "Day= " << d << endl;
    cout << "Month= " << m << endl;
    cout << "Year= " << y << endl;
}

void NextDate(int &D,int &M,int &Y)
{

    D++;
    switch(M)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            switch(D)
            {
                case 32: D = 1; M++; Y++; break;
            }

        case 4:
        case 6:
        case 9:
        case 11:
            switch(D)
            {
                case 31: D = 1; M++; break;
            }

        case 2:
        switch(D)
        {
            case 29: D = 1; M++; break;
        }

    }

    switch (M)
    {
        case 13:M = 1; D = 1; break;
    }
}

void NextDate1(int &d,int &m,int &y)
{
    int N=getMonthDays(m,y);
    if(d<N)
    {
        d++;
    }
    else
    {
        d=1;
        m++;
        if(m==13)
        {
            y++;
            m=1;
        }
    }
}

void proc55()
{
    int d, m, y;
    cout << "Day= " ; cin>> d;
    cout << "Month= " ; cin>> m;
    cout << "Year= " ; cin>> y;

    NextDate1(d, m, y);

    cout << "Day= " << d << endl;
    cout << "Month= " << m << endl;
    cout << "Year= " << y << endl;
}

double Leng(double xa,double ya,double xb,double yb)
{
    double dx= xa - xb;
    double dy= ya - yb;

    return sqrt( dx*dx + dy*dy );
}

double Perim(int xa,int ya,int xb,int yb,int xc,int yc)
{
    double AB = Leng(xa,  ya,  xb,  yb);
    double AC = Leng(xa,  ya,  xc,  yc);
    double BC = Leng(xb,  yb,  xc,  yc);

    return AB + AC + BC;
}

double Area(int xa,int ya,int xb,int yb,int xc,int yc)
{
    double AB = Leng(xa,  ya,  xb,  yb);
    double AC = Leng(xa,  ya,  xc,  yc);
    double BC = Leng(xb,  yb,  xc,  yc);
    double p = Perim(xa, ya, xb, yb, xc, yc)/2;

    return sqrt(p*(p-AB)*(p-AC)*(p-BC));
}

double Dist(double xp,double yp,double xa,double ya,double xb,double yb)
{
    double S = Area(xp, yp, xa, ya, xb, yb);
    double AB = Leng(xa, ya, xb, yb);

    return 2 * S / AB;
}

void MinMax1()
{
    int from=-5;
    int to=15;
    int n;
    cout<<"N= ";cin>>n;

    double min;
    double max;
    for(int i=0;i<n;i++)
    {
        //int x=-5+rand()%16;//[-5...10]
        double x=(from*100+rand()%((to-from)*100))/100.0;
        cout<<x<<endl;

        if(i==0)
        {
            min=x;
            max=x;
        }
        if(i>0)
        {
            if(x<min)min=x;
            if(x>max)max=x;
        }
    }

    cout<<"Min= "<<min<<endl;
    cout<<"Max= "<<max<<endl;
}

void MinMax2()
{
    int from=1;
    int to=15;
    int n;
    cout<<"N= ";cin>>n;

    double min;
    double max;
    for(int i=0;i<n;i++)
    {
        //int x=-5+rand()%16;//[-5...10]
        double a=(from*100+rand()%((to-from)*100))/100.0;
        double b=(from*100+rand()%((to-from)*100))/100.0;
        double s=a*b;
        cout<<a<<" "<<b<<" "<<s<<endl;

        if(i==0)
        {
            min=s;
            max=s;
        }
        if(i>0)
        {
            if(s<min)min=s;
            if(s>max)max=s;
        }
    }

    cout<<"Min= "<<min<<endl;
    cout<<"Max= "<<max<<endl;
}

int main()
{
    srand(time(NULL));
    MinMax2();
    return 0;
}
