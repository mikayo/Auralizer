#ifndef PITCHCONTROL_H_INCLUDED
#define PITCHCONTROL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PitchControl
{
public:
    PitchControl ();
    ~PitchControl ();
    void ClockProcess (float* leftData, float* rightData, int bufferLength, int speed);
private:
    AudioSampleBuffer pitchBuffer;
    int pitchBufferLength;
    int leftReadPosition, leftWritePosition, rightReadPosition, rightWritePosition;
};

#endif  // PITCHCONTROL_H_INCLUDED
