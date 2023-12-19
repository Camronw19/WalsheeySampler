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
class WalsheeySamplerAudioProcessorEditor  : public juce::AudioProcessorEditor, juce::Timer
{
public:
    WalsheeySamplerAudioProcessorEditor (WalsheeySamplerAudioProcessor&);
    ~WalsheeySamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override; 
private:
    juce::TextButton mLoadButton; 
    void onLoadButtonClicked(); 

    juce::MidiKeyboardComponent mKeyboard; 
    WalsheeySamplerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WalsheeySamplerAudioProcessorEditor)
};
