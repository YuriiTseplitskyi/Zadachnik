#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int fact(int n);
const double PI=3.1415926;

void for1()
{
    int k;int n;
    cout <<"K= ";cin >> k;
    cout <<"N= ";cin >> n;

    for (int i = 0; i < n;i++)
    {
        cout << k << endl;
    }
}

void for2()
{
    int a, b;

    cout<<"A= "; cin>>a;
    cout<<"B= "; cin>>b;

    int n=0;
    for(int i=a;i<=b;i++)
    {
        cout<<i<<" ";
        n++;
    }

    cout<<endl;
    cout<<n<<endl;
}

void for3()
{
    int a, b;

    cout<<"A= "; cin>>a;
    cout<<"B= "; cin>>b;

    int n=0;
    for(int i=b-1;i>a;i--)
    {
        cout<<i<<" ";
        n++;
    }

    cout<<endl;
    cout<<n<<endl;
}

void for4()
{
    double price;
    cout << "Price= "; cin>>price;

    int amount = 1;
    for(int i=0; i<10; i++)
    {
        double cost = amount * price;
        cout << "amount= " << amount << "kg" << " ";
        cout << "cost= "<< cost << "hrn" << " " << endl;
        amount += 1;
    }
}

void for5()
{
    double price;
    cout<<"price= "; cin>>price;

    cout.setf(ios::fixed);
    double amount=0.1;
    for(int i=0;i<10;i++)
    {
        double cost=amount * price;
        cout.precision(245);
        cout<<amount<<"kg ";
        cout.precision(2);
        cout<<setw(5)<<cost<<"hrn "<<endl;
        amount+=0.1;
    }
}

void for6()
{
    double price;
    cout << "Price= "; cin>>price;

    double amount = 1.2;
    for(int i=0; i<5; i++)
    {
        double cost = amount * price;
        cout << "amount= " << amount << "kg" << " ";
        cout << "cost= "<< cost << "hrn" << " " << endl;
        amount += 0.2;
    }
}

void for7()
{
    int a, b;

    cout<<"A= "; cin>>a;
    cout<<"B= "; cin>>b;

    int sum = 0;
    for (int i = a; i <= b;i++)
    {
        sum+=i;
    }

     cout << sum << endl;
}

void for8()
{
    int a, b;

    cout<<"A= "; cin>>a;
    cout<<"B= "; cin>>b;

    int sum = 1;
    for (int i = a; i <= b;i++)
    {
        sum*=i;
    }

    cout << sum << endl;
}

void for9()
{
     int a, b;

    cout<<"A= "; cin>>a;
    cout<<"B= "; cin>>b;

    int sum = 0;
    for (int i = a; i <= b;i++)
    {
        sum+=i*i;
    }

    cout << sum << endl;
}

void for10()
{
    int n;
    cout << "N="; cin>>n;

    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0 / (double)i;
    }

    cout << sum << endl;
}

void for11()
{
    int n;
    cout << "N= "; cin>>n;

    int sum = 0;
    for (int i = 0; i <= n;i++)
    {
        sum += (n + i)*(n + i);
    }

    cout << sum << endl;
}

void for12()
{
    int n;
    cout << "N= "; cin>>n;

    double  res = 1;
    double m=1.1;
    for (int i = 0; i < n; i++)
    {
        res *= m;
        m+=0.1;
    }

    cout << res << endl;
}

void for13()
{
    int n;
    cout << "N= "; cin>>n;

    double sum = 0;
    double m=1.1;
    double sign=1;
    for (int i = 1; i <= n; i++)
    {
        sum +=m*sign;
        m+=0.1;
        sign=-sign;
    }

    cout << sum << endl;
}

void for14()
{
    int n;
    cout << "N= "; cin>>n;

    int k = 1;
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << i << "^2 = " << sum << endl;
        sum += k;
        k+=2;
    }

}

void for15()
{
    double a;
    cout << "A= "; cin>>a;
    int n;
    cout << "N= "; cin>>n;

    double sum = 1;
    for(int i=0; i<n; i++)
    {
        sum *= a;
    }

    cout << sum << endl;

}

void for16()
{
    double a;
    cout << "A= "; cin>>a;
    int n;
    cout << "N= "; cin>>n;

    double prod = 1;
    for(int i=0; i<=n; i++)
    {
        cout << a << "^"<< i << " = " << prod << endl;
        prod *= a;
    }
}

void for17()
{
    double a;
    cout << "A= "; cin>>a;
    int n;
    cout << "N= "; cin>>n;

    double prod = 1;
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        cout << a << "^"<< i << " = " << prod << endl;
        sum+=prod;
        prod *= a;
    }
    cout << sum << endl;
}

