#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "competitor.h"

class speechManager
{
public:
    speechManager();
    void showmenu();
    void initSpeech();
    void startGame();

    void beforeStart();
    void createCompetitor();
    ~speechManager();

    vector<int> v1;

    vector<int> v2;
    vector<int> victoryers;

    map<int, competitor> maps;
    int index;
};
