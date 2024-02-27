#pragma once
#include <iostream>
#include <string>
using namespace std;

class competitor
{
public: 
    string m_name;
    double m_value[2];
    competitor();
    competitor(string name, double value1[2]);
};;
