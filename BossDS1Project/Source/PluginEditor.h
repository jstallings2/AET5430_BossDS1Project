/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SmallKnob.h"

//==============================================================================
/**
*/
class BossDS1ProjectAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BossDS1ProjectAudioProcessorEditor (BossDS1ProjectAudioProcessor&);
    ~BossDS1ProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BossDS1ProjectAudioProcessor& audioProcessor;
    
    SmallKnob smallKnobLNF;
    
    // Dist Knob
    juce::Slider distKnob;
    // Tone Knob
    juce::Slider toneKnob;
    // Level Knob
    juce::Slider levelKnob;
    
public:
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BossDS1ProjectAudioProcessorEditor)
};
