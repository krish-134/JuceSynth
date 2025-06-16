/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class JuceSynthAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    JuceSynthAudioProcessor();
    ~JuceSynthAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    
    juce::dsp::Oscillator<float> osc { [](float x) {
        
        return 1.0f - 2.0f * std::abs(x / juce::MathConstants<float>::pi); // triangel wave?
        //return x / juce::MathConstants<float>::pi; //saw wave
        //return x < 0.0f ? -1.0f : 1.0f; // square wave
        //return std::sin (x); //sine wave
    }};
    
    
    juce::dsp::Gain<float> gain;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceSynthAudioProcessor)
};
