#include <iostream>
#include <iomanip>
using namespace std;

void sqPattern();
void calender();
void printDiamond();

int fibonachiSum(int n);
void printRipplePond();

void lostMiner();

int main(){

    int choice;
    cout<<"Enter Your Choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        sqPattern();
        break;
    case 2:
        calender();
        break;
    case 3:
        printDiamond();
        break;
    case 4:
        printRipplePond();
        break;
    case 5:
        lostMiner();
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    
    default:
        cout<<"Invalid Input!"<<endl;
        break;
    }
    

    return 0;
}

/*===========================
  Problem 1 of Assignment 3
===========================*/
void sqPattern(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int digit;

    if (n % 2 != 0 && n > 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (i == n-(n-k) || i == n-k+1 || j == n-k+1 || j == n-(n-k))
                    {
                        if (k > 9)
                        {
                            digit = k % 10;
                            cout<<digit<<" ";
                            break;
                        }
                        else{
                            cout<<k<<" ";
                            break;
                        }                        
                    }                    
                }                
            }
        cout<<endl;
        }        
    }
    else{
        cout<<"Invalid Number Input!"<<endl;
    }   
}

/*===========================
  Problem 2 of Assignment 3
===========================*/

void calender(){
    int year, month, totalDays, weekDay, date = 1;
    bool flagLeap = false;

    cout<<"Year::: ";
    cin>>year;

    cout<<"Month::: ";
    cin>>month;

    if ((year >= 1 && year <= 9999) && (month >= 1 && month <= 12))
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            flagLeap = true;
        }
        totalDays = (year-1) * 365 + (year-1) / 4 - (year-1)/100 + (year-1)/400;
        cout<<setw(6)<<endl<<endl<<' ';

        switch(month){
            case 1:
                month = 31;
                totalDays = totalDays;
                cout<<"January "<<year<<endl;
                break;
            case 2:
                (flagLeap == true) ? month = 29 : month = 28;
                totalDays += 31;
                cout<<"February "<<year<<endl;
                break;
            case 3:
                month = 31;
                (flagLeap == true) ? totalDays += 29+31 : totalDays += 28+31;
                cout<<"March "<<year<<endl;
                break;
            case 4:
                month = 30;
                (flagLeap == true) ? totalDays += 29+31+31 : totalDays += 28+31+31;
                cout<<"April "<<year<<endl;
                break;
            case 5:
                month = 31;
                (flagLeap == true) ? totalDays += 29+31+31+30 : totalDays += 28+31+31+30;
                cout<<"May "<<year<<endl;
                break;
            case 6:
                month = 30;
                (flagLeap == true) ? totalDays += 29+31+31+30+31 : totalDays += 28+31+31+30+31;
                cout<<"June "<<year<<endl;
                break;
            case 7:
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30 : totalDays += 28+31+31+30+31+30;
                month = 31;
                cout<<"July "<<year<<endl;
                break;
            case 8:
                month = 31;
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30+31 : totalDays += 28+31+31+30+31+30+31;
                cout<<"August "<<year<<endl;
                break;
            case 9:
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30+31+31 : totalDays += 28+31+31+30+31+30+31+31;
                month = 30;
                cout<<"September "<<year<<endl;
                break;
            case 10:
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30+31+31+30 : totalDays += 28+31+31+30+31+30+31+31+30;
                month = 31;
                cout<<"October "<<year<<endl;
                break;
            case 11:
                month = 30;
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30+31+31+30+31 : totalDays += 28+31+31+30+31+30+31+31+30+31;
                cout<<"November "<<year<<endl;
                break;
            case 12:
                month = 31;
                (flagLeap == true) ? totalDays += 29+31+31+30+31+30+31+31+30+31+30 : totalDays += 28+31+31+30+31+30+31+31+30+31+30;
                cout<<"December "<<year<<endl;
                break;
        }
        weekDay = (totalDays + 1) % 7;

        cout<<"Su "<<"Mo "<<"Tu "<<"We "<<"Th "<<"Fr "<<"Sa "<<endl<<endl;
        //spaces
        for (int i = 1; i <= (month + weekDay); i++)
        {
            if (i > weekDay)
            {
                cout<<setw(2)<<date<<' ';
                date += 1;
            }
            else{
                cout<<setw(3)<<' ';
            }
            if (i % 7 == 0)
            {
                cout<<endl;
            }            
        }
        cout<<endl;
    }
    else{
        cout<<"Invalid Month or Year!"<<endl;
    }  
}

