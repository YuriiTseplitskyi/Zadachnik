#include <iostream>
 
using namespace std;
 
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

int getNOD1(int a,int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    return a + b;
}

void function24()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    int res = getNOD1(a, b);
    cout << res << endl;
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

void function25()
{
    int a,b;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    cout << a << "/" << b << endl;
    int nom = a/getNOD1(a, b);
    int den = b/getNOD1(a, b);
    cout << nom << "/" << den << endl;
}

int getNOK(int a,int b)
{
    return a * (b / getNOD(a , b));
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

void function26()
{
    int a, b, c;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;
    cout << "C= ";cin>>c;

    int res = getNOD3(a, b, c);
    cout << res<< endl;
}

int main()
{
    function26();
}