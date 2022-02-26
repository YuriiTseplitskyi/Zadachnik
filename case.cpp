#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265;

int getMonthDays(int month, int year);
int getMonthDays1(int month, int year);

void case1()
{
    int x;
    cin>>x;
    switch(x)
    {
        case 1: cout<<"Monday"<<endl; break;
        case 2: cout<<"Tuesday"<<endl; break;
        case 3: cout<<"Wednesday"<<endl; break;
        case 4: cout<<"Thursday "<<endl; break;
        case 5: cout<<"Friday"<<endl; break;
        case 6: cout<<"Saturday"<<endl; break;
        case 7: cout<<"Sunday"<<endl; break;
        default:cout<<"Mistake"<<endl; break;
    }
}

void case2()
{
    int x;
    cin>>x;
    switch(x)
    {
        case 1: cout<<"bad"<<endl; break;
        case 2: cout<<"unsatisfactory"<<endl; break;
        case 3: cout<<"satisfactory"<<endl; break;
        case 4: cout<<"good"<<endl; break;
        case 5: cout<<"very good"<<endl; break;
        default:cout<<"mistake"<<endl; break;
    }
}

void case3()
{
     int x; cin>>x;
     switch(x)
     {
         case 1:
         case 2:
         case 12: cout << "winter" << endl;
         break;

         case 3:
         case 4:
         case 5: cout << "spring" << endl;
         break;

         case 6:
         case 7:
         case 8: cout << "summer" << endl;
         break;

         case 9:
         case 10:
         case 11: cout << "autumn" << endl;
         break;

         default: cout << "mistake" << endl; ; break;
     }
}

void case4()
{
    cout<<"Month=";
    int month; cin>>month;
    cout<<"Year=";
    int year; cin>>year;

    int numberOfDays=getMonthDays1(month,year);
    cout<<numberOfDays<<endl;
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

void case5()
{
    double a;
    cin >> a;
    double b;
    cin >> b;
    char x; cin>>x;
    switch(x)
    {
        case '+': cout << a+b << endl; break;
        case '-': cout << a-b << endl; break;
        case '*': cout << a*b << endl; break;
        case '/': cout << a/b << endl; break;

        default: cout << "mistake" << endl; break;
    }
}
void case6()
{
    double a;
    cin >> a;
    int x; cin>>x;
    switch(x)
    {
        case 1: cout << a/10 << endl;//дц
        break;

        case 2: cout << a*1000 << endl;//км
        break;

        case 3: cout << a << endl;//м
        break;

        case 4: cout << a/1000 << endl;//мм
        break;

        case 5: cout << a/100 << endl;//см
        break;

        default: cout << "mistake" << endl; break;
    }
}

void case7()
{
    double a;
    cin >> a;
    int x; cin>>x;

    switch(x)
    {
        case 1: cout << a << endl;//кг
        break;

        case 2: cout << a/1000000 << endl;//мг
        break;

        case 3: cout << a/1000 << endl;//г
        break;

        case 4: cout << a*1000 << endl;//т
        break;

        case 5: cout << a*100 << endl;//ц
        break;

        default: cout << "mistake" << endl; break;
    }
}

void case8()
{
    int D;
    cin >> D;
    int M;
    cin >> M;
    int Y;
    cin>>Y;

   if(D>1)
   {
       D--;
   }
   else
   {
       M--;
       if(M==0)
       {
           M=12;
           Y--;
       }
       D=getMonthDays(M, Y);
   }
   cout.fill('0');
   cout<<setw(2)<<D<<"/"<<setw(2)<<M<<"/"<<setw(4)<<Y<<endl;
}

void case9()
{
    int D;
    cin >> D;
    int M;
    cin >> M;

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
                case 32: D = 1; M++; break;
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

        default:cout << "mistake" << endl;
    }

    switch (M)
    {
        case 13:M = 1; D = 1; break;
    }

     cout << D << endl << M << endl;
}

void case10()
{

    int x=0;
    int y=0;
    char direction='n';

    while(true)
    {
        cout<< x << " " << y << " " << direction <<endl;

        char command;
        cout<<"Command([l]eft,[r]ight,[g]o): "; cin>>command;

        switch(command)
        {
        case 'l':
            switch(direction)
            {
                case 'n':direction='w'; break;
                case 'w':direction='s'; break;
                case 's':direction='e'; break;
                case 'e':direction='n'; break;
            }
            break;

        case 'r':
            switch(direction)
            {
                case 'n':direction='e'; break;
                case 'w':direction='n'; break;
                case 's':direction='w'; break;
                case 'e':direction='s'; break;
            }
            break;

        case 'g':
            switch(direction)
            {
                case 'n': y++; break;
                case 'w': x--; break;
                case 's': y--; break;
                case 'e': x++; break;
            }
            break;
        }
    }


}