/*===========================
  Problem 3 of Assignment 3
===========================*/

void printDiamond(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int req = n+n-1;
    int st1 = 1;
    int st2 = 2;
    int st3 = 3;
    int st4 = 4;

    if (n % 2 != 0 && n > 2)
    {

        for (int i = 1; i <= req; i++)
        {
            for (int j = 1; j <= req; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (i <= n)
                    {
                        if (j <= n && !(j + i <= n))
                        {

                            if (j + i == n+k)
                            {
                                if (k % 4 == 1)
                                {
                                    cout<<"*";
                                }
                                else if (k % 4 == 2)
                                {
                                    cout<<".";
                                }
                                else if (k % 4 == 3)
                                {
                                    cout<<"o";
                                }
                                else if (k % 4 == 0)
                                {
                                    cout<<"-";
                                }
                            }
                        }
                        else if (j > n && !(j - i >= n))
                        {
                            if (j - i == n-k)
                            {
                                if (k % 4 == 1)
                                {
                                    cout<<"*";
                                }
                                else if (k % 4 == 2)
                                {
                                    cout<<".";
                                }
                                else if (k % 4 == 3)
                                {
                                    cout<<"o";
                                }
                                else if (k % 4 == 0)
                                {
                                    cout<<"-";
                                }
                                else{
                                    cout<<"*";
                                }
                                break;
                            }
                        }
                        else{
                            cout<<" ";
                            break;
                        }
                    }
                    else{
                        if (j <= n && !(i - j >= n))
                        {
                            if (i - j == n-k)
                            {
                                if (k % 4 == 1)
                                {
                                    cout<<"*";
                                }
                                else if (k % 4 == 2)
                                {
                                    cout<<".";
                                }
                                else if (k % 4 == 3)
                                {
                                    cout<<"o";
                                }
                                else if (k % 4 == 0)
                                {
                                    cout<<"-";
                                }
                                break;
                            }
                        }
                        else if (j > n && !(j + i > req + n))
                        {
                            if (j + i == req+n-(k-1))
                            {
                                if ((k-1) % 4 == 0)
                                {
                                    cout<<"*";
                                }
                                else if ((k-1) % 4 == 1)
                                {
                                    cout<<".";
                                }
                                else if ((k-1) % 4 == 2)
                                {
                                    cout<<"o";
                                }
                                else if ((k-1) % 4 == 3)
                                {
                                    cout<<"-";
                                }
                                break;
                            }
                        }
                        else{
                            cout<<" ";
                            break;
                        }
                    }
                }
            }
            cout<<endl;
        }
    }

    else{
        cout<<"Invalid Input!"<<endl;
    }
}

/*===========================
  Problem 4 of Assignment 3
===========================*/
int fibonachiSum(int n){
    int sum = 0;
    int a = 1, b = 1, fib;

    for (int i = 1; i <= n; i++)
    {
        sum += a;
        fib = a + b;
        a = b;
        b = fib;
    }
    return sum;
}

