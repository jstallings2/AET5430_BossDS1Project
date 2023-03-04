/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BossDS1ProjectAudioProcessorEditor::BossDS1ProjectAudioProcessorEditor (BossDS1ProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 500);
    
    //smallKnob = juce::ImageCache::getFromMemory(BinaryData::knob_small_png, BinaryData::knob_small_pngSize);
    
    // Steps:
    // Draw orange background
    // Draw black rectangle (part where the foot goes)
    // Draw and initialize knobs
    
    // Level Knob
    levelKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    levelKnob.setBounds(100,50,125,125);
    levelKnob.setValue(0.0); // initial value
    levelKnob.setRange(-48.0,12.0,0.1); // (min, max, interval)
    levelKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    levelKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(levelKnob);
    
    
}

BossDS1ProjectAudioProcessorEditor::~BossDS1ProjectAudioProcessorEditor()
{
}

//==============================================================================
void BossDS1ProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (juce::Colours::orange);

        g.setColour (juce::Colours::cornflowerblue);
        g.setFont (35.0f);
        g.drawFittedText ("Text", getLocalBounds(), juce::Justification::centred, 1);
        g.drawImageAt(smallKnob,0,0);
    g.setColour(juce::Colours::darkgrey);
        g.fillRoundedRectangle(4, 350, 292, 146, 10); // foot pad
    
}

void BossDS1ProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void BossDS1ProjectAudioProcessorEditor::sliderValueChanged(juce::Slider * slider) {
        // This is how we check which slider was moved
        if (slider == &levelKnob){
            auto value = slider->getValue();
            audioProcessor.level = value;
        }
        //DBG(value);
}
