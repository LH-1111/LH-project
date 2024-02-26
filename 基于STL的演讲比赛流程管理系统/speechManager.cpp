#include "speechManager.h"
using namespace std;

speechManager::speechManager(){
    initSpeech();

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


void speechManager::initSpeech(){
    this->v1.clear();
    this->v2.clear();
    this->victoryers.clear();
    this->maps().clear();
}
speechManager::~speechManager(){
    
}