void for18()
{
    double a;
    cout << "A= "; cin>>a;
    int n;
    cout << "N= "; cin>>n;

    double prod = 1;
    double sum=0;
    double sign=1;
    for(int i=0; i<=n; i++)
    {
        cout << a << "^"<< i << " = " << prod << endl;
        sum+=prod*sign;
        prod *= a;
        sign=-sign;
    }
    cout << sum << endl;
}

void for19()
{
    int n;
    cout << "N= "; cin>>n;

    int sum1 = 1;
    for (int i = 1; i <= n; i++)
    {
        sum1 *= i;
    }

    cout << sum1 << endl;
}

void for20()
{
    int n;
    cout << "N= "; cin>>n;

    int fact = 1;
    int sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum2 += fact;
        fact *= i;
    }
    cout << sum2 << endl;
}

void for21()
{
    int n;
    cout << "N= "; cin>>n;

    double sum1 = 1;
    double sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum2 += 1.0/sum1;
        sum1 *= i;
    }
    cout.precision(10);
    cout << sum2 << endl;
    cout << exp(1) << endl;
}

void for22()
{
    double x;
    cout << "X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double nom = 1;
    double den = 1;
    double sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += nom / den;
        nom *= x;
        den *= i;
    }

    cout << sum << endl;
    cout << exp(x) << endl;
}

int fact(int n)
{
    if(n==0)   return 0;
    if(n==1)   return 1;

    return n * (fact(n - 1));
}

void for23()
{
    double x;
    cout << "X= "; cin>>x;
    while(x>2*PI)x-=2*PI;
    while(x<0)x+=2*PI;

    int n;
    cout << "N= "; cin>>n;

    double nom = x ;
    double den = 1 ;
    double sum = 0;
    double sign = 1;
    double m = 2;

    for (int i = 1; i <= n; i++)
    {
        sum += nom/den * sign;
        cout << sum << endl;
        nom *= x * x;
        den *= m * (m+1);
        m += 2;
        sign=-sign;
    }

    cout << sum << endl;
    cout << sin(x) << endl;
}

void for24()
{
    double x;
    cout << "X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double nom = 1 ;
    double den = 1 ;
    double sum = 0;
    double sign = 1;
    double m = 1;

    for (int i = 1; i <= n; i++)
    {
        sum += nom / den * sign;
        nom *= x * x;
        den *= m * (m + 1);
        m += 2;
        sign = -sign;
    }

    cout << sum << endl;
    cout << cos(x) << endl;
    
}

void for25()
{
    double x;
    cout << "(|X|<1) X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double nom = x ;
    double den = 1 ;
    double sum = 0;
    double sign = 1;
    double m = 1;

    for (int i = 1; i <= n; i++)
    {
        sum += nom / den * sign;
        nom *= x;
        m++;
        den = m ;
        sign = -sign;
    }

    cout << sum << endl;
    cout << log(1+x) << endl;
    
}

void for26()
{
    double x;
    cout << "(|X|<1) X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double nom = x ;
    double den = 1 ;
    double sum = 0;
    double sign = 1;
    double m = 1;

    for (int i = 1; i <= n; i++)
    {
        sum += nom / den * sign;
        nom *= x * x;
        m += 2;
        den = m ;
        sign = -sign;
    }

    cout << sum << endl;
    cout << atan(x) << endl;
}

void for27()
{
    double x;
    cout << "(|X|<1) X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double nom = x ;
    double nom1 = 1 ;
    double m = 1;
    double den = 1;
    double k = 1;
    double sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += nom / den ;
        nom1 *= m;
        nom *= nom1 * x * x;
        m += 2;
        den = 2 * (2*k) * (2*k + 1);
        k++;
    }

    cout << sum << endl;
    cout << asin(x) << endl;
}

void for28()
{
    double x;
    cout << "X= "; cin>>x;
    int n;
    cout << "N= "; cin>>n;

    double sum1 = 1;
    double sum2 = 1;
    double sum3 = 1;

    for (int i = 1; i < n; i++)
    {
        sum1 *= ((-1) * x) * (2 * i - 3);
        sum2 *= (2 * i);
        sum3 += sum1 / sum2;
    }

    cout << sum3 << endl;
}
void for29()
{
    double a,b;
    cout << "A= "; cin>>a;
    cout << "B= "; cin>>b;

    int n;
    cout << "N= "; cin>>n;

    double h = (abs(a - b)) / n;
    cout << "H= " << h << endl;

    double res;

    for (int i = 0; res < b;i++)
    {
        res = a + i * h;
        cout << res << endl;
    }

}

