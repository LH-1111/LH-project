#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(0);
    cout << a.size() << endl;
    cout<<a.capacity() << endl;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    cout << endl;
    cout << a.size() << endl;
    cout<<a.capacity() << endl;
    cout << endl;

    return 0;
}