#include "HrtfOpen.h"

//==================================================================
HrtfOpen::HrtfOpen ()
{
    filterLength = 100;

    fstream myfile;
    for(int k=0; k<2; k++){
        if(k==0){
            myfile.open("/Users/Mika/Documents/Xcode/Auralizer/Source/Lhrtf.txt");
        }
        if(k==1){
            myfile.open("/Users/Mika/Documents/Xcode/Auralizer/Source/Rhrtf.txt");
        }
        string line;
        int i = 0;
        int n = 0;
        string word;
        while (getline(myfile, line)) {//checks each line in file and saves them to line parameter
            stringstream ssin(line);
            i = 0;
            while (ssin.good() && i < 100) {//pushes every word in line to filter table
                ssin >> word;
                float temp = ::atof(word.c_str());//converts words to floats
                table[k][n][i]=temp;
                i++;
            }
            n++;
        }
        myfile.close();
    }
}

HrtfOpen::~HrtfOpen (){};

//==================================================================

float HrtfOpen::getValue (int lr, int ang, int val)
{
    if (ang == 36)
        ang = 0;
    return table[lr][ang][val];
}

float* HrtfOpen::getFilter (int lr, int ang)
{
    if (ang == 36)
        ang = 0;
    return table[lr][ang];
}

int HrtfOpen::getLength ()
{
    return filterLength;
}
