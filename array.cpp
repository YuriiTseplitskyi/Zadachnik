#include <iostream>
#include <ctime>
#include <math.h>
#include <algorithm>

using namespace std;

template<class T>
void FillArrayRND(T* A,int n,int from=0,int to=11)
{
    for (int i = 0; i < n ;i++)
    {
        A[i]=(from*100+rand()%((to-from)*100))/100.0;
    }
}


void FillArrayTransposition(int *A,int n)
{
    for(int i=0;i<n;i++) A[i]=0;

    for (int i = 0; i < n ;i++)
    {
        int pos=rand()%n;
        while(A[pos]!=0)
        {
            pos=rand()%n;
        }
        A[pos]=i;
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

bool isLocalMin(double *arr,int n,int pos)
{
    if(pos==0)return arr[0]<arr[1];
    if(pos==n-1) return arr[n-1]<arr[n-2];
    return arr[pos-1]>arr[pos] && arr[pos]<arr[pos+1];
}

bool isLocalMax(double *arr,int n,int pos)
{
    if(pos==0)return arr[0]>arr[1];
    if(pos==n-1) return arr[n-1]>arr[n-2];
    return arr[pos-1]<arr[pos] && arr[pos]>arr[pos+1];
}

template <class T>
void SortArrayUp(T *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
    }
}

template <class T>
void SortArrayDown(T *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j]) swap(arr[i],arr[j]);
        }
    }
}

template <class T>
T* MergeArraysUp(T* A,int n1,T* B,int n2)
{
    T* C=new T[n1+n2];
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            k++;
            i++;
        }
        else
        {
            C[k]=B[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        C[k]=A[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        C[k]=B[j];
        k++;
        j++;
    }

    return C;
}

template <class T>
T* MergeArraysDown(T* A,int n1,T* B,int n2)
{
    T* C=new T[n1+n2];
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2)
    {
        if(A[i]>B[j])
        {
            C[k]=A[i];
            k++;
            i++;
        }
        else
        {
            C[k]=B[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        C[k]=A[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        C[k]=B[j];
        k++;
        j++;
    }

    return C;
}

template <class T>
void Reverse(T* A,int n,int from=0,int to=-1)
{
    if(to==-1) to=n;
    int i=from;
    int j=to-1;
    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}

template <class T>
void RightShift(T *A, int n)
{
    for (int i = n-1; i >= 1; i--)
     {
         A[i] = A[i-1];
     }

    A[0] = 0;
}

template <class T>
void LeftShift(T *A, int n)
{
    for (int i = 1; i < n; i++)
     {
         A[i-1] = A[i];
     }

    A[n-1] = 0;
}

template <class T>
void RightShift(T *A, int n,int k)
{
   for(int i=0;i<k;i++)
   {
       RightShift(A,n);
   }
}

template <class T>
void LeftShift(T *A, int n,int k)
{
    for(int i=0;i<k;i++)
   {
       LeftShift(A,n);
   }
}

template <class T>
void RightShiftCircle(T *A, int n)
{
    T x=A[n-1];
    RightShift(A,n);
    A[0]=x;
}

template <class T>
void LeftShiftCircle(T *A, int n)
{
    T x=A[0];
    LeftShift(A,n);
    A[n-1]=x;
}

template <class T>
void RightShiftCircle(T *A, int n,int k)
{
    for(int i=0;i<k;i++)
    {
        RightShiftCircle(A,n);
    }
}

template <class T>
void LeftShiftCircle(T *A, int n,int k)
{
    for(int i=0;i<k;i++)
    {
        LeftShiftCircle(A,n);
    }
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

template <class T>
void Insert(T *&A,int &n,int pos,int count,T x)
{
    for (int i = 0; i < count; i++)
    {
        InsertByIndex(A, n, pos, x);
    }
}

void arr1()
{
    const int size=5;

    int arr[size];
    int x=1;
    for (int i = 0; i < size;i++)
    {
        arr[i] = x;
        x+=2;
    }

    for (int i = 0; i < size;i++)
    {
        cout << arr[i] << endl;
    }

}

void arr12()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n;i++)
    {
        arr[i] = 1 + 2 * i;
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }


    delete [] arr;
}

void arr2()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];
    int x=1;
    for (int i = 0; i < n;i++)
    {
        arr[i] =x ;
        x*=2;
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void arr3()
{
    int n,a,d;
    cout << "N= ";cin>>n;
    cout << "A= ";cin>>a;
    cout << "D= ";cin>>d;

    int *arr = new int[n];
    int x=a;

    for (int i = 0; i < n;i++)
    {
        arr[i] = x;
        x=x+d;
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void arr4()
{
    int n,a,d;
    cout << "N= ";cin>>n;
    cout << "A= ";cin>>a;
    cout << "D= ";cin>>d;

    int *arr = new int[n];
    arr[0] = a;
    int prod = 1;

    for (int i = 1; i < n;i++)
    {
        prod *= d;
        arr[i] = arr[0]*prod;
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void arr5()
{
    int n,a,d;
    cout << "N= ";cin>>n;
    cout << "A= ";cin>>a;
    cout << "D= ";cin>>d;

    int *arr = new int[n];
    arr[0] = 1;
    arr[1] = 1;


    for (int i = 2; i < n;i++)
    {
        arr[i] = arr[i-2]+arr[i-1];
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void arr6()
{
    int n,a,b;
    cout << "N= ";cin>>n;
    cout << "A= ";cin>>a;
    cout << "B= ";cin>>b;

    int *arr = new int[n];
    arr[0] = a;
    arr[1] = b;
    arr[2] = a+b;

    for (int i = 3; i < n;i++)
    {
        arr[i] = arr[i-1]+arr[i-1];
    }

    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}


void arr7()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n ;i++)
    {
        arr[i] = rand()%10;
    }

    for (int i = n-1; i > -1 ;i--)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void arr8()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n ;i++)
    {
        arr[i] = rand()%10;
    }

    int counter = 0;
    for (int i = 0; i < n ;i++)
    {
        if(arr[i]%2!=0)
        {
            cout << arr[i] << " ";
            counter++;
        }
    }

    cout << "\nCounter= "<< counter << endl;

    delete[] arr;
}

void arr9()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n;i++)
    {
        arr[i] = rand()%10;
    }


    int counter = 0;
    for (int i = n-1; i >-1;i--)
    {
        if(arr[i]%2==0)
        {
            cout << arr[i] << endl;
            counter++;
        }
    }

    cout << "Counter= "<< counter << endl;
    delete[] arr;
}

void arr10()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr,n);

    ShowArray(arr,n);

    for (int i = 0; i < n ;i++)
    {
        if(arr[i]%2!=0)
        {
            cout << arr[i] << endl;

        }
    }

    cout << "\n\n";

    for (int i = n-1; i >-1;i--)
    {
        if(arr[i]%2==0)
        {
            cout << arr[i] << endl;
        }
    }

    delete[] arr;
}

void arr11()
{
    int n,k;
    cout << "N= ";cin>>n;
    cout << "K= ";cin>>k;

    int *arr = new int[n];

    for (int i = 0; i < n;i++)
    {
        arr[i] = rand()%10;
    }

    for (int i = 0; i < n ;i+=k)
    {
        cout << arr[i] << endl;
    }


    delete[] arr;
}

void array12()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    for (int i = 0; i < n ;i+=2)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void array13()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    for (int i = n-2; i > -1 ;i-=2)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void array14()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    cout << "A2,A4,A6...." << endl;
    for (int i = 1; i <n ;i+=2)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;

    cout << "A1,A3,A5...." << endl;
    for (int i = 0; i <n ;i+=2)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;

    delete[] arr;
}

