#include <iostream>
#include <cmath>

using namespace std;

void if1()
{
    int a; cin>>a;
    if(a>0)
    {
        a++;
    }
    cout<<a<<endl;
}

void if2()
{
    int a; cin>>a;
    if(a>0)
    {
        a++;
    }
    else
    {
        a=a-2;
    }
    cout<<a<<endl;
}

void if3()
{
    int a; cin>>a;
    if(a>0)
    {
        a++;
    }
    else if(a<0)
    {
        a=a-2;
    }
    else
    {
        a=10;
    }
    cout<<a<<endl;
}
/////if4-5
void if4()
{
    int a; cin>>a;
    int b; cin>>b;
    int c; cin>>c;
    int counter=0;

    if(a>0)counter++;
    if(b>0)counter++;
    if(c>0)counter++;

    cout<<counter<<endl;
    cout<<3-counter<<endl;
}

void if6()
{
     int a; cin>>a;
     int b; cin>>b;

     int max=a;
     if(b>a)max=b;

     cout<<max<<endl;

     /*if(a>b)
     {
         cout<<a<<endl;
     }
     else if(a<b)
    {
        cout<<b<<endl;
    }
    else
    {
        cout<<"Equal"<<endl;
    }*/
}

void if7()
{
     int a; cin>>a;
     int b; cin>>b;
     if(a>b)
     {
         cout<<1<<endl;
     }
     else if(a<b)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<"Equal"<<endl;
    }
}

void if8()
{
     int a; cin>>a;
     int b; cin>>b;

     int max=b;
     int min=a;

     if(a>b)
     {
        max=a;
        min=b;
     }

     cout<<max<<endl;
     cout<<min<<endl;
}

void if9()
{
     double a; cin>>a;
     double b; cin>>b;

     if(a>b)
     {
         swap(a,b);
     }

     cout<<"a="<<a<<endl;
     cout<<"b="<<b<<endl;

     /*if(a<b)
     {
         cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
     }
     else if(a>b)
    {
        int c=a;
        a=b;
        b=c;
        cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
    }
    else
    {
        cout<<"Equal"<<endl;
    }*/
}

void if10()
{
    int a;
    cin>>a;
    int b;
    cin>>b;

    if(a!=b)
    {
        int d=a+b;
        a=d;
        b=d;
    }
    else
    {
        a=0;
        b=0;
    }

    cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
}

void if11()
{
     int a; cin>>a;
     int b; cin>>b;

     if(a!=b)
    {
        int max=a;
        if(b>a)max=b;
        a=max;
        b=max;
    }
    else
    {
        a=0;
        b=0;
    }

    cout<<"a="<<a<<"\t"<<"b="<<b<<endl;

}

void if12()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int min=a;
     if(b<min) min=b;
     if(c<min) min=c;

     cout<<min<<endl;
}

void if13()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int mid=a;
     if(a<b&&b<c||c<b&&b<a) mid=b;
     if(a<c&&c<b||b<c&&c<a) mid=c;

     cout<<mid<<endl;
}

void if13a()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int min=a;
     if(b<min) min=b;
     if(c<min) min=c;

     int max=a;
     if(b>max) max=b;
     if(c>max) max=c;

     int mid=(a+b+c)-min-max;
     cout<<mid<<endl;
}

void if14()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int min=a;
     if(b<min) min=b;
     if(c<min) min=c;

     int max=a;
     if(b>max) max=b;
     if(c>max) max=c;

     cout<<min<<endl;
     cout<<max<<endl;


     /*if(a>b&&a>c)
     {
         cout<<a<<endl;
     }
     else if(b>a&&b>c)
     {
         cout<<b<<endl;
     }
     else
     {
         cout<<c<<endl;
     }

     if(a<b&&a<c)
     {
         cout<<a<<endl;
     }
     else if(b<a&&b<c)
     {
         cout<<b<<endl;
     }
     else
     {
         cout<<c<<endl;
     }*/
}

void if15()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int min=a;
     if(b<min) min=b;
     if(c<min) min=c;

     int sum=a+b+c-min;

     cout<<sum<<endl;

     /*if(a>b&&b>c)
     {
         cout<<a+b<<endl;
     }
     else if(a>b&&c>b)
     {
         cout<<a+c<<endl;
     }
     else
     {
         cout<<b+c<<endl;
     }*/
}

void if16()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     if(a<b&&b<c)
     {
         a=a+a;
         b+=b;
         c*=2;
     }
     else
     {
         a=-a;
         b=-b;
         c=-c;
     }

     cout<<"a="<<a<<"\t";
     cout<<"b="<<b<<"\t";
     cout<<"c="<<c<<endl;
}