void printRipplePond(){
    int n, base, seed, val, digit;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Enter a base: ";
    cin>>base;

    cout<<"Enter a seed: ";
    cin>>seed;

    int actual = 2 * n - 1;

    for (int i = 1; i <= actual; i++)
    {
        for (int j = 1; j <= actual; j++)
        {
            switch (base)
            {
            case 10:
                if(i <= n){
                    if(j <= n){
                        if (!(i > j))
                        {
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 9))
                            {
                                val = val - 10;
                            }
                            cout<<val<<" ";
                        }
                        else{

                            val = seed - fibonachiSum(n - j) + 2 * fibonachiSum(n - i);                            
                            while (!(val >= 0))
                            {
                                val = val + 10;
                            }
                            while (!(val <= 9))
                            {
                                val = val - 10;
                            }
                            cout<<val<<" ";
                        }
                    }
                    else{
                        if(!(i + j >= actual + 2)){
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 9))
                            {
                                val = val - 10;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed + fibonachiSum(j-n);
                            while (!(val <= 9))
                            {
                                val = val - 10;
                            }
                            cout<<val<<" ";
                        }
                    }
                }
                else{
                    if(j <= n){
                        if(!(i + j <= actual)){
                            val  = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 10;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed - fibonachiSum(n-j);
                            while (!(val >= 0))
                            {
                                val = val + 10;
                            }
                            cout<<val<<" ";
                        }
                    }
                    else{
                        if (!(j - i > 0))
                        {
                            val = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 10;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed + fibonachiSum(j - n) - 2 * fibonachiSum(i - n);
                            
                            while (!(val <= 9))
                            {
                                val = val - 10;
                            }
                            while (!(val >= 0))
                            {
                                val = val + 10;
                            }
                            cout<<val<<" ";
                        }
                    }
                }  
                break;
            case 16:
                if(i <= n){
                    if(j <= n){
                        if (!(i > j))
                        {
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 15))
                            {
                                val = val - 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                            
                        }
                        else{
                            val = seed - fibonachiSum(n - j) + 2 * fibonachiSum(n - i);
                            while (!(val >= 0))
                            {
                                val = val + 16;
                            }

                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            } 
                        }
                    }
                    else{
                        if(!(i + j >= actual + 2)){
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 15))
                            {
                                val = val - 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                        else{
                            val = seed + fibonachiSum(j-n);
                            while (!(val <= 15))
                            {
                                val = val - 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                    }
                }
                else{
                    if(j <= n){
                        if(!(i + j <= actual)){
                            val  = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                        else{
                            val = seed - fibonachiSum(n-j);
                            while (!(val >= 0))
                            {
                                val = val + 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                    }
                    else{
                        if (!(j - i > 0))
                        {
                            val = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 16;
                            }
                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                        else{
                            val = seed + fibonachiSum(j - n) - 2 * fibonachiSum(i - n);
                            while (!(val <= 15))
                            {
                                val = val - 16;
                            }
                            while (!(val >= 0))
                            {
                                val = val + 16;
                            }

                            if (val > 9)
                            {
                                digit = val % 10;
                                val = 65 + digit;
                                cout<<(char)val<<" ";
                            }
                            else{
                                cout<<val<<" ";
                            }
                        }
                    }
                }
                break;
            case 8:
                if(i <= n){
                    if(j <= n){
                        if (!(i > j))
                        {
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 7))
                            {
                                val = val - 8;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed - fibonachiSum(n - j) + 2 * fibonachiSum(n - i);                
                            while (!(val >= 0))
                            {
                                val = val + 8;
                            }
                            while (!(val <= 7))
                            {
                                val = val - 8;
                            }
                            cout<<val<<" ";
                        }
                    }
                    else{
                        if(!(i + j >= actual + 2)){
                            val = seed + fibonachiSum(n-i);
                            while (!(val <= 7))
                            {
                                val = val - 8;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed + fibonachiSum(j-n);
                            while (!(val <= 7))
                            {
                                val = val - 8;
                            }
                            cout<<val<<" ";
                        }
                    }
                }
                else{
                    if(j <= n){
                        if(!(i + j <= actual)){
                            val  = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 8;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed - fibonachiSum(n-j);
                            while (!(val >= 0))
                            {
                                val = val + 8;
                            }
                            cout<<val<<" ";
                        }
                    }
                    else{
                        if (!(j - i > 0))
                        {
                            val = seed - fibonachiSum(i-n);
                            while (!(val >= 0))
                            {
                                val = val + 8;
                            }
                            cout<<val<<" ";
                        }
                        else{
                            val = seed + fibonachiSum(j - n) - 2 * fibonachiSum(i - n);
                            
                            while (!(val <= 7))
                            {
                                val = val - 8;
                            }
                            while (!(val >= 0))
                            {
                                val = val + 8;
                            }
                            cout<<val<<" ";
                        }
                    }
                }
                break;
            default:
                cout<<"Invalid Base!"<<endl;
                break;
            }
        }
        cout<<endl;
    }   
}

