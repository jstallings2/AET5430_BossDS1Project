/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BossDS1ProjectAudioProcessor::BossDS1ProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), state(*this, nullptr, "DS1Params", createParameterLayout())
#endif
{
}

BossDS1ProjectAudioProcessor::~BossDS1ProjectAudioProcessor()
{
}

//==============================================================================
const juce::String BossDS1ProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BossDS1ProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BossDS1ProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BossDS1ProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double BossDS1ProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BossDS1ProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BossDS1ProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BossDS1ProjectAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String BossDS1ProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void BossDS1ProjectAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void BossDS1ProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void BossDS1ProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool BossDS1ProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void BossDS1ProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    // Get updated parameter values from the editor
    
    float dist = *state.getRawParameterValue("distValue");
    float level = *state.getRawParameterValue("levelValue");
    
    distEffect.setDist(dist);
    distEffect.setLevel(level);
    
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
        // Have a loop to go through each of the samples in our signal
        for (int n = 0 ; n < buffer.getNumSamples() ; ++n)
        {
            float x = buffer.getWritePointer(channel) [n];

            // Perform the distortion effect on the sample
            x = distEffect.processSample(x, channel);

            // scales amplitude by level - this may go in the circuitChain code in which case we'll take it out
            buffer.getWritePointer(channel) [n] = x * distEffect.getLevel();
        }
    }
}

//==============================================================================
bool BossDS1ProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* BossDS1ProjectAudioProcessor::createEditor()
{
    return new BossDS1ProjectAudioProcessorEditor (*this);
}

//==============================================================================
void BossDS1ProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BossDS1ProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BossDS1ProjectAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout BossDS1ProjectAudioProcessor::createParameterLayout() {
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    params.push_back(std::make_unique<juce::AudioParameterFloat>("distValue",
                                                                 "Dist",
                                                                 juce::NormalisableRange<float>(0.f, 1.f),
                                                                 0.f
                                                                 ));
    
    params.push_back(std::make_unique<juce::AudioParameterFloat>("levelValue",
                                                                 "Level",
                                                                 juce::NormalisableRange<float>(0.f, 1.f),
                                                                 1.f
                                                                 ));
    
    
    return {params.begin(), params.end()};
}
