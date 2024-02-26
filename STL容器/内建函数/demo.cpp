#include <iostream>
#include <functional>
using namespace std;

void test(){

    negate<int> n;
    int temp = n(10);
    cout<<temp<<endl;

    plus<int> p ;
    int max = p(10,9);
    cout<<max<<endl;
}


void test01(){

}

int main(){
    test();
    return 0;

}