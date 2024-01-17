#include <iostream>
using namespace std;
#define PI 3.14
class Circle
{
    // 权限
public:
    //属性
    int R;

    //行为
    double zhouchang()
    {
        return 2 * PI * R;
    }
};
int main()
{
    Circle c;
    c.R = 5;
    double max = c.zhouchang();
    cout << max << endl;
}