void array15()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    cout << "A1,A3,A5...." << endl;
    for (int i = 1; i < n ;i+=2)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;

    cout << "A6,A4,A2...." << endl;
    int N=(n-1)/2*2;//�������� ������ ������ � �����
    //int N=n/2*2-1; //�������� �������� ������ � �����
    for (int i = N; i > -1 ;i-=2)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;

    delete[] arr;
}

void array16()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    for (int i = 0; i < n/2; i++)
    {
        cout << arr[i]<<" ";
        cout << arr[n-i-1]<<" ";
    }
    cout << endl;

    delete[] arr;
}

void array16a()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int i=0;
    int j=n-1;
    while(i<=j)
    {
        cout<<arr[i]<<" ";
        if(i!=j) cout<<arr[j]<<" ";
        i++;
        j--;
    }

    cout << endl;

    delete[] arr;
}

void array17()//!
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int i=0;
    int j=n-1;
    int t=0;
    while(i<=j)
    {
        if(t==0) cout<<arr[i++]<<" ";
        if(t==1) cout<<arr[i++]<<" ";
        if(t==2) cout<<arr[j--]<<" ";
        if(t==3) cout<<arr[j--]<<" ";
        t++;
        if(t==4)t=0;
    }
    cout << endl;

    delete[] arr;
}

void array18()
{
    const int n=10;

    int *arr = new int[n];

    FillArrayRND(arr, n,1,10);
    ShowArray(arr, n);

    int k=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < arr[n-1])
        {
            k = arr[i];
            break;
        }
    }

    cout<< k << endl;

    delete[] arr;
}

void array19()
{
    const int n=10;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    cout << arr[0] << " < DIGIT < " << arr[n - 1] << endl;
    ShowArray(arr, n);

    int k=-1;
    for (int i = 0; i < n; i++)
    {
        if(arr[0] < arr[i] && arr[i] < arr[n-1])
        {
            k = i;
        }
    }

    cout<< k << endl;
    delete[] arr;
}

void array20()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int k,l;
    cout << "1 <= K <= L <= N" << endl;
    cout << "K= ";cin>>k;
    cout << "L= ";cin>>l;

    int sum = 0;
    for (int i = k; i <= l; i++)
    {
        sum += arr[i];
    }

    cout << "Sum= " << sum << endl;
    delete[] arr;
}

void array21()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int k,l;
    cout << "1 <= K <= L <= N" << endl;
    cout << "K= ";cin>>k;
    cout << "L= ";cin>>l;

    double sum = 0;
    double counter = 0;
    for (int i = k-1; i <= l-1; i++)
    {
        sum += arr[i];
        counter++;
    }
    double average = sum / counter;

    cout << "Sum= " << sum << endl;
    cout << "Counter= " << counter << endl;
    cout << "Average= " <<average << endl;

    delete[] arr;
}

void array22()
{
    int n,k,l;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    cout << "1 <= K <= L <= N" << endl;
    cout << "K= ";cin>>k;
    cout << "L= ";cin>>l;

    double sum = 0;
    for (int i = k+1; i < l; i++)
    {
        sum += arr[i];
    }

    cout << "Sum= " << sum << endl;

    delete[] arr;
}

void array23()
{
    int n,k,l;
    cout << "1 <= K <= L <= N" << endl;
    cout << "N= ";cin>>n;
    cout << "K= ";cin>>k;
    cout << "L= ";cin>>l;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    double sum = 0;
    double counter = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        counter++;
    }

    for (int i = l+1; i < n; i++)
    {
        sum += arr[i];
        counter++;
    }

    double aeven = sum / counter;
    cout << "Sum= " << sum << endl;
    cout << "Counter= " << counter << endl;
    cout << "AEven= " << aeven << endl;

    delete[] arr;
}

void array24()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ShowArray(arr, n);

    int diff = abs(arr[1] - arr[0]);
    bool ok=true;
    for (int i = 0; i < n;i++)
    {
        int tempDiff=abs(arr[i++]-arr[i]);

        if(diff!=tempDiff)
        {
            ok = false;
            break;
        }
    }

    cout << ok << endl;
    if(ok)cout<<"Diff= "<<diff<<endl;
    delete[] arr;
}

void array25()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ShowArray(arr, n);

    bool ok;
    double diff = abs(arr[1] / arr[0]);
    for (int i = 0; i < n-1;i++)
    {
        double tempDiff=abs(double(arr[i+1])/double(arr[i]));
        if(diff==tempDiff)
        {
            ok = true;
        }
        else
        {
            ok = false;
            break;
        }
    }

    cout << ok << endl;

    delete[] arr;
}

