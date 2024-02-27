#include "speechManager.h"

using namespace std;

speechManager::speechManager()
{
    this->initSpeech();
    this->createCompetitor();
}
void speechManager::showmenu()
{
    cout << "-------------------------------------------------" << endl;
    cout << "------------------1. 开始演讲比赛----------------" << endl;
    cout << "------------------2. 查看往届记录----------------" << endl;
    cout << "------------------3. 清空比赛记录----------------" << endl;
    cout << "------------------4. 退出比赛程序----------------" << endl;
    cout << "-------------------------------------------------" << endl;
}

void speechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->victoryers.clear();
    this->maps.clear();
    this->index = 1;
}

void speechManager::createCompetitor()
{
    string temp = "ABCDEFGHIJKL";
    for (int i = 0; i < temp.size(); i++)
    {
        competitor compe;
        string name = "student";
        name += temp[i];
        double x[2] = {0, 0};
        compe = competitor(name, x);
        this->v1.push_back(i + 10001);
        this->maps.insert(make_pair(i + 10001, compe));
    }
}

void speechManager::startGame()
{
    // one
    //
    beforeStart();
    speechContest();
    showScore();
    this->index++;
    beforeStart();
    speechContest();
    showScore();
    saveRecord();
    cout << "game over" << endl;
}

void speechManager::beforeStart()
{
    cout << "第" << this->index << "轮" << endl;
    cout << "-----------------------" << endl;
    cout << "抽签之后的顺序:" << endl;
    if (this->index == 1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
}

void speechManager::speechContest()
{

    cout << this->index << "  "
         << "game start" << endl;
    multimap<double, int, greater<int>> groupScore;
    vector<int> tempv;
    int num = 0;
    if (this->index == 1)
    {
        tempv = v1;
    }
    else
    {
        tempv = v2;
    }
    for (vector<int>::iterator it = tempv.begin(); it != tempv.end(); it++)
    {
        deque<double> sorces;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            // cout << score<<"  \t ";
            sorces.push_back(score);
        }
        sort(sorces.begin(), sorces.end());
        sorces.pop_front();
        sorces.pop_back();
        float avg = (accumulate(sorces.begin(), sorces.end(), 0.0f)) / ((float)sorces.size());
        // *it->second[this->index -1 ] = avg;
        this->maps[*it].m_value[this->index - 1] = avg;

        groupScore.insert(make_pair(avg, *it));
        num++;
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号: " << it->second << " 姓名： " << this->maps[it->second].m_name << " 成绩： " << this->maps[it->second].m_value[this->index - 1] << endl;
            }
            int count = 0;
            // 取前三名
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    victoryers.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "------------- 第" << this->index << "轮比赛完毕  ------------- " << endl;
}

void speechManager::showScore()
{
    cout << "---------第" << this->index << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v;
    if (this->index == 1)
    {
        v = v2;
    }
    else
    {
        v = victoryers;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号：" << *it << " 姓名： " << maps[*it].m_name << " 得分： " << maps[*it].m_value[this->index - 1] << endl;
    }
    cout << endl;
    this->showmenu();
}

void speechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("record.txt", ios::out | ios::app);
    for (vector<int>::iterator it = this->victoryers.begin(); it != this->victoryers.end(); it++)
    {
        {
            ofs << *it << ","
                << maps[*it].m_value[1] << ",";
        }
        ofs << endl;
        // 关闭文件     
    }
    ofs.close();
    cout << "记录已经保存" << endl;
}
speechManager::~speechManager()
{
}
