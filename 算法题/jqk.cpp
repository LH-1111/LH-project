/*扑克牌算法*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getmax(const vector<int> &list)
{
}
void print_list(vector<int> list)
{
    for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
        /* code */
    }
    cout << endl;
}
int main()
{
    int num = 0;
    cout << "请输入牌的张数:";
    while (true)
    {
        cin >> num;
        if (num <= 15 || num <= 0)
        {
            break;
        }
        else
        {
            cout << "请输入正确的牌的张数:";
        }
    }
    vector<int> points;
    for (int i = 0; i < num; i++)
    {
        int temp = 0;
        cout << "请输入第" << i + 1 << "张牌的点数:";
        cin >> temp;
        if (temp == 0)
        {
            temp = 10;
        }
        points.push_back(temp);
    }
    print_list(points);
}