void array26()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ShowArray(arr, n);

    int k=-1;
    bool ok=true;
    for (int i = 0; i < n-1;i++)
    {
        if((arr[i]+arr[i+1])%2==0)
        {
            ok = false;
            k = i+1;
            break;
        }
    }

    if(ok==true)
        cout << "0" << endl;
    else
    {
        cout << k << endl;
        cout << arr[k] << endl;
    }

    delete[] arr;
}

void array27()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ShowArray(arr, n);

    int k;
    bool ok=true;
    for (int i = 0; i < n-1;i++)
    {
        if((arr[i]*arr[i+1])<0)
        {
            ok = false;
            k = i+2;
            break;
        }
    }

    if(ok) cout << "0" << endl;
    else cout << k << endl;

    delete[] arr;
}

void array28()
{
    int n;
    cout << "N= ";cin>>n;
    cout << "A2,A4,A6...." << endl;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int min = arr[0];
    for (int i = 0; i < n;i+=2)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
    }

    cout << "Min= " << min << endl;
    delete[] arr;
}

void array29()
{
    int n;
    cout << "N= ";cin>>n;
    cout << "A1,A3,A5...." << endl;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int max = arr[1];
    for (int i = 1; i < n;i+=2)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }

    cout << "Max= " << max << endl;
    delete[] arr;
}

void array30()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int counter = 0;
    for (int i = 0; i < n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout << i << endl;
            counter++;
        }
    }

    cout << "Counter= " << counter << endl;
    delete[] arr;
}

void array31()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int counter = 0;

    for (int i=n-1; i>0; --i)
    {
        if (arr[i-1]<arr[i])
        {
            cout << arr[i] << endl;
            ++counter;
        }
    }

    cout << "Counter= " << counter << endl;
    delete[] arr;
}

void array32()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int result=-1;
    for (int i = 0; i < n; i++)
    {
        bool found = isLocalMin(arr,n,i);
        if (found)
        {
            cout << arr[i] << endl;
            result=i;
            break;
        }
    }
    delete[] arr;
}

void array33()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int pos=-1;
    for (int i = n-1; i >= 0; i--)
    {
        if (isLocalMax(arr,n,i))
        {
            cout << arr[i] << " " ;
            pos=i;
            break;
        }
    }

    cout << "\nPos= "<< pos << endl;
    delete[] arr;
}

void array34()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int N=0;
    for(int i=0;i<n;i++)
    {
        if(isLocalMin(arr,n,i))
        {
            N++;
        }
    }

    double *b=new double[N];

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(isLocalMin(arr,n,i))
        {
            b[j]=arr[i];
            j++;
        }
    }

    ShowArray(b,N);

    double max=b[0];
    for(int i=0;i<N;i++)
    {
        if(b[i]>max) max=b[i];
    }

    cout<<"Max= "<<max<<endl;

    delete[] arr;
    delete[] b;
}

void array35()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int N = 0;
    for (int i = 0; i < n; i++)
    {
        if(isLocalMax(arr,n,i))
        {
            N++;
        }
    }

    double *b = new double[N];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(isLocalMax(arr,n,i))
        {
            b[j] = arr[i];
            j++;
        }
    }

    ShowArray(b, N);

    double min = b[0];
    for (int i = 0; i < N; i++)
    {
        if(b[i]<min) min=b[i];
    }

    cout << "Min= " << min << endl;

    delete[] arr;
    delete[] b;
}

void array36()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int N = 0;
    for (int i = 0; i < n; i++)
    {
        if(!(isLocalMin(arr, n,i)) && !(isLocalMax(arr, n, i)))
        {
            N++;
        }
    }

    double *b = new double[N];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(!(isLocalMin(arr, n,i)) && !(isLocalMax(arr, n, i)))
        {
            b[j] = arr[i];
            j++;
        }
    }

    if(j==0)
        cout<<j<<endl;
    else
        ShowArray(b, N);

    delete[] arr;
    delete[] b;
}

void array37()//!
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    int counter = 0;
    for (int i = 1; i < n;i++)
    {
        if(isLocalMax(arr,n,i)) counter++;
    }

    cout << "Counter= " << counter << endl;
    delete[] arr;
}

void array40()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n,-11,-1);
    ShowArray(arr, n);

    double r;
    cout << "R= ";cin>>r;

    double diff;
    double *b = new double[n];
    for (int i = 0; i < n; i++)
    {
        diff = abs(arr[i] - r);
        b[i] = diff;
    }

    ShowArray(b, n);

    int pos=0;
    double min = b[0];
    for (int i = 0; i < n;i++)
    {
        if(b[i]<min)
        {
            min=b[i];
            pos=i;
        }
    }

    double result=arr[pos];
    cout << "Result= " << result << endl;
    cout << "MinDiff= " << min << endl;

    delete[] arr;
    delete[] b;
}

void array40a()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    double r;
    cout << "R= ";cin>>r;



    double nearest=arr[0];
    double minDiff = fabs(nearest-r);
    for (int i = 0; i < n;i++)
    {
        double diff=fabs(arr[i]-r);
        if(diff<minDiff)
        {
            minDiff=diff;
            nearest=arr[i];
        }
    }

    cout << "Result= " << nearest << endl;
    cout << "MinDiff= " << minDiff << endl;

    delete[] arr;
}

void array41()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    int j = 0;
    double sum;
    double *b = new double[n];
    for (int i = 0; i < n; i++)
    {
        sum = a[i]+a[i+1];
        b[j] = sum;
        j++;
    }

    ShowArray(b, n);

    double max = b[0];
    int k;
    for (int i = 0; i < n;i++)
    {
        if (b[i] > max)
        {
            max = b[i];
            k = i;
        }
    }

    cout << "Max= " << max << endl;

    cout << a[k] << " " << a[k + 1] << endl;

    delete[] a;
    delete[] b;
}

void array41a()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double A=a[0];
    double B=a[1];
    double max = A+B;
    for (int i = 1; i < n;i++)
    {
        double sum=a[i-1]+a[i];
        if (sum > max)
        {
            max = sum;
            A=a[i-1];
            B=a[i];
        }
    }

    cout << "Max= " << max << endl;
    cout << A << " " << B << endl;

    delete[] a;
}

