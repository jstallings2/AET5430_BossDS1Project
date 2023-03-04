/*
  ==============================================================================

    SmallKnob.h
    Created: 4 Mar 2023 2:31:05pm
    Author:  Jacob Stallings

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SmallKnob : public juce::LookAndFeel_V3 {
public:
    juce::Image knob = juce::ImageCache::getFromMemory(BinaryData::knob_small_png, BinaryData::knob_small_pngSize);
    
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider);
    
};
