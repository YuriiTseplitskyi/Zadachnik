#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int getSign(int x);
int RootsCount(double a, double b, double c);
double Calc(double a,double b, char op);
double CircleS(double r);
int getDigitN(int k, int n);
bool IsPowerN(int k, int n);
bool IsPrime(int n);
int getDigitCount(int k);

const double PI = 3.14159251;

void proc16()
{
    int a,b;
    cout<<"A= ";cin >> a;
    cout<<"B= ";cin >> b;
    int sum=getSign(a)+getSign(b);
    cout<<sum<<endl;
}

//proc16
int getSign(int x)
{
    int k = 0;

    if(x<0)k=-1;
    if(x==0)k=0;
    if(x>0)k=1;

    return k;
}

void proc17()
{
    double a,b,c;
    cout<<"(A!=0)A= ";cin >> a;
    cout<<"B= ";cin >> b;
    cout<<"C= ";cin >> c;
    int n=RootsCount(a,b,c);
    cout<<n<<endl;
}

//proc17
int RootsCount(double a, double b, double c)
{
    double d = b * b - 4 * a * c;

    if(d>0)return 2;
    if(d==0)return 1;

    return 0;
}

//proc18

void proc18()
{
    double R;
    cout << "R= ";cin>>R;
    double n=CircleS(R);
    cout<<n<<endl;
}

double CircleS(double r)
{
    return  PI * r * r;
}

//proc19
double RingS(double R1, double R2)
{
    cout << "R1= ";cin>>R1;
    cout << "R2= ";cin>>R2;

    double s = PI * (R1 * R1 - R2 * R2);
    return s;
}

//proc20
double TriangleP(double a,double h)
{
    cout << "a= ";cin>>a;
    cout << "h= ";cin>>h;

    return (a / 2) * (a / 2) + h * h;
}

//proc21
int SumRange(int a,int b)
{
    int sum = 0;

    cout<<"A= ";cin >> a;
    cout<<"B= ";cin >> b;

    for (int i = a; i <= b;i++)
    {
        sum += i;
    }

    return sum;
}

//proc22
void proc22()
{
    double a,b;
    char op;
    cout<<"A= ";cin >> a;
    cout<<"B= ";cin >> b;
    cout <<"Op(+,-,*,/)= ";cin>>op;
    double result=Calc(a,b,op);
    cout<<result<<endl;
}
double Calc(double a,double b, char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;

        default:return 0;
    }
}

//proc23
int Quarter(int x,int y)
{
    if(x>0&&y>0) return 1;
    if(x<0&&y>0) return 2;
    if(x<0&&y<0) return 3;
    if(x>0&&y<0) return 4;

    return 0;
}

//proc24
bool isEven(int k)
{
    return k%2==0;
}

//proc25
bool IsSquare(int k)//!
{
    int x=0;
    while(x*x<k) x++;

    return x*x==k;
}

//proc26
void proc26()
{
    int k;
    cout << "K= ";cin>>k;
    bool IsPower5(int k);
    bool ok=IsPower5(k);
    cout<<ok<<endl;
}
bool IsPower5(int k)
{
    int x=1;
    while(x<k)
    {
        x=x*5;
    }

    return x==k;
}

//proc27
void proc27()
{
    int k, n;
    cout << "K= ";cin>>k;
    cout << "N= ";cin>>n;
    bool ok=IsPowerN(k, n);
    cout << ok << endl;
}

bool IsPowerN(int k, int n)
{

    while(k%n==0)
    {
        k /= n;
    }

    return k==1;
}

//proc28
void proc28()
{
    int n;
    cout << "N= ";cin>>n;
    bool ok = IsPrime(n);
    cout << ok << endl;
}

bool IsPrime(int n)//?
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

//proc29
void proc29()
{
    int k;
    cout << "K= ";cin>>k;
    int counter = getDigitCount(k);
    cout << counter << endl;
}

int getDigitCount(int k)
{
    if(k==0)return 1;
    int counter=0;
    while(k!=0)
    {
        counter++;
        k /= 10;
    }

    return counter;
}
//proc30
void proc30()
{
    int k, n;
    cout << "K= ";cin>>k;
    cout << "N= ";cin>>n;
    int m = getDigitN(k, n);
    cout << m << endl;
}

int getDigitN(int k,int n)
{
    for(int i=0;i<n;i++)
    {
        k=k/10;
    }
    return k%10;
}

int getDigitSum(int k)
{
    int sum=0;
    while(k!=0)
    {
        int d=k%10;
        sum=sum+d;
        k/=10;
    }
    return sum;
}

int getReverseInt(int k)
{
    int sum=0;
    while(k!=0)
    {
        int d=k%10;
        sum=sum*10+d;
        k/=10;
    }
    return sum;
}

bool IsPalindrom(int k)
{
    int i=0;
    int j=getDigitCount(k)-1;

    while(i<j)
    {
        int a=getDigitN(k,i);
        int b=getDigitN(k,j);
        if(a!=b)return false;
        i++;
        j--;
    }

    return true;
}

bool IsPalindrom1(int k)
{
    int q=getReverseInt(k);
    return k==q;
}

void proc31()
{
    int k;
    cout << "K= ";cin>>k;
    bool isPalindrom = IsPalindrom1(k);
    cout<<isPalindrom<<endl;
}

double Fact2(int n)
{
    double prod=1;
    if(n%2==0)
    {
        for(int i=2;i<=n;i+=2)
        {
            prod*=i;
        }
    }

    if(n%2!=0)
    {
        for(int i=1;i<=n;i+=2)
        {
            prod*=i;
        }
    }

    return prod;

}

