#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef HRTFDELAY_H_INCLUDED
#define HRTFDELAY_H_INCLUDED

class HrtfDelay
{
public:
    HrtfDelay();
    ~HrtfDelay();
    float get(int lr, int ang);
    
private:
    float delaytable[2][36];
};

#endif  // HRTFDELAY_H_INCLUDED
