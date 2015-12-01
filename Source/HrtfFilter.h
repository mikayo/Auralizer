#ifndef HRTFFILTER_H_INCLUDED
#define HRTFFILTER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "HrtfOpen.h"
#include "HrtfDelay.h"

class HrtfFilter
{
public:
    HrtfFilter ();
    ~HrtfFilter ();
    void set ();
    void setAngle (float newAngle);
    float getAngle ();
    float interpolate (float upperCoef, float lowerCoef);
    float *getCoefs (int channel);
    void ClockProcess (float* leftData, float* rightData, int bufferLength);
    
private:
    float filterCoefs[2][100];
    float currentAngle;
    float previousAngle;
    float lPreviousDelay;
    float lCurrentDelay;
    float rPreviousDelay;
    float rCurrentDelay;
    
    // delay buffer
    AudioSampleBuffer delayBuffer;
    int delayBufferLength;
    int leftReadPosition, leftWritePosition, rightReadPosition, rightWritePosition;
    
    // filter classes
    HrtfOpen hrtfBuffer;
    HrtfDelay hrtfDelay;
};

#endif  // HRTFFILTER_H_INCLUDED
