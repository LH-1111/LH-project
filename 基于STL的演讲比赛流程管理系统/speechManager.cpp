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
    this->index = 0;
}

void speechManager::createCompetitor()
{
    string temp = "ABCDEFGHIJKL";
    for (int i = 0; i < temp.size(); i++)
    {
        competitor compe;
        string name = "student";
        name += temp[i];
        float x[2] = {0, 0};
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
}

void speechManager::beforeStart()
{
    cout << "第" << this->index << "轮" << endl;
    cout << "-----------------------" << endl;
    cout << "抽签之后的顺序" << endl;
    if (this->index == 0)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it<<"  " ;
        }
        cout << endl;
    }
    else
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it ;
        }
        cout << endl;
    }
}
speechManager::~speechManager()
{
}