void array42()
{
    int n;
    cout << "N= ";cin>>n;

    double *arr = new double[n];

    FillArrayRND(arr, n);
    ShowArray(arr, n);

    double r;
    cout << "R= ";cin>>r;

    int k;
    double min = abs(arr[0] + arr[1] - r);
    for (int i = 0; i < n-1; i++)
    {
        double tempMin = abs(arr[i] + arr[i + 1] - r);
        if (min > tempMin)
        {
            min = tempMin;
            k = i;
        }
    }

    cout << arr[k] << " " << arr[k + 1] << endl;
    delete[] arr;
}

void array43()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayRND(arr,n,0,5);

    //sort(arr,arr+n);
    SortArrayUp(arr,n);

    ShowArray(arr, n);

    int counter = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i-1]!=arr[i]) counter++;
    }

    cout << "Counter= " << counter << endl;
    delete[] arr;
}

void array44()
{
    int n;
    cout << "N= ";cin>>n;

    int *arr = new int[n];

    FillArrayTransposition(arr,n);
    arr[rand()%n]=arr[rand()%n];
    ShowArray(arr, n);

    int pos1=-1;
    int pos2=-1;
    for (int i = 0; i < n-1; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                pos1=i;
                pos2=j;
                goto A;
            }
        }
    }
A:
    cout << pos1 << " " << pos2 << endl;
    delete[] arr;
}

void array45()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double A=a[0];
    double B=a[1];
    double minDiff=fabs(A-B);
    int pos1=0;
    int pos2=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double diff=fabs(a[i]-a[j]);
            if(diff<minDiff)
            {
                minDiff=diff;
                A=a[i];
                B=a[j];
                pos1=i;
                pos2=j;
            }
        }
    }

    cout<<A<<" "<<B<<endl;
    cout<<"Pos1= "<<pos1<<endl;
    cout<<"Pos2= "<<pos2<<endl;
    cout<<"MinDiff= "<<minDiff<<endl;
    delete[] a;
}

void array46()
{
    int n;
    cout << "N= ";cin>>n;

    double*a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double r;
    cout<< "R= ";cin>>r;

    int pos1 = 0;
    int pos2 = 1;
    double min = fabs(a[pos1] + a[pos2]-r);
    for (int i = 0; i < n-1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
           double tempMin=fabs(a[i]+a[j]-r);
           if(tempMin<min)
           {
               pos1 = i;
               pos2 = j;
               min=tempMin;
           }
        }
    }

    cout << a[pos1] << " " << a[pos2] << endl;

    delete[] a;
}

void array47()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayRND(a, n,1,10);
    ShowArray(a, n);

    int counter = 0;
    for (int i = 0; i < n;i++)
    {
        bool ok=true;
        for (int j = 0; j < i;j++)
        {
            if(a[i]==a[j])
            {
                ok=false;
                break;
            }
        }
        if(ok)counter++;
    }

    cout << "Counter= " << counter << endl;

    delete[] a;
}

void array48()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    int counter = 1;
    for (int i = 0; i < n;i++)
    {
        int cnt=0;
        for (int j = 0; j < n;j++)
        {
            if(a[i]==a[j])cnt++;
        }
        if(cnt>counter) counter = cnt;
    }

    cout << "Counter= " << counter << endl;

    delete[] a;
}

void array49()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayTransposition(a, n);
    a[8]=-5;
    a[2]=a[12];
    ShowArray(a, n);

    int pos1=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]<1||a[i]>n)
        {
            pos1=i;
            break;
        }
    }

    int pos2=n;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                if(j<pos2) pos2=j;
            }
        }
    }

    int pos=min(pos1,pos2);
    if(pos==n){
        cout<<"We have transposition"<<endl;
    }
    else
    {
        cout<<"Pos= "<<pos<<endl;
    }
    delete[] a;
}

void array50()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayTransposition(a, n);
    ShowArray(a, n);

    int counter=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])counter++;
        }
    }

    cout<<"Counter= "<<counter<<endl;
    delete[] a;
}


void array51()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];
    cout << "Array a:" << endl;
    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];
    cout << "Array b:" << endl;
    FillArrayRND(b, n);
    ShowArray(b, n);

    /*for (int i = 0; i < n;i++)
    {
        swap(a[i], b[i]);
    }*/

    swap(a,b);

    cout << "Array a:" << endl;
    ShowArray(a, n);

    cout << "Array b:" << endl;
    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array52()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];
    cout << "Array a:" << endl;
    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<5)
        {
            b[i] = 2 * a[i];
        }
        else
        {
            b[i] = a[i] / 2;
        }
    }

    cout << "Array b:" << endl;
    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array53()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];
    cout << "Array a:" << endl;
    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];
    cout << "Array b:" << endl;
    FillArrayRND(b, n);
    ShowArray(b, n);

    double *c = new double[n];
    for (int i = 0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i];
        }
    }
    cout << "Array c:" << endl;
    ShowArray(c, n);

    delete[] a;
    delete[] b;
    delete[] c;
}

void array54()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2==0) counter++;
    }

    int *b = new int[counter];

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2==0)
        {
            b[j]=a[i];
            j++;
        }
    }

    ShowArray(b, counter);

    delete[] a;
    delete[] b;
}

void array55()
{
    int n1;
    cout << "N1= ";cin>>n1;

    int *a = new int[n1];

    FillArrayRND(a, n1);
    ShowArray(a, n1);

    int n2 = n1 / 2 ;
    int *b = new int[n2];

    int j = 0;
    for (int i = 1; i < n1;i+=2)
    {
        b[j] = a[i];
        j++;
    }

    cout << "N2= " << n2 << endl;
    ShowArray(b, n2);

    delete[] a;
    delete[] b;
}

