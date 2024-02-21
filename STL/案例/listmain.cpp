// 3.7.8 排序案例
// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
class Person
{
private:
    /* data */
public:
    string m_name;
    int m_age;
    float m_high;
    Person(string name, int age, float high)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_high = high;
    }
    ~Person(){}
};
bool compareage(Person a, Person b){
    if (a.m_age==b.m_age) 
    {
        return a.m_high<b.m_high;
    }else{
        return a.m_age<b.m_age;
    }
    
    return a.m_age<b.m_age;
}
void printlist(const list<Person> &listperson)
{
    for (list<Person>::const_iterator it = listperson.begin(); it != listperson.end(); it++)
    {
        cout << it->m_name << " "<<"\t" << it->m_age <<"\t"<< " " << it->m_high << endl;
    }
}
int main()
{
    list<Person> listperson;
    listperson.push_back(Person("三", 58, 1.88));
    listperson.push_back(Person("四", 19, 1.79));
    listperson.push_back(Person("五", 5, 2.10));
    listperson.push_back(Person("六", 21, 2.15));
    listperson.push_back(Person("六", 21, 2.16));
    listperson.push_back(Person("六", 21, 2.14));
    listperson.sort(compareage);
    printlist(listperson);

}