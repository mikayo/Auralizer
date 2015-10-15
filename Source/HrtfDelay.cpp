#include "HrtfDelay.h"

HrtfDelay::HrtfDelay ()
{
    fstream myfile;
    myfile.open("/Users/Mika/Documents/Xcode/Auralizer/Source/delay.txt");
    string line;
    string word;
    for(int i = 0; i<36; i++){
        for(int j=0; j<2;j++){
            getline(myfile, line);
            stringstream ssin(line);
            ssin >> word;
            float temp = ::atof(word.c_str());
            delaytable[j][i]=temp;
        }
    }
}

HrtfDelay::~HrtfDelay (){};

float HrtfDelay::get(int lr, int ang)
{
    if (ang == 36)
        ang = 0;
    return delaytable[lr][ang];
}