void array56()
{
    int n1;
    cout << "N1= ";cin>>n1;

    int *a = new int[n1];

    FillArrayRND(a, n1);
    ShowArray(a, n1);

    int n2 = (n1+2) / 3;
    int *b = new int[n2];

    int j = 0;
    for (int i = 0; i < n1;i+=3)
    {
        b[j] = a[i];
        j++;
    }

    cout << "N2= " << n2 << endl;
    ShowArray(b, n2);

    delete[] a;
    delete[] b;
}

void array57()
{
    int n;
    cout << "N= ";cin>>n;

    int *a = new int[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    int *b = new int[n];

    int j = 0;
    for (int i = 0; i < n; i+=2)
    {
        b[j] = a[i];
        j++;
    }

    for (int i = 1; i < n; i+=2)
    {
        b[j] = a[i];
        j++;
    }

    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array58()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        b[i] = sum;
    }

    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array59()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];

    int count = 0;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        count++;
        b[i] = sum/count;
    }

    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array60()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];

    double sum = 0;
    for (int i = n; i >= 0; i--)
    {
        sum += a[i];
        b[i] = sum;
    }

    ShowArray(b, n);

    delete[] a;
    delete[] b;
}

void array61()
{
    int n;
    cout << "N= ";cin>>n;

    double *a = new double[n];

    FillArrayRND(a, n);
    ShowArray(a, n);

    double *b = new double[n];

    int counter=0;
    double sum = 0;
    for (int i = n; i >= 0; i--)
    {
        sum += a[i];
        counter++;
        b[i] = sum/counter;
    }

    ShowArray(b, n);

    delete[] a;
    delete[] b;
}
void array62()
{
    int n1;
    cout << "N1= ";cin>>n1;

    double *a = new double[n1];

    FillArrayRND(a, n1,-5,5);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int n2 = 0;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]>0) n2++;
    }

    double *b = new double[n2];
    int j = 0;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]>0)
        {
            b[j]=a[i];
            j++;
        }
    }

    cout << "N2= " << n2 << endl;
    cout << "Array b:(+)" << endl;
    ShowArray(b, n2);

    int n3 = 0;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]<0) n3++;
    }

    double *c = new double[n3];
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]<0)
        {
            c[k]=a[i];
            k++;
        }
    }

    cout << "N3= " << n3 << endl;
    cout << "Array c:(-)" << endl;
    ShowArray(c, n3);

    delete[] a;
    delete[] b;
    delete[] c;
}

void array63()
{
    int n1;
    cout << "N1= ";cin>>n1;
    double *a = new double[n1];

    FillArrayRND(a, n1);
    SortArrayUp(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int n2;
    cout << "N1= ";cin>>n2;
    double *b = new double[n2];

    FillArrayRND(b, n2);
    SortArrayUp(b, n2);
    cout << "Array b:" << endl;
    ShowArray(b, n2);

    int n3 =n1+n2;
    double *c = MergeArraysUp(a,n1,b,n2);

    cout << "Array c:" << endl;
    ShowArray(c, n3);

    delete[] a;
    delete[] b;
    delete[] c;
}

void array64()
{
    int n1;
    cout << "N1= "; cin>> n1;
    double *a = new double[n1];
    FillArrayRND(a, n1);
    SortArrayDown(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int n2;
    cout << "N2= "; cin>> n2;
    double *b = new double[n2];
    FillArrayRND(b, n2);
    SortArrayDown(b, n2);
    cout << "Array b:" << endl;
    ShowArray(b, n2);

    int n3;
    cout << "N3= ";cin>> n3;
    double *c = new double[n3];
    FillArrayRND(c, n3);
    SortArrayDown(c, n3);
    cout << "Array c:" << endl;
    ShowArray(c, n3);

    int n4 = n1 + n2;
    double *d = MergeArraysDown(a,n1,b,n2);

    int n5=n4+n3;
    double *e = MergeArraysDown(d,n4,c,n3);

    cout << "Array e:" << endl;
    ShowArray(e, n5);

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
    delete[] e;
}

void array65()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int k;
    cout << "K= ";cin>>k;

    double ak=a[k];
    for (int i = 0; i < n1; i++)
    {
        a[i] = a[i] + ak;
    }

    ShowArray(a, n1);

    delete[] a;
}

void array66()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *a = new int[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int evenNumber=-1;
    for (int i = 0; i < n1;i++)
    {
        if(a[i]%2==0)
        {
            evenNumber = a[i];
            break;
        }
    }

    if(evenNumber!=-1)
    {
        for (int i = 0; i < n1; i++)
        {
            if(a[i]%2==0)
            {
                a[i] = a[i] + evenNumber;
            }
        }
    }

    ShowArray(a, n1);

    delete[] a;
}

void array67()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *a = new int[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int OddNumber=0;
    for (int i = n1-1; i >= 0;i--)
    {
        if(a[i]%2!=0)
        {
            OddNumber = a[i];
            break;
        }
    }

    if(OddNumber!=0)
    {
        for (int i = 0; i < n1; i++)
        {
            if(a[i]%2!=0)
            {
                a[i] = a[i] + OddNumber;
            }
        }
    }

    ShowArray(a, n1);

    delete[] a;
}

void array68()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    double min=a[0];
    int pos1=-1;
    for (int i = 0; i < n1;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            pos1 = i;
        }
    }

    cout << "Min= " << min << endl;

    double max=a[0];
    int pos2=-1;
    for (int i = 0; i < n1;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            pos2 = i;
        }
    }

    cout << "Max= " << max << endl;
    if(pos1!=pos2)
    {
        a[pos1]=max;
        a[pos2]=min;
        //swap(a[pos1], a[pos2]);
    }

    ShowArray(a, n1);

    delete[] a;
}

void array69()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    for (int i = 0; i < n1-1;i+=2)
    {
        swap(a[i], a[i + 1]);
    }

    ShowArray(a, n1);

    delete[] a;
}

void array70()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    Reverse(a,n1);

    ShowArray(a, n1);

    delete[] a;
}

void array71()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int size = n1-1;
    for (int i = 0; i < n1/2;i++)
    {
        swap(a[i], a[size]);
        size--;
    }

    ShowArray(a, n1);

    delete[] a;
}

