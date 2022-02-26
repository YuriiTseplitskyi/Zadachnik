#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
    
void series1()
{
    double n;
    double sum=0;

    for (int i = 1; i <= 10; i++)
    {
        cout << "N" << i << "= ";
        cin >> n;
        sum += n;
    }

    cout << "Sum= " << sum << endl;
    
}

void series2()
{
    double n;
    double prod=1;

    for (int i = 1; i <= 10; i++)
    {
        cout << "N" << i << "= ";
        cin >> n;
        prod *= n;
    }

    cout << "Prod= " << prod << endl;
    
}

void series3()
{
    double n;
    double res=0;

    for (int i = 1; i <= 10; i++)
    {
        cout << "N" << i << "= ";
        cin >> n;
        res *= n;
    }

    res /= 10;
    cout << "Res= " << res << endl;   
}

void series4()
{
    double n;
    double sum=0;
    double prod=1;
    int k = n;

    for (int i = 1; i <=n; i++)
    {
        cout << "N" << i << "= ";
        cin >> n;
        prod *= n;
        sum += n;
    }

    cout << "Prod= " << prod << endl; 
    cout << "Sum= " << sum << endl; 
}

int main()
{
    series4();
}