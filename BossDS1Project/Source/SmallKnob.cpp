/*
  ==============================================================================

    SmallKnob.cpp
    Created: 4 Mar 2023 2:31:05pm
    Author:  Jacob Stallings

  ==============================================================================
*/

#include "SmallKnob.h"

void SmallKnob::drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider &slider) {
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    juce::AffineTransform rotator;
    g.drawImageTransformed(knob, rotator.rotated(angle,(float)(knob.getWidth()/2), (float)(knob.getHeight()/2)));
}
