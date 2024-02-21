/*输入描述：
输入第一行包含两个整数n、m(0<n,m<21),分别表示n行m列的矩阵，第二行时长度不超过100的单词W（在整个矩阵中给定单词只会出现一次），从第三行到到第n+2行时只包含大小写英文字母的长度为m的字符串矩阵。

输出描述：
如果能在矩阵中连成给定的单词，则输出给定单词首字母在矩阵中的位置（第几行 第几列），否则输出“NO”*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printString(vector<string> &stringmap)
{
    // for (vector<string>::iterator it = stringmap.begin(); it != stringmap.end(); it++)
    // {
    //     cout<<"stringmap :"<< *it<<endl;
    // }
    cout << "stringmap size :" << stringmap.size() << endl;
    for (int i = 0; i < stringmap.size(); i++)
    {
        cout << "stringmap :" << stringmap[i] << endl;
    }
}
string foundWrold(vector<string> &stringmap, string findWord, int row, int list)
{
    string ret = "查找失败";
    for (int i = 0; i < row; i++)
    {
        if (stringmap[i].size() != list)
        {
            ret = "长度不匹配";
            break;
        }
        string demo = stringmap[i];
        int pos = demo.find(findWord);
        if (pos != -1)
        {
            ret.append(to_string(i));
            ret.append(to_string(pos));
        }
    }

    return ret;
}
int main()
{
    int row, list;
    cout << "请输入行：";
    cin >> row;
    cout << "请输入列：";
    cin >> list;
    string str;
    cout << "请输入查找str:";
    cin >> str;
    string findword = str.substr(0, 1);
    cout << "findword:" << findword << endl;
    vector<string> strmap(row);
    for (int i = 0; i < list; i++)
    {
        cin >> strmap[i];
    }
    string result = foundWrold(strmap, findword, row, list);
    // printString(strmap);
    cout << result << endl;
}