void array72()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int k,l;
    cout << "1 <= K < L <= N" << endl;
    cout << "K= "; cin>> k;
    cout << "L= "; cin>> l;

    /*int j = l;
    int size = l - k;
    for (int i = k; i <size;i++)
    {
        double temp1 = a[i];
        double temp2 = a[j];
        swap(a[i], a[j]);
        j--;
    }*/

    Reverse(a,n1,k,l+1);

    ShowArray(a, n1);

    delete[] a;
}

void array73()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    int k,l;
    cout << "1 <= K < L <= N" << endl;
    cout << "K= "; cin>> k;
    cout << "L= "; cin>> l;
    cout << "Changed array a:" << endl;

    // int diff = (l - k) / 2;
    // int size = l - diff;
    // int j = l - 1;
    // for (int i = k + 1; i <size;i++)
    // {
    //     double temp1 = a[i];
    //     double temp2 = a[j];
    //     swap(a[i], a[j]);
    //     j--;
    // }

    Reverse(a, n1, k+1, l);

    ShowArray(a, n1);

    delete[] a;
}

void array74()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    double max = a[0];
    int pos1;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            pos1 = i;
        }
    }
    cout << "Max= " << max << endl;

    double min = a[0];
    int pos2;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            pos2 = i;
        }
    }
    cout << "Min= " << min << endl;

    cout << "Pos1= " << pos1 << endl;
    cout << "Pos2= " << pos2 << endl;

    if(pos1>pos2) swap(pos1, pos2);

    for (int i = pos1+1; i < pos2; i++)
    {
        a[i] = 0;
    }

    cout << "Changed array a:" << endl;
    ShowArray(a, n1);

    delete[] a;
}

void array75()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    double max = a[0];
    int pos1;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            pos1 = i;
        }
    }
    cout << "Max= " << max << endl;
    cout << "PosMax= " << pos1 << endl;

    double min = a[0];
    int pos2;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            pos2 = i;
        }
    }
    cout << "Min= " << min << endl;
    cout << "PosMin= " << pos2 << endl;

    if(pos1>pos2) swap(pos1, pos2);
    int j = pos2;

    int diff;
    if(pos1>pos2)
        diff = (pos1 - pos2) / 2;
    else
        diff = (pos2 - pos1) / 2;
    cout << "Diff= " << diff << endl;

    int size = pos1 + diff;
    cout << "Size= " << size << endl;
    for (int i = pos1; i <pos2/2 ; i++)
    {
        swap(a[i], a[j]);
        j--;
    }

    cout << "Changed array a:" << endl;
    ShowArray(a, n1);

    delete[] a;
}

void array75a()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *a = new double[n1];
    FillArrayRND(a, n1);
    cout << "Array a:" << endl;
    ShowArray(a, n1);

    double max = a[0];
    int posMax;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            posMax = i;
        }
    }
    cout << "Max= " << max << endl;
    cout << "PosMax= " << posMax << endl;

    double min = a[0];
    int posMin;
    for (int i = 0; i < n1; i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            posMin = i;
        }
    }
    cout << "Min= " << min << endl;
    cout << "PosMin= " << posMin << endl;

    if(posMin>posMax) swap(posMin,posMax);

    Reverse(a, n1, posMin, posMax + 1);

    cout << "Changed array a:" << endl;
    ShowArray(a, n1);

    delete[] a;
}

void array76()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    int counter = 0;
    if(a[0]>a[1] )   counter++;
    if(a[n-1]>a[n-2] )  counter++;

    for (int i = 1; i < n-1; i++)
    {
        if(a[i-1]<a[i] && a[i]>a[i+1]) counter++;
    }

    int *pos = new int[counter];
    int j = 0;

    if(a[0]>a[1] )
    {
        pos[j]=0;
        j++;
    }

    for (int i = 1; i < n-1; i++)
    {
        if(a[i-1]<a[i] && a[i]>a[i+1])
        {
            pos[j]=i;
            j++;
        }
    }

    if(a[n-1]>a[n-2] )
    {
        pos[j]=n-1;
        j++;
    }

    int k = 0;
    for (int i = 0; i < counter; i++)
    {
        int localMax = pos[k];
        a[localMax] = 0;
        k++;
    }

    cout << "Array pos:" << endl;
    ShowArray(pos, counter);

    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array77()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    int counter = 0;
    if(a[0]>a[1] )   counter++;
    if(a[n-1]>a[n-2] )  counter++;

    for (int i = 1; i < n-1; i++)
    {
        if(a[i-1]<a[i] && a[i]>a[i+1]) counter++;
    }

    int *pos = new int[counter];
    int j = 0;

    if(a[0]<a[1] )
    {
        pos[j]=0;
        j++;
    }

    for (int i = 1; i < n-1; i++)
    {
        if(a[i-1]>a[i] && a[i]<a[i+1])
        {
            pos[j]=i;
            j++;
        }
    }

    if(a[n-1]<a[n-2] )
    {
        pos[j]=n-1;
        j++;
    }

    int k = 0;
    for (int i = 0; i < counter; i++)
    {
        int localMin = pos[k];
        a[localMin] = a[localMin]*a[localMin] ;
        k++;
    }

    cout << "Array pos:" << endl;
    ShowArray(pos, counter);

    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array78()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    double *b = new double[n];

    b[0] = (a[0] + a[1]) / 2;

    for (int i = 1; i < n-1; i++)
    {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }

    b[n-1] = (a[n-1] + a[n-2]) / 2;

    swap(a, b);

    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
    delete[] b;
}

void array79()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

//     for (int i = n-1; i >= 1; i--)
//     {
//         a[i] = a[i-1];
//     }
//
//    a[0] = 0;

    LeftShift(a,n);

    cout << "------->" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array80()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    double *b = new double[n];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    int j=0;
    for (int i = 0; i < n-1; i++)
    {
        a[i] = b[j+1];
        j++;
    }

    a[n-1] = 0;
    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array81()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    int k;
    cout << "K= ";cin>>k;

