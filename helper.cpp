#include <iostream>
#include <cmath>
#include <ctime>

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

template<class T>
void FillArrayRND(T* A,int n,int from=0,int to=11)
{
    for (int i = 0; i < n ;i++)
    {
        A[i]=(from*100+rand()%((to-from)*100))/100.0;
    }
}

template<class T>
void ShowArray(T* A,int n)
{
    for (int i = 0; i < n ;i++)
    {
        cout << A[i] << " " ;
    }
    cout<<endl;
}

template <class T>
void RemoveByIndex(T *&A,int &n,int pos)
{
    n--;
    T *B=new T[n];

    for(int i=0;i<n;i++)
    {
        if(i<pos)
        {
            B[i]=A[i];
        }
        else
        {
            B[i]=A[i+1];
        }
    }

    delete [] A;
    A = B;
}

void Delete()
{
    int n = 10;
    int *A = new int[n];
    FillArrayRND(A, n);
    ShowArray(A, n);

    int pos1;
    cout << "Pos1= ";cin>>pos1;

    n--;
    int *B = new int[n];
    for (int i = 0; i < n; i++)
    {
        if(i<pos1)
        {
            B[i] = A[i];
        }
        else
        {
            B[i] = A[i + 1];
        }
    }

    delete[] A;
    A = B;
    ShowArray(A, n);

    int pos2;
    cout << "Pos2= ";cin>>pos2;

    n++;
    int *C = new int[n];
    for (int i = 0; i < n; i++)
    {
        if(i<pos2)
        {
            C[i] = A[i];
        }
        else
        {
            C[i+1] = A[i];
        }
    }

    C[pos2] = 100;

    delete[] A;
    A = C;

    ShowArray(A, n);

    delete[] A;
}

template <class T>
void RemoveByIndexFromTo(T *&A,int &n, int from,int to)
{
    for (int i = to; i > from; i--)
    {
        RemoveByIndex(A, n, i);
    }

}

template <class T>
void Remove(T *&A,int &n, int pos,int count)
{
    if(pos<0)return;
    for(int i=0;i<count;i++)
    {
        if(pos>=n)break;
        RemoveByIndex(A,n,pos);
    }
}

template <class T>
void InsertByIndex(T *&A,int &n,int pos,T x)
{
    T *B=new T[n+1];

    for(int i=0;i<n;i++)
    {
        if(i<pos)
        {
            B[i]=A[i];
        }
        else
        {
            B[i+1]=A[i];
        }
    }

    B[pos]=x;
    n++;

    delete [] A;
    A = B;
}

void SearchInArray()
{
    int n;
    cout << "N= ";cin>>n;

    int *A = new int[n];
    FillArrayRND(A, n);
    cout << "Array A:" << endl;
    ShowArray(A, n);

    int counter = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(A[i]>A[j])
                counter++;
        }
    }

    delete[] A;
}

int main()
{
    cout.setf(ios::boolalpha);
    srand(time(NULL));

    // double k = 5;
    // int n = 5;
    // double sum1 = k / 10;
    // double sum2 = n / 10;
    // cout << sum1 << endl;
    // cout << sum2 << endl;

    //Delete();

    // int *a = new int[5];
    // a[0] = 100;
    // cout << a << endl;
    // delete[] a;
    // //a = NULL;
    // a = nullptr;
    // cout << a << endl;

    // a = new int[10];
    // cout << a << endl;

}
