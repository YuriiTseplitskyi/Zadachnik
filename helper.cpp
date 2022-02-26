#include <iostream>
#include <cmath>
 
using namespace std;

int fact(int n)
{
    if(n==0)   return 0;
    if(n==1)   return 1;
    
    return n * (fact(n - 1));
}

int fib(int n)
{
    if(n<2) return n;

    return fib(n - 1) + fib(n - 2);
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
    switch(month)
    {
        case 1: return 31;
        case 2: return isYearLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;

        default:return 0;
    }
}

int getMonthDays1(int month, int year)
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

void array()
{
    int size = 10;
    int array[size];

    for (int i = 0; i < size;i++)
    {
        array[i] = rand()%11;
    }

    for (int i = 0; i < size;i++)
    {
        cout << array[i] << endl;
    }
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

int main()
{
    cout.setf(ios::boolalpha);
    
    // double k = 5;
    // int n = 5;
    // double sum1 = k / 10;
    // double sum2 = n / 10;
    // cout << sum1 << endl;
    // cout << sum2 << endl;

    double n = 2;
    n = 1 / n;
   
    cout << 5/2;
}