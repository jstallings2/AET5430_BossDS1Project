/*
  ==============================================================================

    DS1DistortionEffect.cpp
    Created: 16 Apr 2023 8:11:05am
    Author:  Jacob Stallings

  ==============================================================================
*/

#include "DS1DistortionEffect.h"

float DS1DistortionEffect::processSample(float x, const int c) {
    
    if(IS_SIMPLE_DIST)
        x = (2.f/M_PI) * atan(x * (9*getDist()+1));
    return x;
    
}

void DS1DistortionEffect::prepareToPlay(float sampleRate, int samplesPerBlock){
    sDist.reset(sampleRate, 0.1); // 100 ms smoothing response time
    sLevel.reset(sampleRate, 0.1);
    super::prepareToPlay(sampleRate, samplesPerBlock); // let AudioEffect do the rest
}

float DS1DistortionEffect::getDist() { return sDist.getNextValue(); }

void DS1DistortionEffect::setDist(float dist) {
    sDist.setTargetValue(dist);
}

float DS1DistortionEffect::getLevel() { return sLevel.getNextValue(); }

void DS1DistortionEffect::setLevel(float level) {
    sLevel.setTargetValue(level);
}




