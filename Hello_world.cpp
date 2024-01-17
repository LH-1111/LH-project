#include<iostream>
#include<string>
using namespace std;

#define day 24

int main(){
    printf("day : %d " , day);
    // int day = 23;
    cout << "day : " << day << endl;
    int month = 12;

    cout << "month : " << month << endl;
    month = 13 ;
    cout << "month : " << month << endl;
    short max = 32768;
    cout << "max : " << max << endl;


    cout << "short : " << sizeof(short) << endl;
    cout << "int : " << sizeof(int) << endl;
    cout << "long : " << sizeof(long) << endl;
    cout << "long long : " << sizeof(long long) << endl;


    float f = 3.14f ; 
    cout << "f : " << f << endl;
    cout << "float : " << sizeof(float) << endl;
    double d = 3.141591111111111111111 ; 
    cout << "d : " << d << endl;
    cout << "double : " << sizeof(double) << endl;

    char a = '+';
    cout << "a : " << a << endl;
    cout << "a ascll nume : " << (int)a << endl;
    cout << "char : " << sizeof(char) << endl;

    //C风格的字符串
    char str[] = "Hello world" ;
    cout << "str : " << str << endl;
    cout << "str size： " << sizeof(str) << endl;
    
    //C++ 风格
    string str2 = "Hello world2";
    cout << "str2 : " << str2 << endl;

    bool bool1 = true;
    bool bool2 = false;
    cout << "bool1 : " << (int)bool1 << endl;
    cout << "bool2 : " << (int)bool2 << endl;

    //控制台输入数据
    int x , y ,z;
    cout << "第一个数 : "<< endl;
    cin >> x ;
    cout << "第二个数 : "<< endl;
    cin >> y ;
    cout << "第三个数 : "<< endl;
    cin >> z ;
    
    int maxnume ;
    if(x>y&&x>z) max = x;
    if(y>x&&y>z) max = y;
    if(z>x&&z>y) max = z;
    cout << "最大的数 : "<< max << endl;

    int h = x > y ? 10 : 100 ;
    cout << "最大的数 : "<< h << endl;

    int num1 = 10;
    int num2 = 23;
    cout << num2 / num1 << endl;
    cout << num2 % num1 << endl;

    int nume = 10 ;
    int b = nume++;
    int c = ++nume;

    cout << "b : " << b << endl;
    cout << "c : " << c << endl;
    cout << (b == c) << endl;

    return 1;
}