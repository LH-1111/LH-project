#include "competitor.h"

competitor::competitor(string name,double x[2]){
    this->m_name = name;
    this->m_value[0] = x[0];
    this->m_value[1] = x[1];
}


competitor::competitor(){
}
