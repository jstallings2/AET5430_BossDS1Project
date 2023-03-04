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
    
    // Level Knob (center)
    levelKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    levelKnob.setBounds(112,90,75,75);
    levelKnob.setValue(0.5); // initial value
    levelKnob.setRange(0,1); // (min, max, interval)
    levelKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    levelKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(levelKnob);
    
    //Dist Knob (right)
    distKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    distKnob.setBounds(175,5,100,100);
    distKnob.setValue(0.5); // initial value
    distKnob.setRange(0,1); // (min, max, interval)
    distKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    distKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    distKnob.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    addAndMakeVisible(distKnob);
    
    //Tone Knob (left)
    toneKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    //toneKnob.setLookAndFeel(smallKnobLNF);
    toneKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    toneKnob.setBounds(23,5,100,100);
    toneKnob.setValue(0.5); // initial value
    toneKnob.setRange(0,1); // (min, max, interval)
    toneKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    toneKnob.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::green);
    addAndMakeVisible(toneKnob);
    
    
    
    
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
        if (slider == &toneKnob){
            auto value = slider->getValue();
            audioProcessor.tone = value;
        }
        if (slider == &distKnob){
            auto value = slider->getValue();
            audioProcessor.dist = value;
        }
        //DBG(value);
}
