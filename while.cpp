#include <iostream>
#include <cmath>

using namespace std;

void while1()
{
    double a,b;
    cout<<"A= ";cin>>a;
    cout<<"B= ";cin>>b;

    int counter=0;
    while(a>=b)
    {
        a-=b;
        counter++;
    }
    cout<<"A= "<<a<<endl;
}

void while2()
{
    double a,b;
    cout<<"A= ";cin>>a;
    cout<<"B= ";cin>>b;

    int counter=0;
    while(a>=b)
    {
        a-=b;
        counter++;
    }
    cout<<"Counter= "<<counter<<endl;
}
void while3()
{
    int n, k;
    cout<<"N= ";cin>>n;
    cout<<"K= ";cin>>k;

    int counter=0;
    while(n>=k)
    {
        n -= k;
        counter++;
    }

    cout<<"Res= "<<counter<<endl;
    cout<<"Rest= "<<n<<endl;
}

//81=1*3*3*3*3
void while4()
{
    int x;
    cout<<"X= ";cin>>x;

    bool ok=true;
    while(x>1)
    {
        if(x%3!=0)
        {
            ok=false;
            break;
        }
        x=x/3;
    }
    cout<<ok<<endl;
}

void while5()
{
    int n;
    cout << "N= ";cin>>n;

    int counter=0;
    while(n!=1)
    {
        n /= 2;
        counter++;
    }

    cout<<"K= "<<counter<<endl;
}

void while6()
{
    int n;
    cout << "N= ";cin>>n;

    double res = 1;
    int k=0;
    while(k<n)
    {
        res *= n-k;
        k += 2;
    }

    cout << "Res= " << res << endl;
}

void while7()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 1;
    while(k*k<n)
    {
        k++;
    }

    cout << "K= " << k << endl;
}

void while8()//!
{
    int n;
    cout << "N= ";cin>>n;

    int k = 1;
    while(k*k<n)
    {
        k++;
    }
    k--;
    cout << "K= " << k << endl;
}

void while9()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 0;
    int p=1;
    while(p<=n)
    {
        p*=3;
        k++;
    }

    cout << "K= " << k << endl;
}

void while10()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 1;
    while(pow(3,k)<n)
    {
        k++;
    }
    k--;
    cout << "K= " << k << endl;
}

void while11()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 0;
    int sum = 0;
    while(sum<=n)
    {
        k++;
        sum += k;
    }

    cout << "K= " << k << endl;
    cout << "Sum= " << sum << endl;
}

void while12()//!
{
    int n;
    cout << "N= ";cin>>n;

    int k = 0;
    int sum = 0;
    while(sum<=n)
    {
        k++;
        sum += k;
    }

    cout << "K= " << k-1 << endl;
    cout << "Sum= " << sum-k << endl;
}

void while13()
{
    int a;
    cout << "A= ";cin>>a;

    double sum = 1;
    int k = 1;
    while(sum<a)
    {
        sum += 1.0 / k;
        k++;
    }

    cout << "K= " << k << endl;
    cout << "Sum= " << sum << endl;
}

void while14()
{
    int a;
    cout << "A= ";cin>>a;

    double sum = 1;
    int k = 1;
    while(sum<a)
    {
        sum += 1.0 / k;
        k++;
    }

    cout << "K= " << k-1 << endl;
    cout << "Sum= " << sum-1.0/k << endl;
}

void while15()
{
    double sum=1000;
    double sumFinal = 1100;
    int month = 0;
    double p;
    cout << "(0<P<25)P= "; cin>>p;

    while(sum<sumFinal)
    {
        sum += sum * (p/100);
        month++;
    }

    cout << "Month= " << month << endl;
    cout << "Sum= " << sum << endl;
}

void while16()
{
    double rout=10;
    double routFinal = 200;
    int day = 0;
    double p;
    cout << "(0<P<50)P= "; cin>>p;
    double sum=0;

    while(sum<routFinal)
    {
        day++;
        sum+=rout;
        cout << "Days= " << day;
        cout << "  Rout= " << rout << endl;
        rout += rout * (p/100);
    }

    cout << "Days= " << day << endl;
    cout << "Sum= " << sum << endl;
}

