#include <iostream>

using namespace std;

void bool1()
{
    int a;cin>>a;
    bool ok=a>0;
    cout<<ok<<endl;
}

void bool2()
{
    int a;cin>>a;
    bool ok=a%2!=0;
    cout<<ok<<endl;
}

void bool3()
{
    int a;cin>>a;
    bool ok=a%2==0;
    cout<<ok<<endl;
}

void bool4()
{
    int a;cin>>a;
    int b;cin>>b;
    bool ok=a>2&&b<=3;
    cout<<ok<<endl;
}

void bool5()
{
    int a;cin>>a;
    int b;cin>>b;
    bool ok=a>=0||b<-2;
    cout<<ok<<endl;
}

void bool6()
{
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;

    bool ok = a<b && b<c;
    cout<<ok<<endl;
}

void bool7()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;

    bool ok1 = a<b && b<c;
    bool ok2 = c<b && b<a;
    bool ok = ok1 || ok2;
    cout<<ok<<endl;
}

void bool8()
{
    int a;cin>>a;
    int b;cin>>b;
    bool ok=a%2!=0 && b%2!=0;
    cout<<ok<<endl;
}

void bool10()
{
    int a;cin>>a;
    int b;cin>>b;
    bool ok=(a%2!=0&&b%2==0)||(a%2==0&&b%2!=0);
    ok = a%2 != b%2;
    cout<<ok<<endl;
}

void bool11()
{
    int a;cin>>a;
    int b;cin>>b;
    bool ok=(a%2!=0&&b%2!=0)||(a%2==0&&b%2==0);
    ok = a%2 == b%2;
    cout<<ok<<endl;
}

void bool14()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;

    bool oka = a>0 && b<=0 && c<=0;
    bool okb = a<=0 && b>0 && c<=0;
    bool okc = a<=0 && b<=0 && c>0;
    bool ok = oka || okb || okc;
    cout<<ok<<endl;
}

void bool15()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;
    bool ok=(a>0&&b>0&&c<0)||(a>0&&b<0&&c>0)||(a<0&&b>0&&c>0);
    cout<<ok<<endl;
}

void bool16()
{
    int a;cin>>a;
    bool ok=(a%2==0)&&(10<=a && a<=99);
    cout<<ok<<endl;
}

void bool17()
{
    int a;cin>>a;
    bool ok=a%2!=0&&(100<=a && a<=999);
    cout<<ok<<endl;
}

void bool20()
{
    int a;cin>>a;
    int a1=a/1%10;
    int a2=a/10%10;
    int a3=a/100%10;
    bool ok=(a1!=a2&&a1!=a3&&a2!=a3);
    cout<<ok<<endl;
}

void bool21()
{
    int a;cin>>a;
    int a1=a/1%10;
    int a2=a/10%10;
    int a3=a/100%10;
    bool ok=(a3<a2&&a2<a1);
    cout<<ok<<endl;
}

void bool23()
{
    int a;cin>>a;
    int a1=a/1%10;
    int a2=a/10%10;
    int a3=a/100%10;
    int a4 = a/1000%10;
    bool ok = a1 == a4 && a2 == a3;
    cout<<ok<<endl;
}

void bool24()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;
    bool ok=(b*b-4*a*c)>=0;
    cout<<ok<<endl;
}

void bool27()
{
    int x;cin>>x;
    int y;cin>>y;
    bool ok=x<0&&y!=0;
    cout<<ok<<endl;
}

void bool28()
{
    int x;cin>>x;
    int y;cin>>y;
    bool ok = x*y>0;
    cout<<ok<<endl;
}

void bool29()
{
    int x;cin>>x;
    int y;cin>>y;
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok= x1 < x && x < x2 && y1 < y && y2 < y;
    cout<<ok<<endl;
}

void bool30()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;
    bool ok=(a==b)&&(a==c);
    cout<<ok<<endl;
}

void bool32()
{
    int a;cin>>a;
    int b;cin>>b;
    int c;cin>>c;
    bool ok=(a*a+b*b==c*c)||(a*a+c*c==b*b)||(c*c+b*b==a*a);
    cout<<ok<<endl;
}

void bool34()
{
    int x;cin>>x;
    int y;cin>>y;
    //bool ok=(x%2==0&&y%2!=0)||(x%2!=0&&y%2==0);
    bool ok = (x+y)%2 !=0;
    cout<<ok<<endl;
}

void bool35()
{
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok = (x1+y1)%2 == (x2+y2)%2;
    cout<<ok<<endl;
}

void bool36()
{
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok = x1==x2 || y1==y2;//����
    cout<<ok<<endl;
}

void bool37()
{
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok = abs(x1-x2)<2 && abs(y1-y2)<2;
    cout<<ok<<endl;
}

void bool38()
{
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok= abs(x1-x2) == abs(y1-y2);//����
    cout<<ok<<endl;
}

void bool39()
{
    int x1;cin>>x1;
    int y1;cin>>y1;
    int x2;cin>>x2;
    int y2;cin>>y2;

    bool ok1 = x1==x2 || y1==y2;
    bool ok2= abs(x1-x2) == abs(y1-y2);
    bool ok = ok1 || ok2;
    cout<<ok<<endl;
}

/*bool ok1= abs(x1-x2)==2&&abs(y1-y2)==1;
bool ok2= abs(x1-x2)==1&&abs(y1-y2)==2;
bool ok=ok1||ok2;*/


int main()
{

    cout.setf(ios::boolalpha);

    //bool1();
    //bool2();
    //bool3();
    //bool4();
    //bool5();
    //bool6();
    //bool7();
    //bool8();
    //bool10();
    //bool11();
    //bool15();
    //bool16();
    //bool17();
    //bool20();
    //bool22();
    //bool24();
    //bool27();
    //bool29();
    //bool30();
    //bool32();
    //bool34();
    //bool38();
    return 0;
}
