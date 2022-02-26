#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

using namespace std;

void begin13() 
{
	double r, R;
	cout << " r = "; cin >> r;
	cout << " R = "; cin >> R;

	double s = PI * r * r;
	double S = PI * R * R;
	double Sk = fabs(S - s);

	cout << " S = " << S << endl;
	cout << " s = " << s << endl;
	cout << " Sk = " << Sk << endl;
}

void begin14() 
{
	double L;
	cout << " L = "; cin >> L;

	double R = L / (2 * PI);
	double S = PI * R * R;

	cout << " R = " << R << endl;
	cout << " S = " << S << endl;
}

void Integer() 
{
	cout << " 5/2 = " << 5 / 2 << endl;
	cout << " 5%2 = " << 5 % 2 << endl;

	int x = 1234567;

	int d0 = x / 1 % 10; //7
	int d1 = x / 10 % 10; //6
	int d2 = x / 100 % 10; //5
	int d3 = x / 1000 % 10; //4
	int d4 = x / 10000 % 10; //3
	int d5 = x / 100000 % 10; //2
	int d6 = x / 1000000 % 10; //1
  
	int y = d0 * 1000000 + d1 * 100000 + d2 * 10000 + d3 * 1000 + d4 * 100 + d5 * 10 + d6 * 1;

	cout << " y = " << y << endl;
}

void integer30()
{
    int year;cin>>year;
    int century=(year-1)/100+1;


    // if(year>=1000)
    // {
        
    //     int a=year/1000 % 10;
    //     int b=year/100%10;

    //     cout<<(a*10+b)+1<<" "<<"century"<<endl;
    // }
    // else if(year>=100&&year<1000)
    // {
    //      int c;
    //      c=year/100%10;
    //      cout<<c+1<<" "<<"century"<<endl; 
    // }
    // else
    // {
    //     cout<<1<<" "<<"century"<<endl;
    // }

}


void begin22()
{

    int a,b,c;
    cin>>a>>b;
    cout<<"a="<<" "<<a<<"\t"<<"b="<<" "<<b<<"\t\t";
    
    c=a;
    a=b;
    b=c;
    cout<<"a="<<" "<<a<<"\t"<<"b="<<" "<<b<<"\t\t";
    
    swap(a,b);
    cout<<"a="<<" "<<a<<"\t"<<"b="<<" "<<b<<"\t\t";
}

void begin29()
{
    
     double gra;cin>>gra;
     double ra=(gra*PI)/180;
     cout<<ra<<"\n";

}

void integer29()
{
    int a,b,c;
    cin>>a>>b>>c;

    int A=a/c;
    int B=b/c;
    int n=A*B;
    int s=(a*b)-n*c*c;

    cout<<"A="<<A<<endl;
    cout<<"B="<<B<<endl;
    cout<<"n="<<n<<endl;
    cout<<"s="<<s<<endl;


   /* int s1=a*b;
    int s2=c*c;

    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;

    int num=s1/s2;
    cout<<num<<endl;*/
}

void integer1920()
{
     int s;cin>>s;

     int m=s/60;
     int h=s/60/60;
    
     cout<<"minutes="<<m<<"\t"<<"hours="<<h<<endl;
}

void integer21()
{
    int S;cin>>S;

    int m=S/60;
    int s=S-m*60;

    cout<<s<<endl;
}

void integer17()
{
    int num;cin>>num;

    int a=num/1000%10;
    int b=num/100%10;

    cout<<"thousands="<<a<<"\t"<<"hundreds="<<b<<endl;
}

void integer2223()
{
    int S;cin>>S;

    int h=S/60/60;
    int s=S-h*60*60;
    int m=s/60;

    cout<<s<<endl;
    cout<<m<<endl;

//помилка при 3450
}

void integer1920a()
{
     int s;cin>>s;

     int h=s/3600;
     int rest=s%3600;
     int m=rest/60;
     int sec=rest%60;
    
     cout<<"minutes="<<m<<"\t"<<"hours="<<h<<"\t"<<"seconds="<<sec<<endl;
}

void integer24()
{
    int k;cin>>k;
    int pr;cin>>pr;

    int dt=(k+pr-1)%7;
    cout<<dt<<endl;

}


int main()
{
    //begin13();
    //begin14();
	//Integer();
    
    //integer30();
    //begin22();
    //begin29();
    //integer29();
    //integer1920();
    //integer21();
    //integer17();
    //integer2223();
    // integer1920a();
    Integer();

    return 0;
}