//    double *b = new double[n];
//
//    for (int i = 0; i < n; i++)
//    {
//        b[i] = a[i];
//    }
//
//    for (int i = 0; i < k; i++)
//    {
//        a[i] = 0;
//    }
//
//    int j = 0;
//    for (int i = k; i < n; i++)
//    {
//        a[i] = b[j];
//        j++;
//    }

    RightShift(a,n,k);

    cout << "------->" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array82()//!//!
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    int k;
    cout << "K= ";cin>>k;

    double *b = new double[n];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    for (int i = k; i < n; i++)
    {
        a[i] = 0;
    }

    int j = 0;
    for (int i = n-1; i >=1; i--)
    {
        a[i] = b[i-k];
        j++;
    }


    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array83()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

//    double *b = new double[n];
//
//    for (int i = 0; i < n; i++)
//    {
//        b[i] = a[i];
//    }
//
//    for (int i = 1; i < n; i++)
//    {
//        a[i] = b[i - 1];
//    }
//
//    a[0] = b[n - 1];

    RightShiftCircle(a,n);

    cout << "------->" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array84()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    double *b = new double[n];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    for (int i = n-1; i >=1; i--)
    {
        a[i - 1] = b[i];
    }

    a[n - 1] = b[0];

    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array85()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a, n);

    int k;
    cout<<"K= ";cin>>k;

    RightShiftCircle(a,n,k);

    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);

    delete[] a;
}

void array87()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    SortArrayUp(a, n);
    a[0]=7;
    ShowArray(a, n);

    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i]) swap(a[i-1],a[i]);
    }

    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);
    delete[] a;
}

void array88()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    SortArrayUp(a, n);
    a[n-1]=7;
    ShowArray(a, n);

    for(int i=n-1;i>0;i--)
    {
        if(a[i-1]>a[i]) swap(a[i-1],a[i]);
    }

    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);
    delete[] a;
}

void array89()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    SortArrayUp(a, n);
    a[rand()%n]=7;
    ShowArray(a, n);

    for(int i=n-1;i>0;i--)
    {
        if(a[i-1]>a[i]) swap(a[i-1],a[i]);
    }

    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i]) swap(a[i-1],a[i]);
    }

    cout << "<-------" << endl;
    cout << "Changed array a:" << endl;
    ShowArray(a, n);
    delete[] a;
}

void array90()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a,n);

    int k;
    cout<<"K= ";cin>>k;

    RemoveByIndex(a,n,k);

    cout << "Array a:" << endl;
    ShowArray(a,n);

    delete[] a;
}

void array91()
{
    int n;
    cout << "N1= "; cin>> n;

    double *a = new double[n];
    FillArrayRND(a, n);
    cout << "Array a:" << endl;
    ShowArray(a,n);

    int k,l;
    cout << "1 <= K <= L <= N" << endl;
    cout << "K= ";cin>>k;
    cout << "L= ";cin>>l;

    int count=l-k+1;
    Remove(a,n,k,count);
    cout << "Array a:" << endl;
    ShowArray(a,n);

    delete[] a;
}

