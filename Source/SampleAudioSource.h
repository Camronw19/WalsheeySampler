/*
  ==============================================================================

    SampleAudioSource.h
    Created: 19 Dec 2023 12:15:29pm
    Author:  camro

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SampleAudioSource  : public juce::AudioSource
{
public:
    SampleAudioSource(juce::MidiKeyboardState& keyboardState);
    ~SampleAudioSource() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override; 
    void releaseResources() override; 
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override; 
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::MidiBuffer& midiMessages); 
    void LoadSamplerSound();
private:
    juce::Synthesiser mSampler;
    juce::AudioFormatManager mFormatManager;
    std::unique_ptr<juce::FileChooser> mFileChooser;
    juce::MidiKeyboardState& mKeyboardState; 
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleAudioSource)
};