/*===========================
  Problem 5 of Assignment 3
===========================*/

void lostMiner(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    unsigned long long r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0;
    unsigned long long p = 1, q = 1, current = 0, upRow = 0, downRow = 0;
    char temp;
    bool reached, surroundings;
    int S = 5, star = 2, dot = 3, G = 4, E = 6, startRow = 0, startColumn = 0, gcount = 0, exit = false, d;

    if (n >= 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin>>temp; //S=5, *=2, .=3, G=4, E=6
                if (i == 1)
                {
                    if (temp == 'S')
                    {
                        r1 = r1 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r1 = r1 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r1 = r1 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r1 = r1 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r1 = r1 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 2)
                {
                    if (temp == 'S')
                    {
                        r2 = r2 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r2 = r2 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r2 = r2 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r2 = r2 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r2 = r2 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 3)
                {
                    if (temp == 'S')
                    {
                        r3 = r3 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r3 = r3 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r3 = r3 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r3 = r3 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r3 = r3 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 4)
                {
                    if (temp == 'S')
                    {
                        r4 = r4 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r4 = r4 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r4 = r4 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r4 = r4 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r4 = r4 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 5)
                {
                    if (temp == 'S')
                    {
                        r5 = r5 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r5 = r5 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r5 = r5 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r5 = r5 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r5 = r5 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 6)
                {
                    if (temp == 'S')
                    {
                        r6 = r6 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r6 = r6 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r6 = r6 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r6 = r6 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r6 = r6 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 7)
                {
                    if (temp == 'S')
                    {
                        r7 = r7 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r7 = r7 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r7 = r7 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r7 = r7 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r7 = r7 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 8)
                {
                    if (temp == 'S')
                    {
                        r8 = r8 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r8 = r8 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r8 = r8 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r8 = r8 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r8 = r8 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 9)
                {
                    if (temp == 'S')
                    {
                        r9 = r9 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r9 = r9 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r9 = r9 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r9 = r9 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r9 = r9 * 10 + E;
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                if (i == 10)
                {
                    if (temp == 'S')
                    {
                        r10 = r10 * 10 + S;
                        startRow = i;
                        startColumn = j;
                    }
                    else if (temp == '*')
                    {
                        r10 = r10 * 10 + star;
                    }
                    else if (temp == '.')
                    {
                        r10 = r10 * 10 + dot;
                    }
                    else if (temp == 'G')
                    {
                        r10 = r10 * 10 + G;
                    }
                    else if (temp == 'E')
                    {
                        r10 = r10 * 10 + E;
                        
                    }
                    else{
                        cout<<"Invalid Input!"<<endl;
                        return;
                    }
                }
                
            } 
        }

        for (int i = 1; i <= n - startColumn; i++)
        {
            p = p * 10;
        }
        
        if (startRow == 1)
        {
            r1 += 2 * p;
        }
        else if (startRow == 2)
        {
            r2 += 2 * p;
        }
        else if (startRow == 3)
        {
            r3 += 2 * p;
        }
        else if (startRow == 4)
        {
            r4 += 2 * p;
        }
        else if (startRow == 5)
        {
            r5 += 2 * p;
        }
        else if (startRow == 6)
        {
            r6 += 2 * p;
        }
        else if (startRow == 7)
        {
            r7 += 2 * p;
        }
        else if (startRow == 8)
        {
            r8 += 2 * p;
        }
        else if (startRow == 9)
        {
            r9 += 2 * p;
        }
        else
        {
            r10 += 2 * p;
        }

        do{
            reached = false;

            for (int i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    current = r1;
                }
                else if (i == 2)
                {
                    current = r2;
                }
                else if (i == 3)
                {
                    current = r3;
                }
                else if (i == 4)
                {
                    current = r4;
                }
                else if (i == 5)
                {
                    current = r5;
                }
                else if (i == 6)
                {
                    current = r6;
                }
                else if (i == 7)
                {
                    current = r7;
                }
                else if (i == 8)
                {
                    current = r8;
                }
                else if (i == 9)
                {
                    current = r9;
                }
                else
                {
                    current = r10;
                }

                //up row
                if (i == 2)
                {
                    upRow = r1;
                }
                else if (i == 3)
                {
                    upRow = r2;
                }
                else if (i == 4)
                {
                    upRow = r3;
                }
                else if (i == 5)
                {
                    upRow = r4;
                }
                else if (i == 6)
                {
                    upRow = r5;
                }
                else if (i == 7)
                {
                    upRow = r6;
                }
                else if (i == 8)
                {
                    upRow = r7;
                }
                else if (i == 9)
                {
                    upRow = r8;
                }
                else if (i == 10)
                {
                    upRow = r9;
                }

                //Down Row
                if (i == 1)
                {
                    downRow = r2;
                }
                else if (i == 2)
                {
                    downRow = r3;
                }
                else if (i == 3)
                {
                    downRow = r4;
                }
                else if (i == 4)
                {
                    downRow = r5;
                }
                else if (i == 5)
                {
                    downRow = r6;
                }
                else if (i == 6)
                {
                    downRow = r7;
                }
                else if (i == 7)
                {
                    downRow = r8;
                }
                else if (i == 8)
                {
                    downRow = r9;
                }
                else if (i == 9)
                {
                    downRow = r10;
                }
                
                for (int j = 1; j <= n; j++)
                {
                    q = 1;
                    for (int k = 1; k <= n-j; k++)
                    {
                        q = q * 10;
                    }
                    
                    d = (current / q) % 10;

                    if (d != 2 && d != 7)
                    {
                        surroundings = false;
                        if (i > 1 && (upRow / q) % 10 == 7)
                        {
                            surroundings = true;
                        }
                        if (i < n && (downRow / q) % 10 == 7)
                        {
                            surroundings = true;
                        }
                        if (j > 1 && (current / (q*10)) % 10 == 7)
                        {
                            surroundings = true;
                        }
                        if (j < n && (current / (q / 10)) % 10 == 7)
                        {
                            surroundings = true;
                        }

                        if (surroundings == true)
                        {
                            if (d == G)
                            {
                                gcount++;
                            }
                            if (d == E)
                            {
                                exit = true;
                            }
                            current += (7 - d) * q;
                            reached = true;
                        }
                    }
                }
                
                if (i == 1)
                {
                    r1 = current;
                }
                else if (i == 2)
                {
                    r2 = current;
                }
                else if (i == 3)
                {
                    r3 = current;
                }
                else if (i == 4)
                {
                    r4 = current;
                }
                else if (i == 5)
                {
                    r5 = current;
                }
                else if (i == 6)
                {
                    r6 = current;
                }
                else if (i == 7)
                {
                    r7 = current;
                }
                else if (i == 8)
                {
                    r8 = current;
                }
                else if (i == 9)
                {
                    r9 = current;
                }
                else
                {
                    r10 = current;
                }   
            }
        } while(reached);


        if (exit == true)
        {
            cout<<"Solvable: Yes"<<endl;
        }
        else{
            cout<<"Solvable: No"<<endl;
        }

        cout<<"Gold Reachable: "<<gcount<<endl;
    }
    else{
        cout<<"Invalid Input!"<<endl;
    }
}

