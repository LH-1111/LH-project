#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(int argc, char *argv[]) {
    stack<int> s;
    s.push(10);
    s.push(2);
    int i = s.top();
    int j = s.top()-1;
    cout << j << endl;
    cout << "栈的大小为：" << s.size() << endl;
    s.pop();
    cout << "栈的大小为：" << s.size() << endl;
    return 0;
}