double Fact21(int n)
{
    double prod=1;

    int p=1;
    if(n%2==0) p=2;

    for(int i=p;i<=n;i+=2)
    {
        prod*=i;
    }

    return prod;

}

void proc35()
{
    int k;
    cout << "K= ";cin>>k;
    double res=Fact2(k);
    cout<<res<<endl;
}


int Fib(int n)
{
    int f1 = 1;
    int f2 = 1;
    int f=0;

    while(f<n)
    {
        f = f2 + f1;
        f2 = f1;
        f1 = f;
    }

    return f;
}

void proc36()
{
    int n;
    cout << "N= ";cin>>n;
    int res=Fib(n);
    cout<<res<<endl;
}

double Power1(double a,double b)
{
    if(a<0||a==0) return 0;
    return exp(b * log(a));
}

void proc37()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;

    double res = Power1(a, b);
    cout << res << endl;
}

double Power2(double a,int n)
{
    double prod=1;

    if(n>0)
    {
        for (int i = 0; i < n; i++)
        {
            prod *= a;
        }
    }

    if(n<0)
    {
        for (int i = 0; i < abs(n); i++)
        {
            prod *= a;
        }

        prod = 1 / prod;
    }

    return prod;
}

void proc38()
{
    int a,n;
    cout << "A= ";cin>>a;
    cout << "N= ";cin>>n;

    int res = Power2(a, n);
    cout << res << endl;
}

double Power3(double a,double b)//!
{
    double frac=b-int(b);
    if(frac!=0)return Power1(a,b);
    return Power2(a,b);
}

void proc39()
{
    double a,n;
    cout << "A= ";cin>>a;
    cout << "N= ";cin>>n;

    double res = Power3(a, n);
    cout << res << endl;
}

double Exp1(double x,double e)
{
    double nom = 1;
    double den = 1;
    double exp = 0;
    double n=1;

    while(true)
    {
        double dod=nom/den;
        exp += dod;
        if(fabs(dod)<e) break;
        nom *= x;
        den *= n;
        n++;
    }

    return exp;
}

void proc40()
{
    double x,e;
    cout << "X= ";cin>>x;
    cout << "E= ";cin>>e;

    double res = Exp1(x, e);
    cout << res << endl;
    cout << exp(x) << endl;
}

double Sin(double x,double e)
{
    double SIN = 0;
    double nom = x ;
    double den = 1 ;
    double sign = 1;
    double n = 2;

    while(true)
    {
        double res = nom / den;
        SIN += res * sign;
        if(fabs(res)<e)break;
        nom *= x * x;
        den *= n * (n+1);
        n += 2;
        sign=-sign;
    }

    return SIN;
}

void proc41()
{
    double x,e;
    cout << "X= ";cin>>x;
    cout << "E= ";cin>>e;

    double res = Sin(x, e);
    cout << res << endl;
}

double Cos1(double x,double e)///!
{
    double COS = 0;
    double res = 1;
    double nom = 1 ;
    double den = 1 ;
    double sign = 1;
    double n = 1;

    while(abs(res)>e)
    {
        res += COS;
        COS += res * sign;
        nom *= x * x;
        den *= n * (n + 1);
        n += 2;
        sign = -sign;
    }

    return COS;
}

void proc42()///!
{
    double x,e;
    cout << "X= ";cin>>x;
    cout << "E= ";cin>>e;

    double res = Cos1(x, e);
    cout << res << endl;
}

double Ln1(double x,double e)
{
    double nom = x ;
    double den = 1 ;
    double ln = x;
    double sign = 1;
    double m = 1;

    while(ln>e)
    {
        ln += nom / den * sign;
        nom *= x;
        m++;
        den = m ;
        sign = -sign;
    }

    return ln;
}

void proc43()
{
    double x,e;
    cout << "X= ";cin>>x;
    cout << "E= ";cin>>e;

    double res = Ln1(x, e);
    cout << res << endl;
}

double Arctg1(double x,double e)
{
    double nom = x ;
    double den = 1 ;
    double Arctg = 0;
    double res;
    double sign = 1;
    double m = 1;

    while(den>e)
    {

        Arctg += nom / den * sign;
        nom *= x * x;
        m += 2;
        den = m ;
        sign = -sign;
    }
}

int getNOD(int a,int b)
{

    a = abs(a);
    b = abs(b);
    while(a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }

    return a;
}

int ReduceFraction(int nom,int den)
{
    nom = abs(nom);
    den = abs(den);
    while(nom!=den)
    {
        if(nom>den)
        {
            nom-=den;
        }
        else
        {
            den-=nom;
        }
    }

    return nom;
}

void proc47()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    cout << a << "/" << b << endl;
    int nom = a/getNOD(a, b);
    int den = b/getNOD(a, b);
    cout << nom << "/" << den << endl;
}

int getNOK(int a,int b)
{
    return a * (b / getNOD(a , b));
}

void proc48()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    int res = getNOK(a, b);
    cout << res << endl;
}

int getNOD3(int a,int b,int c)
{

    a = abs(a);
    b = abs(b);
    c = abs(b);
    
    while(a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }

    while(a!=c)
    {
        if(a>c)
        {
            a-=c;
        }
        else
        {
            c-=a;
        }
    }

    return a;
}

void proc49()
{
    int a, b, c;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    cout << "C= ";cin>>c;

    int res = getNOD3(a, b, c);
    cout << res<< endl;
}

double Leng(int xa,int ya,int xb,int yb)
{
    return abs(sqrt((xa - xb) * (xa - xb) + (ya - yb) * (xa - xb)));
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

    int main()
{
    cout.setf(ios::fixed);
    cout.precision(15);
    cout.setf(ios::boolalpha);

    proc40();

}
