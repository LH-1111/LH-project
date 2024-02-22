#include<iostream>
using namespace std ;



struct Hero
{
    string name;
    int age;
    string sex;
};
void paixu(Hero * hero , int len);
void show(Hero * hero , int len);

int main(){
    Hero heroarr[5] = {
        {"张三1" , 11 , "男"},
        {"张三2" , 231, "男"},
        {"张三3" , 141, "男"},
        {"张三4" , 432, "男"},
        {"张三5" , 124, "男"},
    };
    int len = sizeof(heroarr)/sizeof(heroarr[0]);
    cout << len << endl;
    Hero * h = &heroarr[0];
    show(h,5);
    return 0;
}

void paixu(struct Hero * hero , int len){
   for(int i ; i < len-1; i++){
       for (int j = 0; j < len-1 -j; j++)
       {
           if(hero[j].age < hero[j+1].age ){
               int temp = hero[j].age;
               hero[j].age = hero[j+1].age;
               hero[j+1].age = temp;
           }

       }
   }
}

void show(struct Hero * hero , int len){
   for(int i ; i < len-1; i++){
       cout << hero[i].name<<endl;
       cout << hero[i].age<<endl;
       cout << hero[i].sex<<endl;
   }
}

