#pragma once
#include <iostream>
#include <string>
using namespace std;

class competitor
{
public: 
    string m_name;
    float m_value[2];
    competitor();
    competitor(string name, float value1[2]);
};