//////////////////////////!
void case11()
{
    int c;
    cin >> c;
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;

    // Північ - 1
    // Захід - 2
    // Південь - 3
    // Схід - 4

    // 1 - поворот наліво
    // -1 поворот направо
    // 2 - поворот на 180

    switch(c)
    {
        case 1://північ
            switch(n1)
            {
                case 1:c = 2; break;
                case -1:c = 4; break;
                case 2:c = 3; break;

                default:cout << "mistake" << endl; break;
            }
            switch(n2)
            {
                case 1:c = 3; break;
                case -1:c = 3; break;
                case 2:c = 1; break;

                default:cout << "mistake" << endl; break;
            }

        break;

        case 2://захід
            switch(n1)
            {
                case 1:c = 3; break;
                case -1:c = 1; break;
                case 2:c = 4 ; break;

                default:cout << "mistake" << endl; break;
            }
            switch(n2)
            {
                case 1:c = 4; break;
                case -1:c = 4; break;
                case 2:c = 2; break;

                default:cout << "mistake" << endl; break;
            }

        break;

        case 3://південь
            switch(n1)
            {
                case 1:c = 4; break;
                case -1:c = 2; break;
                case 2:c = 1; break;

                default:cout << "mistake" << endl; break;
            }
            switch(n2)
            {
                case 1:c = 1; break;
                case -1:c = 1; break;
                case 2:c = 3; break;

                default:cout << "mistake" << endl; break;
            }
        break;

        case 4://схід
            switch(n1)
            {
                case 1:c = 1; break;
                case -1:c = 3; break;
                case 2:c = 2; break;

                default:cout << "mistake" << endl; break;
            }
            switch(n2)
            {
                case 1:c = 2; break;
                case -1:c = 2; break;
                case 2:c = 4; break;

                default:cout << "mistake" << endl; break;
            }
        break;

        default:cout << "mistake" << endl; break;
    }

    cout << c << endl;

}

void case12()
{
    int num;
    cin >> num;
    double x;
    cin >> x;
    double r, d, l, s;

    switch(num)
    {
        case 1:
            r = x;
            d = 2*r;
            l = 2 * PI * r;
            s = PI * r * r;
            break;
        case 2:
            r = x / 2;
            d = x;
            l = 2 * PI * r;
            s = PI * r * r;
            break;
        case 3:
            r = x / (2 * PI);
            d = 2 * r;
            l = x;
            s = PI * r * r;
            break;
        case 4:
            s = x;
            r = sqrt(s / PI);
            d = 2 * r;
            l = 2 * PI * r;
            break;

        default: cout << "mistake" << endl;
        break;
    }

    cout << r << endl;
    cout << d << endl;
    cout << l << endl;
    cout << s << endl;

}

void case13()
{
    int num;
    cin >> num;
    double x;
    cin >> x;
    double a, c, h, s;

    switch(num)
    {
        case 1:
            a = x;
            c = a * sqrt(2);
            h = c / 2;
            s = (c * h) / 2;
            break;

        case 2:
            c = x;
            a = c/sqrt(2);
            h = c / 2;
            s = (c * h) / 2;
            break;

        case 3:
            h = x;
            c = 2*h;
            a = c/sqrt(2);
            s = (c * h) / 2;
            break;

        case 4:
            s = x;
            a = pow(2 * s, 0.5);
            c = a * sqrt(2);
            h = c / 2;
            break;

        default: cout << "mistake" << endl;
        break;
    }

    cout << a << endl;
    cout << c << endl;
    cout << h << endl;
    cout << s << endl;
}

void case15()
{
    //  1 - піка
    //  2 - хреста
    //  3 - дзвуна
    //  4 - черва

    int mast;
    cin >> mast;
    int carta;
    cin >> carta;

    switch(carta)
    {
        case 6: cout << "six" << endl; break;
        case 7: cout << "seven" << endl; break;
        case 8: cout << "eight" << endl; break;
        case 9: cout << "nine" << endl; break;
        case 10: cout << "ten" << endl; break;
        case 11: cout << "jack" << endl; break;
        case 12: cout << "queen" << endl; break;
        case 13: cout << "king" << endl; break;
        case 14: cout << "ace" << endl; break;

        default: cout << "mistake" << endl;
    }

    switch(mast)
    {
        case 1:cout << "spades" << endl; break;
        case 2:cout << "clubs" << endl; break;
        case 3:cout << "diamonds" << endl; break;
        case 4:cout << "hearts" << endl; break;

        default: cout << "mistake" << endl;
    }
}

