// 3.4.1 案例描述
// 有5名选手：选手ABCDE,10个评委分别对每一名选手打分,去除最高分，去除评委中最低分，取平均分。

// 3.4.2 实现步骤
// 1. 创建五名选手,放到vector中
// 2. 遍历vector容器,取出来每一个选手,执行for循环,可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序,去除最高和最低分
// 4. deque容器遍历一遍,累加总分
// 5. 获取平均分

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:
    string m_name;
    deque<int> score;
    Person(string name)
    {
        this->m_name = name;
    }
    void setscore()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "第" << i + 1 << "位评委打分：";
            int temp;
            cin >> temp;
            this->score.push_back(temp);
        }
    }
    void showscore()
    {
        for (int i = 0; i < this->score.size(); i++)
        {
            cout << this->score[i] << " ";
        }
        cout << endl;
    }
    float getscore()
    {
        sort(this->score.begin(), this->score.end());
        cout << "去除最高分：" << score.back() << endl;
        cout << "去除最低分：" << score.front() << endl;
        score.pop_back();
        score.pop_front();
        this->showscore();
        float num = 0;
        for (deque<int>::iterator it = score.begin(); it != score.end(); it++)
        {
            num += *it;
        }
        cout << "num:" << num << endl;
        cout << "size:" << this->score.size() << endl;
        float sorceP = num / this->score.size();
        return sorceP;
    }
};
int main()
{
    vector<Person> v;
    Person p1("A");
    Person p2("B");
    Person p3("C");
    Person p4("D");
    Person p5("E");
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "选手：" << v[i].m_name << endl;
        v[i].setscore();
        v[i].showscore();
        float sorce = v[i].getscore();
        cout << "选手平均分：" << sorce << endl;
    }
}