void for30()
{

    double a,b;
    cout << "A= "; cin>>a;
    cout << "B= "; cin>>b;

    int n;
    cout << "N= "; cin>>n;

    double h = (abs(a - b)) / n;
    cout << "H= " << h << endl<<endl;

    double rez1;
    double rez2;

    for (int i = 0; rez1 < b;i++)
    {
        rez1 = a + i * h;
        rez2 = 1 - sin(rez1);
        cout <<"Res1= "<< rez1 << "   ";
        cout <<setw(5)<<"F(Res1)= "<< rez2 << endl;
    }
}

void for31()
{
    int n;
    cout << "N= "; cin>>n;

    double a = 2;

    for (int i = 1; i <= n;i++)
    {
        a = 2 + 1 / a;
        cout << "A"<< i << "= "<< a << endl;
    }
}

void for32()
{
    int n;
    cout << "N= "; cin>>n;

    double a = 1;

    for (int i = 1; i <= n;i++)
    {
        a = (a + 1) / i;
        cout << "A"<< i << "= "<< a << endl;
    }
}

void for33()
{
    int n;
    cout << "N= "; cin>>n;

    int f;
    int f1 = 1;
    int f2 = 1;
    cout << "F"<< 1 << "= " << f1 << endl;
    cout << "F"<< 2 << "= " << f2 << endl;

    for (int i = 3; i <= n; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        cout << "F"<< i << "= " << f << endl;
    }
}

void for34()
{
    int n;
    cout << "N= "; cin>>n;

    double a;
    double a1 = 1;
    double a2 = 2;
    cout << "A"<< 1 << "= " << a1 << endl;
    cout << "A"<< 2 << "= " << a2 << endl;

    for (int i = 3; i <= n; i++)
    {
        a = (a1 + 2*a2)/3;
        a1 = a2;
        a2 = a;
        cout << "A"<< i << "= " << a << endl;
    }
}

void for35()
{
    int n;
    cout << "N= "; cin>>n;

    double a;
    double a1 = 1;
    double a2 = 2;
    double a3 = 3;
    cout << "A"<< 1 << "= " << a1 << endl;
    cout << "A"<< 2 << "= " << a2 << endl;
    cout << "A"<< 3 << "= " << a3 << endl;

    for (int i = 4; i <= n; i++)
    {
        a = a3 + a2 - 2 * a1;
        a1 = a2;
        a2 = a3;
        a3=a;
        cout << "A"<< i << "= " << a << endl;
    }
}

void for37()
{
    int n,k;
    cout << "N= "; cin>>n;
    cout << "K= "; cin>>k;

    double res=0;
    for (int i = 1; i <= n;i++)
    {
        double prod=1;
        for(int j=0;j<i;j++)
        {
            prod *=i;
        }
        res += prod;
    }

    cout << "Res= " << res << endl;
}

void for36()
{
    int n,k;
    cout << "N= "; cin>>n;
    cout << "K= "; cin>>k;

    double res=0;
    for (int i = 1; i <= n;i++)
    {
        double prod=1;
        for(int j=0;j<k;j++)
        {
            prod *=i;
        }
        res += prod;
    }

    cout << "Res= " << res << endl;
}

void for38()
{
    int n;
    cout << "N= "; cin>>n;

    double res=0;
    int k=n;
    for (int i = 1; i <= n;i++)
    {
        double prod=1;
        for(int j=0;j<k;j++)
        {
            prod *=i;
        }
        k--;
        res += prod;
    }

    cout << "Res= " << res << endl;
}

void for39()
{
    int a,b;
    cout << "A= "; cin>>a;
    cout << "B= "; cin>>b;

    for (int i = a; i <= b;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            cout << i << endl;
        }
    }
}

void for40()
{
    int a,b;
    cout << "A= "; cin>>a;
    cout << "B= "; cin>>b;

    int n = 0;
    for (int i = a; i <= b;i++)
    {
        n++;
        for (int j = 0; j < n ;j++)
        {
            cout << i << endl;
        }
    }
}

int main()
{

    //for1();
    //for2();
    //for3();
    //for4();
    //for5();
    //for6();
    //for7();
    //for8();
    //for9();
    //for10();
    //for11();
    //for12();
    //for13();
    //for14();
    //for15();
    //for16();
    //for17();
    //for18();
    //for19();
    //for20();
    //for21();
    //for22();
    //for23();
    //for24();
    //for25();
    //for26();
    for27();
    //for28();
    //for29();
    //for30();
    //for31();
    //for32();
    //for33();
    //for34();
    //for35();
    //for36();
    //for37();
    //for38();
    //for39();
    //for40();


    return 0;
}