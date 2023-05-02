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
    
    // Level Knob (center)
    levelKnob.setLookAndFeel(&smallKnobLNF);
    // Specify location in window (xPos,yPos,width,height)
    levelKnob.setBounds(25,25,100,100);
    levelKnob.setValue(1.0); // initial value
    levelKnob.setRange(0,1); // (min, max, interval)
    levelKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    levelKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(levelKnob);
    
    //Dist Knob (right)
    distKnob.setLookAndFeel(&smallKnobLNF);
    // Specify location in window (xPos,yPos,width,height)
    distKnob.setBounds(200,25,100,100);
    distKnob.setValue(0.0); // initial value
    distKnob.setRange(0,1); // (min, max, interval)
    distKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    distKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(distKnob);
    
}

BossDS1ProjectAudioProcessorEditor::~BossDS1ProjectAudioProcessorEditor()
{
}

//==============================================================================
void BossDS1ProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (juce::Colours::orange);
    g.setColour(juce::Colours::black);
        g.fillRoundedRectangle(4, 350, 292, 146, 10); // foot pad
    g.setFont (24.0f);
    g.drawText("LEVEL", 12, 65, 100, 100, juce::Justification::horizontallyCentred);
    g.drawText("DIST", 187, 65, 100, 100, juce::Justification::horizontallyCentred);
    
    g.setFont(36.f);
    g.drawText("Distortion", 145, 250, 300, 100, juce::Justification::left);
    g.drawText("DS-1", 220, 280, 300, 100, juce::Justification::left);

    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state,"distValue", distKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state,"levelValue", levelKnob));
}

void BossDS1ProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
