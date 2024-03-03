// 给n个数求他们中所有基数的乘积
// input
// 输入数据包含多个测试用例，每个测试用例占一行，每行的第一个数为n，代表本组数据一共有n个，接着是n个数
// output
// 输出每组数中的所有奇数的乘积，输出一行

#include <iostream>
#include <vector>
using namespace std;
// int main()
// {
//     int num;
//     cout << "input test num :";
//     cin >> num;
//     vector<int> vec[num];
//     for (int i = 0; i < num; i++)
//     {
//         cout << "第" << i + 1 << "组数据的输入个数:";
//         int n;
//         cin >> n;
//         for (int j = 0; j < n; j++)
//         {
//             int temp;
//             cin >> temp;
//             vec[i].push_back(temp);
//         }
//     }
//     for (int i = 0; i < num; i++)
//     {
//         int result = 1;
//         for (int j = 0; j < vec[i].size(); j++)
//         {
//             if (vec[i][j] % 2 != 0)
//             {
//                 result *= vec[i][j];
//             }
//         }
//         cout << "第" << i + 1 << "数据的结果：" << result << endl;
//     }
// }

int main()
{
    int num;
    int a[100000];
    while (cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            int x;
            cin >> x;
            a[i] = x;

            /* code */
        }
        int result = 1;
        for (int i = 0; i < num; i++)
        {
            if (a[i] % 2 != 0)
            {
                result *= a[i];
            }
        }
        cout << result << endl;

        /* code */
    }
    return 0;
}