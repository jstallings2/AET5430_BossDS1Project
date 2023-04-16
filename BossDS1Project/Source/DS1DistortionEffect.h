/*
  ==============================================================================

    DS1DistortionEffect.h
    Created: 16 Apr 2023 8:11:05am
    Author:  Jacob Stallings

  ==============================================================================
*/

#pragma once

#include "AudioEffect.h"



class DS1DistortionEffect : public AudioEffect {
public:
    
    virtual float processSample(float x, const int c);
    
    float getTone();
    void setTone(float tone);
    
    float getDist();
    void setDist(float dist);
    
    float getLevel();
    void setLevel(float level);
    
private:
    float tone;
    float dist;
    float level;
    const bool IS_SIMPLE_DIST = true; // if true = run cubic dist, false = full DS1 chain
    
};
