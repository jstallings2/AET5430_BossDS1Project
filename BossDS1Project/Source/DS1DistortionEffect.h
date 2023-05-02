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
    
    // Ciruit: Override the constructor and add the layout
    
    virtual float processSample(float x, const int c);
    
    void prepareToPlay(float sampleRate, int samplesPerBlock);
    
    float getDist();
    void setDist(float dist);
    
    float getLevel();
    void setLevel(float level);
    
private:
    typedef AudioEffect super;
    
    const bool IS_SIMPLE_DIST = true; // if true = run cubic dist, false = full DS1 chain
    
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> sDist = {0.f};
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> sLevel = {0.f};
};
