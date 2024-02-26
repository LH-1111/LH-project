/*
3.10.1 案例描述

公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入  key(部门编号) value(员工)
分部门显示员工信息

3.10.2 实现步骤

1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
4. 分部门显示员工信息
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
using namespace std;

class MyCompare
{
public:
    bool operator()(string v1, string v2)
    {
        return v1 > v2;
    }
};

class worker
{
public:
    string m_name;
    float m_salary;
    string m_department;
    worker() {}
    worker(string name, float salary, string department)
    {
        this->m_name = name;
        this->m_salary = salary;
        this->m_department = department;
    }
};
vector<worker> creatework()
{
    vector<worker> workers;
    string temp = "ABCDEFGHIJ";

    for (int i = 0; i < 10; i++)
    {
        worker workertemp;

        if (0 == (i % 2))
        {
            workertemp = worker(string(1, temp[i]), 200.00, "策划");
        }
        else if (0 == (i % 5))
        {
            workertemp = worker(string(1, temp[i]), 300.00, "美术");
        }
        else
        {
            workertemp = worker(string(1, temp[i]), 100.00, "研发");
        }
        workers.push_back(workertemp);
    }

    return workers;
}
void printvector(const vector<worker> &listperson)
{
    for (vector<worker>::const_iterator it = listperson.begin(); it != listperson.end(); it++)
    {
        cout << it->m_name << " "
             << "\t" << it->m_salary << "\t"
             << " " << it->m_department << endl;
    }

    cout << endl;
}

void printMap(const multimap<string, worker, MyCompare> &multimaptemp)
{
    for (multimap<string, worker, MyCompare>::const_iterator it = multimaptemp.begin(); it != multimaptemp.end(); it++)
    {
        cout << "key :" << it->first << " "
             << it->second.m_name << " "
             << "\t" << it->second.m_salary << "\t"
             << " " << it->second.m_department << endl;
    }
    cout << endl;
}
int main()
{
    vector<worker> workers = creatework();
    multimap<string, worker, MyCompare> workers_map;
    multimap<string, worker, MyCompare> workers_map1;
    multimap<string, worker, MyCompare> workers_map2;
    for (int i = 0; i < workers.size(); i++)
    {
        if (workers[i].m_department == "策划")
        {
            workers_map.insert(make_pair(workers[i].m_department,workers[i]));
        }
        else if (workers[i].m_department == "研发")
        {
            workers_map1.insert(make_pair(workers[i].m_department, workers[i]));
        }
        else
        {
            workers_map2.insert(make_pair(workers[i].m_department, workers[i]));
        }
    }
    printMap(workers_map);
    printMap(workers_map1);
    printMap(workers_map2);

}