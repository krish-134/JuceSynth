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
class JuceSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    JuceSynthAudioProcessorEditor (JuceSynthAudioProcessor&);
    ~JuceSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthAudioProcessor& audioProcessor;

    //SLIDERS
    juce::Slider frequencySlider;
    juce::Label frequencyLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> frequencyAttachment;
    
    juce::Slider gainSlider;
    juce::Label gainLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceSynthAudioProcessorEditor)
};
