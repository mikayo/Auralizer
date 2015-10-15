#include "HrtfFilter.h"
#include "math.h"
#include <iostream>

//==================================================================
HrtfFilter::HrtfFilter ()
{
    currentAngle = 0.0f;
    previousAngle = 0.0f;
    lCurrentDelay = 0;
    lPreviousDelay = 0;
    rCurrentDelay = 0;
    rPreviousDelay = 0;
    
    delayBufferLength = 512;
    leftReadPosition = 0;
    leftWritePosition = 1;
    rightReadPosition = 0;
    rightWritePosition = 1;
    
    delayBuffer.setSize(2, delayBufferLength);
    delayBuffer.clear();
    
};

HrtfFilter::~HrtfFilter (){};

// ================================================================
void HrtfFilter::set ()
{
    leftWritePosition = (int)hrtfDelay.get(0, 0);
    rightWritePosition = (int)hrtfDelay.get(1, 0);
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            filterCoefs[i][j] = hrtfBuffer.getValue(i, 0, j);
        }
    }
}

void HrtfFilter::setAngle (float newAngle)
{
    previousAngle = currentAngle;
    currentAngle = newAngle;
}

float HrtfFilter::getAngle ()
{
    return currentAngle;
}

float HrtfFilter::interpolate(float upperCoef, float lowerCoef)
{
    float coefDifference;
    float lowerAngle;
    
    lowerAngle = 10 * floor(currentAngle / 10);
    
    coefDifference = upperCoef - lowerCoef;
    
    return lowerCoef + (coefDifference / 10.0f) * (currentAngle - lowerAngle);
}

float* HrtfFilter::getCoefs(int channel)
{
    return filterCoefs[channel];
}

void HrtfFilter::ClockProcess (float* leftData, float* rightData, int bufferLength)
{
    float ltmp, rtmp;
    float lLowerDelay, lUpperDelay, rLowerDelay, rUpperDelay;
    float lDelayDifference, rDelayDifference;
    int lrp, lwp, rrp, rwp;
    lrp = leftReadPosition;
    lwp = leftWritePosition;
    rrp = rightReadPosition;
    rwp = rightWritePosition;
    
    // delay pointers
    float* lDelayPointer = delayBuffer.getWritePointer(0);
    float* rDelayPointer = delayBuffer.getWritePointer(1);
    
    // update delays
    if (currentAngle != previousAngle)
    {
        lPreviousDelay = lCurrentDelay;
        rPreviousDelay = rCurrentDelay;
        
        lLowerDelay = hrtfDelay.get(0, (int)currentAngle/10);
        lUpperDelay = hrtfDelay.get(0, (int)(currentAngle/10)+1);
        rLowerDelay = hrtfDelay.get(1, (int)currentAngle/10);
        rUpperDelay = hrtfDelay.get(1, (int)(currentAngle/10)+1);
        
        lCurrentDelay = interpolate(lUpperDelay, lLowerDelay);
        rCurrentDelay = interpolate(rUpperDelay, rLowerDelay);
        
        lDelayDifference = lCurrentDelay - lPreviousDelay;
        rDelayDifference = rCurrentDelay - rPreviousDelay;
    
        lrp -= (int)lDelayDifference + delayBufferLength % delayBufferLength;
        
        rrp -= (int)rDelayDifference + delayBufferLength % delayBufferLength;
    }
    
    // filter vectors
    
    float *lLowerHrtf = hrtfBuffer.getFilter(0, (int)currentAngle/10);
    float *rLowerHrtf = hrtfBuffer.getFilter(1, (int)currentAngle/10);
    float *lUpperHrtf = hrtfBuffer.getFilter(0, (int)(currentAngle/10)+1);
    float *rUpperHrtf = hrtfBuffer.getFilter(1, (int)(currentAngle/10)+1);
    int filterLength = hrtfBuffer.getLength();
    
    float *lFilterBuffer = getCoefs(0);
    float *rFilterBuffer = getCoefs(1);
    
    for (int n = 0; n < bufferLength; n++)
    {
        // write input to delay buffers
        lDelayPointer[lwp] = leftData[n];
        rDelayPointer[rwp] = rightData[n];
        
        // filter interpolation
        if (currentAngle != previousAngle)
        {
            if (n < filterLength)
            {
                lFilterBuffer[n] = interpolate(lUpperHrtf[n], lLowerHrtf[n]);
                rFilterBuffer[n] = interpolate(rUpperHrtf[n], rLowerHrtf[n]);
            }
        }
        
        // filtering
        ltmp = 0.0f;
        rtmp = 0.0f;
        for (int i = 0; i < filterLength; i++)
        {
            // left channel
            if (lrp - i < 0)
                ltmp += lDelayPointer[lrp - i + delayBufferLength] * lFilterBuffer[i];
            else
                ltmp += lDelayPointer[lrp - i] * lFilterBuffer[i];
            
            // right channel
            if (rrp - i < 0)
                rtmp += rDelayPointer[rrp - i + delayBufferLength] * rFilterBuffer[i];
            else
                rtmp += rDelayPointer[rrp - i] * rFilterBuffer[i];
        }
        
        // write output
        leftData[n] = ltmp;
        rightData[n] = rtmp;
        
        // advance pointers
        if (lrp == delayBufferLength)
            lrp = 0;
        else
            ++lrp;
        if (lwp == delayBufferLength)
            lwp = 0;
        else
            ++lwp;
        if (rrp == delayBufferLength)
            rrp = 0;
        else
            ++rrp;
        if (rwp == delayBufferLength)
            rwp = 0;
        else
            ++rwp;
    }
    
    // update delay buffer pointers
    leftReadPosition = lrp;
    leftWritePosition = lwp;
    rightReadPosition = rrp;
    rightWritePosition = rwp;
}



















