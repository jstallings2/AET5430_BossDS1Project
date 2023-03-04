/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BossDS1ProjectAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener
{
public:
    BossDS1ProjectAudioProcessorEditor (BossDS1ProjectAudioProcessor&);
    ~BossDS1ProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider*) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BossDS1ProjectAudioProcessor& audioProcessor;
    
    juce::Image smallKnob;
    
    // Dist Knob
    // Tone Knob
    // Level Knob
    juce::Slider levelKnob;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BossDS1ProjectAudioProcessorEditor)
};