void array92()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for(int i=n1-1;i>=0;i--)
    {
        if(A[i]%2!=0)
        {
            RemoveByIndex(A,n1,i);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array93()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int N=(n1-1)/2*2;//останній парний індекс у масиві

    for(int i=N;i>=0;i-=2)
    {
        RemoveByIndex(A,n1,i);
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array94()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int N=n1/2*2-1;//останній непарний індекс у масиві

    for(int i=N;i>=0;i-=2)
    {
        RemoveByIndex(A,n1,i);
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array95()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    //FillArrayRND(A, n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int n2 = 0;
    for (int i = 0; i < n1-1; i++)
    {
        if(A[i]!=A[i+1])
            n2++;
    }
    n2++;

    int j = 0;
    int *B = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        if(A[i]!=A[i+1])
        {
            B[j] = A[i];
            j++;
        }
    }

    delete [] A;
    A = B;

    cout << "N2= " << n2 << endl;
    cout << "Array A:" << endl;
    ShowArray(A,n2);

    delete[] A;
}

void array95a()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for(int i=n1-1;i>0;i--)
    {
        if(A[i]==A[i-1])
        {
            RemoveByIndex(A,n1,i);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array96()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for (int i = 0; i < n1-1; i++)
    {
        for (int j = n1-1; j > i; j--)
        {
            if(A[i]==A[j])
            {
                RemoveByIndex(A, n1, j);
            }
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array97()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int n2 = 0;
    for (int i = 0; i < n1; i++)
    {
        bool ok = true;
        for (int j = 0; j < i; j++)
        {
            if(A[i]==A[j])
            {
               ok = false;
               break;
            }
        }
        if(ok)n2++;
    }

    int *B = new int[n2];
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        bool ok = true;
        for (int j = i+1; j < n1; j++)
        {
            int a = A[i];
            int b = A[j];
            if(A[i]==A[j])
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            B[k] = A[i];
            k++;
        }
    }

    delete[] A;
    A = B;

    cout << "N2= " << n2 << endl;
    cout << "Array A:" << endl;
    ShowArray(A,n2);

    delete[] A;
}

void array97a()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);
    Reverse(A,n1);

    //0 5 8 4 3
    for (int i = 0; i < n1-1; i++)
    {
        for (int j = n1-1; j > i; j--)
        {
            if(A[i]==A[j])
            {
                RemoveByIndex(A, n1, j);
            }
        }
    }

    Reverse(A,n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array98()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for(int i=n1-1;i>=0;i--)
    {
        int x=A[i];
        int counter=0;
        for(int j=0;j<n1;j++)
        {
            if(A[j]==x)counter++;
        }
        if(counter<3)
        {
            for(int k=n1-1;k>=0;k--)
            {
                if(A[k]==x) RemoveByIndex(A,n1,k);
            }
            i=i-(counter-1);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array99()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for(int i=n1-1;i>=0;i--)
    {
        int x=A[i];
        int counter=0;
        for(int j=0;j<n1;j++)
        {
            if(A[j]==x)counter++;
        }
        if(counter>2)
        {
            for(int k=n1-1;k>=0;k--)
            {
                if(A[k]==x) RemoveByIndex(A,n1,k);
            }
            i=i-(counter-1);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array100()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for(int i=n1-1;i>=0;i--)
    {
        int x=A[i];
        int counter=0;
        for(int j=0;j<n1;j++)
        {
            if(A[j]==x)counter++;
        }
        if(counter==2)
        {
            for(int k=n1-1;k>=0;k--)
            {
                if(A[k]==x) RemoveByIndex(A,n1,k);
            }
            i=i-(counter-1);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);

    delete[] A;
}

void array101()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int k;
    cout<<"K= ";cin>>k;

    InsertByIndex(A,n1,k,0.0);

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array102()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int k;
    cout<<"K= ";cin>>k;

    InsertByIndex(A,n1,k+1,0.0);

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array103()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    double min = A[0];
    int posMin = 0;
    for (int i = 0; i < n1; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
            posMin = i;
        }
    }
    InsertByIndex(A,n1,posMin,0.0);

    double max = A[0];
    int posMax = 0;
    for (int i = 0; i < n1; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
            posMax = i;
        }
    }
    InsertByIndex(A,n1,posMax+1,0.0);

    cout << "Max= " << max << endl;
    cout << "Min= " << min << endl;

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array104()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int pos,count;
    cout << "Pos= ";cin>>pos;
    cout << "Count= ";cin>>count;

    Insert(A, n1, pos, count, 0.0);

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array105()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int pos,count;
    cout << "Pos= ";cin>>pos;
    cout << "Count= ";cin>>count;

    Insert(A, n1, pos+1, count, 0.0);

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array106()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for (int i = 0; i < n1; i+=3)
    {
        InsertByIndex(A, n1, i, A[i]);
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array107()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for (int i = 1; i < n1; i+=4)
    {
        Insert(A, n1, i, 2, A[i]);
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array108()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1,-6,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int n2 = 0;
    for (int i = n1-1; i >=0; i--)
    {
        if(A[i]>0)
        {
            InsertByIndex(A, n1, i, 0.0);//не компілює якщо не йти з кінця //!чому
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array109()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1,-6,5);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for (int i = n1-1; i >=0; i--)
    {
        if(A[i]<0)
        {
            InsertByIndex(A, n1, i+1, 0.0);//не компілює якщо не йти з кінця //!чому
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array110()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    for (int i = n1-1; i >=0; i--)
    {
        if(A[i]%2==0)
        {
            InsertByIndex(A, n1, i, A[i]);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array111()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int n2 = 0;
    for (int i = n1-1; i >=0; i--)
    {
        if(A[i]%2!=0)
        {
            Insert(A, n1, i, 2, A[i]);
        }
    }

    cout << "Array A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array112()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,15);
    cout << "Array A:" << endl;
    ShowArray(A,n1);
    cout << endl;

    int counter=0;
    for (int i = 0; i < n1-1; i++)
    {
        bool finish=true;
        for (int j = 1; j < n1-i; j++)
        {
            counter++;
            if(A[j-1]>A[j])
            {
                swap(A[j-1], A[j]);
                finish=false;
            }
        }
        if(finish) break;
        ShowArray(A, n1);
    }

    cout << "\nArray A:" << endl;
    ShowArray(A,n1);
    delete[] A;
    cout<<"Counter= "<<counter<<endl;
}

void array113()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,25);
    cout << "Array A:" << endl;
    ShowArray(A,n1);
    cout << endl;

    int max = A[0];
    int pos = 0;
    int tempN = n1;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 1;j < tempN; j++)
        {
            if(A[j]>max)
            {
                pos = j;
                max = A[j];
            }
        }
        swap(A[tempN - 1], A[pos]);
        tempN--;
        max = A[0];
        pos = 0;
        ShowArray(A, n1);
    }

    cout << "\nArray A:" << endl;
    ShowArray(A,n1);
    delete[] A;
}

void array114()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,25);
    cout << "Array A:" << endl;
    ShowArray(A,n1);
    cout << endl;

    int counter=0;
    for(int i=1;i<n1;i++)
    {
        for(int j=i;j>0;j--)
        {
            counter++;
            if(A[j-1]>A[j])
            {
                swap(A[j-1],A[j]);
            }
            else
            {
                break;
            }
        }
        ShowArray(A,n1);
    }

    cout << "\nArray A:" << endl;
    ShowArray(A,n1);
    delete[] A;
    cout<<"Counter= "<<counter<<endl;
}

void array115()
{
    int n1;
    cout << "N1= "; cin>> n1;

    double *A = new double[n1];
    FillArrayRND(A, n1,1,15);
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int *I = new int[n1];

    for (int i = 0; i < n1; i++)
    {
        I[i] = i;
    }

    cout << "\nArray I:" << endl;
    ShowArray(I,n1);
    cout << endl;

    for (int i = 0; i < n1-1; i++)
    {
        bool finish=true;
        for (int j = 1; j < n1-i; j++)
        {
            if(A[I[j-1]]>A[I[j]])
            {
                swap(I[j-1], I[j]);
                finish=false;
            }
        }
        if(finish) break;
    }

    cout << "\nArray I:" << endl;
    ShowArray(I,n1);

    delete[] A;
    delete[] I;
}

void array116()
{
    int n1;
    cout << "N1= "; cin>> n1;

    int *A = new int[n1];
    FillArrayRND(A, n1,1,15);
    A[1] = A[2];
    A[n1 - 2] = A[n1 - 1];
    cout << "Array A:" << endl;
    ShowArray(A,n1);

    int n2 = n1;
    int *B = new int[n2];
    // int *C = new int[n2];

    int j = 0;
    B[0] = 1;
    //C[0] = A[0];
    for (int i = 1; i<n1; i++)
    {
        if(A[i]==A[i+1])
        {
            B[j] += 1;
            RemoveByIndex(A, n1, i);
        }
        else
        {
            j++;
            B[j] = 1;
            //C[j] = A[i];
        }
    }
    j++;

    int *C = new int[j];
    delete[] C;
    C = A;

    cout << "\nArray B:" << endl;
    ShowArray(B,j);

    cout << "\nArray C:" << endl;
    ShowArray(C,j);

    delete[] A;
    delete[] B;
    delete[] C;
}

int main()
{
    srand(time(NULL));
    cout.setf(ios::boolalpha);

    array100();

    return 0;
}

