//
//  main.h
//  hrtf
//
//  Created by Kosonen Mika on 11/10/15.
//  Copyright (c) 2015 Kosonen Mika. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef hrtf_main_h
#define hrtf_main_h

class HrtfOpen
{
public:
    HrtfOpen ();
    ~HrtfOpen ();
    float getValue (int lr, int ang, int val);
    float *getFilter (int lr, int ang);
    int getLength ();
    
private:
    float table[2][36][100];
    int filterLength;
};

#endif




