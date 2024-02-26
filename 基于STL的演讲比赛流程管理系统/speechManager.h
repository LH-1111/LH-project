#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "competitor.h"

class speechManager
{
public:
    speechManager();
    void showmenu();
    void initSpeech();
    ~speechManager();
     
    vector<int> v1;

    vector<int> v2;
    vector<int> victoryers;

    map<int , competitor> maps;

    
};
