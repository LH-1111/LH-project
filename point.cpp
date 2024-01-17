#include<iostream>
using namespace std ;


void dubbsort (int * arr ,int len);
void show(int * arr ,int len);

void swap(int * p ,int *p2){
    int temp = *p;
    *p = *p2;
    *p2 = temp;
}
int main(){
    int a = 20;
    int b = 30;
    int * p = &a;
    cout << a << endl;
    cout << * p << endl;

    cout << &a << endl;
    cout << p << endl;
    
    cout << "int占用空间：" << sizeof(int *) << endl;
    cout << "char占用空间：" << sizeof(char *) << endl;
    cout << "double占用空间：" << sizeof(double *) << endl;
    cout << "long long占用空间：" << sizeof(long long *) << endl;


    int * p2 = NULL ;
    cout << "p2：" << p2 << endl;

    p2 = &a;
    cout << "p2：" << p2 << endl;
    cout << "p2：" << *p2 << endl;

    //常量指针
    const int * p3 = &a;
    p3 = &b;
    cout << "p3 : " << *p3 << endl;

    //指针常量
    int * const p4 = &a;
    *p4 = 50;
    cout << "p4 -a : " << a << endl;
    cout << "p4 : " << *p4 << endl;




    int num [5] = {0,1,2,3,4};
    int * num2 = num;
    cout << "num2 : " << *num2 << endl;
    cout << "num2 : " << ++ *num2 << endl; 

    swap(&a,&b);
    cout << "swap a : " <<a << endl;
    cout << "swap b: " << b << endl; 




    int arr[10] = {1,234,12,4,123,4,123,14,123,241234};
    int len = sizeof(arr)/sizeof(arr[0]);
    dubbsort(arr,len);
    show(arr,len);
    return 1;
}

void dubbsort (int * arr ,int len){
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
}

void show(int * arr ,int len){
    for (int i = 0; i < len-1; i++)
    {
        cout<< arr[i] << endl;
    }

}