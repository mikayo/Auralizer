#ifndef PITCHSHIFT_H_INCLUDED
#define PITCHSHIFT_H_INCLUDED

void smbFft(float *fftBuffer, long fftFrameSize, long sign);
double smbAtan2(double x, double y);
void smbPitchShift(float pitchShift, long numSampsToProcess, long fftFrameSize, long osamp, float sampleRate, float *indata, float *outdata);


#endif  // PITCHSHIFT_H_INCLUDED
