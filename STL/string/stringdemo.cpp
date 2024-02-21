#include <iostream>
using namespace std;

// * `string& operator=(const char* s);`             //char*类型字符串 赋值给当前的字符串
// * `string& operator=(const string &s);`         //把字符串s赋给当前的字符串
// * `string& operator=(char c);`                          //字符赋值给当前的字符串
// * `string& assign(const char *s);`                  //把字符串s赋给当前的字符串
// * `string& assign(const char *s, int n);`     //把字符串s的前n个字符赋给当前的字符串
// * `string& assign(const string &s);`              //把字符串s赋给当前字符串
// * `string& assign(int n, char c);`                  //用n个字符c赋给当前字符串

void test()
{
    string s1 = "hello world";
    cout << "s1 = " << s1 << endl;
    string s2 = s1;
    cout << "s2 = " << s2 << endl;
    string s3;
    s3 = 'a';
    cout << "s3 = " << s3 << endl;

    string s4;
    s4.assign(s1);
    cout << "s4 = " << s4 << endl;
    s4.assign(s1.c_str(), 5);
    cout << "s42 = " << s4 << endl;

    string s5;
    s5.assign(5, 'a');
    cout << "s5 = " << s5 << endl;

    string str6;
    str6.assign("hello c++", 5);
    cout << "str6 = " << str6 << endl;
}

void test01()
{
    string str1 = "我";

    str1 += "爱玩游戏";

    cout << "str1 = " << str1 << endl;

    str1 += ':';

    cout << "str1 = " << str1 << endl;

    string str2 = "LOL DNF";

    str1 += str2;

    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    str3.append("game abcde", 4);
    // str3.append(str2);
    str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
    cout << "str3 = " << str3 << endl;
}

// // string find function
// * `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
// * `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
// * `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
// * `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
// * `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
// * `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
// * `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
// * `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
// * `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
// * `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
void find()
{
    string str1 = "hello world aaaaaaaaaa";

    int ret = str1.find("hea");
    cout << "ret = " << ret << endl;

    int pos = str1.rfind("e");
    cout << "pos = " << pos << endl;
}

void replace()
{
    string str1 = "hello world aaaaaaaaaa";
    str1.replace(0, 5, "bbbbbbbbb");
    cout << "str1 = " << str1 << endl;
}

void compare()
{
    string str1 = "xello world aaaaaaaaaa";
    string str2 = "hello world aaaaaaaaaa";
    if (0 == str1.compare(str2))
    {
        cout << "string is same" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 > str2" << endl;
    }
}

void save()
{
    string str = "hello ";
    cout << "str :" << str << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << endl;
    }
    str[0] = 'l';
    cout << str << endl;
}
// * `string& insert(int pos, const char* s);  `                //插入字符串
// * `string& insert(int pos, const string& str); `        //插入字符串
// * `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
// * `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符
void insert()
{
    string str = "hello";
    str.insert(0, "aaa");
    cout << str << endl;
}
int main()
{
    insert();
    return 0;
}