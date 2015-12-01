#include "PitchControl.h"

//==================================================================
PitchControl::PitchControl ()
{
    pitchBufferLength = 44100;
    leftReadPosition = 0;
    leftWritePosition = 1;
    rightReadPosition = 0;
    rightWritePosition = 1;
    
    pitchBuffer.setSize(2, pitchBufferLength);
    pitchBuffer.clear();
};

PitchControl::~PitchControl (){};

//==================================================================
void PitchControl::ClockProcess(float *leftData, float *rightData, int bufferLength, int speed)
{
    int lrp, lwp, rrp, rwp;
    lrp = leftReadPosition;
    lwp = leftWritePosition;
    rrp = rightReadPosition;
    rwp = rightWritePosition;
    
    float* leftPitchPointer = pitchBuffer.getWritePointer(0);
    float* rightPitchPointer = pitchBuffer.getWritePointer(1);
    
    for (int n = 0; n < bufferLength; n++)
    {
        leftPitchPointer[lwp] = leftData[n];
        rightPitchPointer[rwp] = rightData[n];
        
        leftData[n] = leftPitchPointer[lrp];
        rightData[n] = rightPitchPointer[rrp];
        
        // advance pointers
        lrp += speed + pitchBufferLength % pitchBufferLength;
        rrp += speed + pitchBufferLength % pitchBufferLength;
        
        lwp += 1 + pitchBufferLength % pitchBufferLength;
        rwp += 1 + pitchBufferLength % pitchBufferLength;
    }
    
}