void if17()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     if(a<b&&b<c||a>b&&b>c)
     {
         cout<<"a="<<a*2<<"\t"<<"b="<<b*2<<"\t"<<"c="<<c*2<<endl;
     }
     else
     {
         cout<<"a="<<-1*a<<"\t"<<"b="<<-1*b<<"\t"<<"c="<<-1*c<<endl;
     }
}

void if18()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;

     int num=1;
     if(a==c)num=2;
     if(a==b)num=3;

     cout<<num<<endl;

}

void if19()
{
     int a; cin>>a;
     int b; cin>>b;
     int c; cin>>c;
     int d; cin>>d;

     if(b==c&&c==d)
     {
         cout<<1<<endl;
     }
     else if(a==c&&c==d)
     {
         cout<<2<<endl;
     }
      else if(a==b&&b==d)
     {
         cout<<3<<endl;
     }
     else
     {
         cout<<4<<endl;
     }
}

void if20()
{
     double a; cin>>a;
     double b; cin>>b;
     double c; cin>>c;

     int dist1=abs(a-b);
     int dist2=abs(a-c);

     cout<<"dist1="<<dist1<<endl;
     cout<<"dist2="<<dist2<<endl;

     if(dist1>dist2)
     {
         cout<<c<<"\t"<<dist2<<endl;
     }
     else if(dist1<dist2)
     {
         cout<<b<<"\t"<<dist1<<endl;
     }
     else
     {
         cout<<"Equal"<<endl;
     }
}

void if21()
{
     int x; cin>>x;
     int y; cin>>y;

     int res=0;
     if(x==0&&y==0) res=1;
     if(x!=0&&y==0) res=2;
     if(y!=0&&x==0) res=3;

     cout<<res<<endl;

}

void if22()
{
     int x; cin>>x;
     int y; cin>>y;

     if(x>0&&y>0)
     {
         cout<<1<<endl;
     }
     if(x<0&&y>0)
     {
         cout<<2<<endl;
     }
     if(x<0&&y<0)
     {
         cout<<3<<endl;
     }
     if(x>0&&y<0)
     {
         cout<<4<<endl;
     }

}

void if23()
{
     int x1; cin>>x1;
     int y1; cin>>y1;

     int x2; cin>>x2;
     int y2; cin>>y2;

     int x3; cin>>x3;
     int y3; cin>>y3;

     int x4=x1;
     if(x1==x3) x4=x2;
     if(x1==x2) x4=x3;

     int y4=y1;
     if(y1==y3) y4=y2;
     if(y1==y2) y4=y3;

     cout<<x4<<endl;
     cout<<y4<<endl;
}

void if24()
{
    double x; cin>>x;

    double f=6-x;
    if(x>0) f=2*sin(x);

    cout<<f<<endl;
}

void if25()
{
    double x; cin>>x;
    if(x<-2||x>2)
    {
        double res1=2*x;
        cout<<res1<<endl;
    }
    else
    {
        double res2=-3*x;
        cout<<res2<<endl;
    }
}

void if26()
{
    double x; cin>>x;

    double f=x*x;
    if(x<=0) f=-x;
    if(x>=2) f=4;

    cout<<f<<endl;

}

void if27()
{
    double x; cin>>x;

    double f=0;
    if(x>=0)
    {
        int y=x;
        if(y%2==0) f=1;
        if(y%2!=0) f=-1;
    }
    cout<<f<<endl;
}

void if28()
{
    int year; cin>>year;
    if(year%4==0)
    {
        cout<<366<<endl;
    }
    else if(year%100==0&&year%400!=0)
    {
        cout<<365<<endl;
    }
    else
    {
        cout<<365<<endl;
    }
}

void if29()
{
    int x; cin>>x;
    if(x>0)
    {
        cout<<"�������"<<endl;
    }
    else if(x<0)
    {
        cout<<"³�'����"<<endl;
    }
    else
    {
        cout<<"�� ����� 0"<<endl;
        return;
    }

    if(x%2==0)
    {
        cout<<"�����"<<endl;
    }
    else
    {
        cout<<"�������"<<endl;
    }

    if(abs(x/100%10)>0)
    {
        cout<<"T�����������"<<endl;
    }
    else if(abs(x/10%10)>0)
    {
        cout<<"�����������"<<endl;
    }
    else
    {
        cout<<"Трьожзначне"<<endl;
    }
}

int main()
{
     
    //if1();
    //if2();
    //if3();
    //if4();
    //if6();
    //if7();
    //if8();
    //if9();
    //if10();
    //if11();
    //if12();
    //if13();
    //if14();
    //if15();
    //if16();
    //if17();
    //if18();
    //if19();
    //if20();
    //if21();
    //if22();
    //if23();
    //if24();
    //if25();
    //if26();
    //if27();
    //if28();
    //if29();

    return 0;
}
