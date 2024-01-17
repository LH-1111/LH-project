#include<iostream>
#include<string>
using namespace std ;


struct Student
{
    string name;
    int age;
    int score;
};

void show(Student * student);

int main(){
    Student student ;
    student.name = "aaaa" ;
    student.age = 1 ;
    student.score = 2 ;
    
    show(&student);
    return 0;
}


void show(struct Student * p ){
       cout << p->name<<endl;
       cout << p->age<<endl;
       cout << p->score<<endl;

}