void case16()
{
    int year;
    cin >> year;

    switch(year/10)
    {
        case 2:cout << "двадцять" << " " ; break;
        case 3:cout << "тридцять" << " " ; break;
        case 4:cout << "сорок" << " " ; break;
        case 5:cout << "п'ятдесят" << " " ; break;
        case 6:cout << "шістдесят" << " " ; break;

        default:cout << "mistake" << endl;
    }

    switch(year%10)
    {
        case 0:cout <<""; break;
        case 1:cout << "один" << " " ; break;
        case 2:cout << "два" << " " ; break;
        case 3:cout << "три" << " " ; break;
        case 4:cout << "чотири" << " " ; break;
        case 5:cout << "п'ять" << " " ; break;
        case 6:cout << "шість" << " " ; break;
        case 7:cout << "сім" << " " ; break;
        case 8:cout << "вісім" << " " ; break;
        case 9:cout << "дев'ять" << " " ; break;

        default:cout << "mistake" << endl;
    }

    switch(year%10)
    {
        case 0:cout << "років"<< " "<<endl; break;

        case 1:cout << "рік" << " " <<endl; break;

        case 2:
        case 3:
        case 4:cout << "роки" << " "<<endl; break;

        case 5:
        case 6:
        case 7:
        case 8:
        case 9:cout << "років" <<" "<<endl; break;

        default:cout << "mistake" << endl;
    }

}

void  case17()
{
    int zavd; cin>>zavd;

    switch(zavd)
    {
        case 10:cout << "десять завдань" << endl; break;
        case 11:cout << "одинадцять завдань" << endl; break;
        case 12:cout << "дванадцять завдань" << endl; break;
        case 13:cout << "тринадцять завдань" << endl; break;
        case 14:cout << "чотирнадцять завдань" << endl; break;
        case 15:cout << "п'ятнадцять завдань" << endl; break;
        case 16:cout << "шістнадцять завдань" << endl; break;
        case 17:cout << "сімнадцять завдань" << endl; break;
        case 18:cout << "вісімнадцять завдань" << endl; break;
        case 19:cout << "дев'ятнадцять завдань" << endl; break;

        default:
        switch(zavd/10)
        {
            case 2: cout << "двадцять" << " "; break;
            case 3: cout << "тридцять" << " "; break;
            case 4: cout << "сорок" << " "; break;
        }

        switch(zavd%10)
        {
            case 1:cout << " одне "<< " "; break;
            case 2:cout << " два"<< " "; break;
            case 3:cout << " три"<< " "; break;
            case 4:cout << " чотири"<< " "; break;
            case 5:cout << " п'ять"<< " "; break;
            case 6:cout << " шість"<< " "; break;
            case 7:cout << " сім"<< " "; break;
            case 8:cout << " вісім"<< " "; break;
            case 9:cout << " дев'ять"<< " "; break;
        }
        switch(zavd%10)
        {
            case 0:cout << "завдань"<< " "<<endl; break;

            case 1:
            case 2:
            case 3:
            case 4:cout << "завдання" << " " <<endl; break;

            case 5:
            case 6:
            case 7:
            case 8:
            case 9:cout << "завдань" <<" "<<endl; break;
        }
    }

}

void case18()
{
    int digit; cin>>digit;

    switch(digit/100)
   {
        case 1:cout << " сто " ; break;
        case 2:cout << " двісті " ; break;
        case 3:cout << " триста " ; break;
        case 4:cout << " чотириста " ; break;
        case 5:cout << " п'ятсот " ; break;
        case 6:cout << " шістсот " ; break;
        case 7:cout << " сімсот " ; break;
        case 8:cout << " вісімсот " ; break;
        case 9:cout << " дев'ятсот " ; break;
    }

    switch(digit/10%10)
    {
        case 1:cout << " десять " ; break;
        case 2:cout << " двадцять " ; break;
        case 3:cout << " тридцять " ; break;
        case 4:cout << " сорок " ; break;
        case 5:cout << " п'ятдесят " ; break;
        case 6:cout << " шістдесят " ; break;
        case 7:cout << " сімдесят " ; break;
        case 8:cout << " вісімдесят " ; break;
        case 9:cout << " дев'яносто " ; break;
    }

    switch(digit%100)
    {
        case 11:cout << " одинадцать";break;
        case 12:cout << " дванадцать ";break;
        case 13:cout << " тринадцать";break;
        case 14:cout << " чотирнадцать";break;
        case 15:cout << " п'ятнадцать ";break;
        case 16:cout << " шістнадцать ";break;
        case 17:cout << " сімнадцать";break;
        case 18:cout << " вісімнадцать";break;
        case 19:cout << " дев'ятнадцать";break;

        default:
        switch(digit%10)
        {
        case 1:cout << " один "<< " "; break;
        case 2:cout << " два"<< " "; break;
        case 3:cout << " три"<< " "; break;
        case 4:cout << " чотири"<< " "; break;
        case 5:cout << " п'ять"<< " "; break;
        case 6:cout << " шість"<< " "; break;
        case 7:cout << " сім"<< " "; break;
        case 8:cout << " вісім"<< " "; break;
        case 9:cout << " дев'ять"<< " "; break;
        }
    }
}

void case20()
{
    cout<<"DAY"<<endl;
    int d;cin>>d;
    cout<<"MONTH"<<endl;
    int m;cin>>m;

    switch(m%10)
    {
    case 1:
        switch(d%10)
        {
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:cout<<"водолій"<<endl; break;
        }
    case 2:
        switch(d%10)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:cout<<"водолій"<<endl; break;


        }

    }
}


int main()
{
    system("chcp 1251 >> nul");
    case8();

    return 0;
}