void while17()
{
    int n;
    cout << "N= ";cin>>n;

    while(n!=0)
    {
        int digit = n % 10;
        cout << digit << endl;
        n/=10;
    }
}

void while18()
{
    int n;
    cout << "N= ";cin>>n;

    int counter = 0;
    int sum = 0;

    while(n!=0)
    {
        int digit = n % 10;
        cout << digit << endl;
        n/=10;
        sum+=digit;
        counter++;
    }

    cout <<"Sum= "<< sum << endl;
    cout << "Number of letters= " << counter  << endl;
}

void while19()
{
    int n;
    cout << "N= ";cin>>n;

    int sum = 0;
    while(n!=0)
    {
        int digit = n % 10;
        cout << digit << endl;
        n/=10;
        sum=sum*10+digit;
    }

    cout <<"Sum= "<< sum << endl;
}

void while20()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 1;
    bool ok = false;
    int digit = 1;
    while(digit!=0)
    {
        digit = n / k % 10;
        k *= 10;
        if(digit==2)
        {
            ok = true;
            break;
        }
    }
    cout << ok << endl;
}

void while21()
{
    int n;
    cout << "N= ";cin>>n;

    int k = 1;
    bool ok = false;
    int digit = 1;
    while(digit!=0)
    {
        digit = n / k % 10;
        k *= 10;
        if(digit%2!=0)
        {
            ok = true;
            break;
        }
    }
    cout << ok << endl;
}

void while22()
{
    int n;
    cout << "N= ";cin>>n;
    bool ok=true;
    if(n%2==0)
    {
        ok=false;
    }
    else
    {
        for(int i=3; i<sqrt(n)+1; i+=2)
        {
            if(n%i==0)
            {
                ok=false;
                break;
            }
        }
    }
    cout<<ok<<endl;

}

void while23()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;

    a=abs(a);
    b=abs(b);
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
    cout<< a <<endl;
}

void while24()
{
    int n;
    cout << "N= ";cin>>n;

    int f1 = 1;
    int f2 = 1;
    int f = 0;
    bool ok = false;

    while(f<n)
    {
        f = f2 + f1;
        f2 = f1;
        f1 = f;
        if(f==n)
        {
            ok = true;
        }
    }
    cout << ok << endl;
}

void while25()
{
    int n;
    cout << "N= ";cin>>n;

    int f1 = 1;
    int f2 = 1;
    int f = 0;

    while(f<n)
    {
        f = f2 + f1;
        f2 = f1;
        f1 = f;
    }
    cout << f << endl;
}

void while26()
{
    int n;
    cout << "N= ";cin>>n;

    int f1 = 1;
    int f2 = 1;
    int f = 0;

    while(f<n)
    {
        f = f2 + f1;
        f2 = f1;
        f1 = f;
    }
    cout << f2 << endl << f + f2 << endl;
}

void while27()
{
    int n;
    cout << "N= ";cin>>n;

    int f1 = 1;
    int f2 = 1;
    int f = 0;
    int counter = 0;

    while(f!=n)
    {
        f = f2 + f1;
        f2 = f1;
        f1 = f;
        counter++;
    }

    counter += 2;
    cout << counter << endl;
}

void while28()//!//!!//!!//!!
{
    double e;
    cout << "E= ";cin>>e;

    int counter = 0;
    double a1 = 2;
    //while(a<e)
    {
        double a = 2 + 1 / a1;
        counter++;
        a1 = a;
    }
    cout << counter+1 << endl;
}

void while29()
{
    double e;
    cout << "E= ";cin>>e;

    double a1 = 1;
    double a2 = 2;

    int k=2;

    while(abs(a2-a1)>e)
    {
        double a = (a1 + 2 * a2) / 3;
        a1 = a2;
        a2 = a;
        k++;
    }

    cout << "K= " << k << endl;
    cout << "A(k-1)= " << a1 << endl;
    cout << "A(k)= " << a2 << endl;
}

void while30()//!!//!!//!!
{
    int a, b, c;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    cout << "C= ";cin>>c;

    int counter = 0;
    while((a-c)>0 && (b-c)>0)
    {
        a -= c;
        b -= c;
        counter++;
    }
    cout << counter << endl;
}

int main()
{
    cout.setf(ios::boolalpha);
    system("chcp 1251>>nul");

    while17();

    return 0;
}
