/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SampleButtonWindow.h"
#include "SampleButton.h"
#include "AudioEditor.h"

//==============================================================================
/**
*/
class WalsheeySamplerAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::FileDragAndDropTarget
{
public:
    WalsheeySamplerAudioProcessorEditor (WalsheeySamplerAudioProcessor&);
    ~WalsheeySamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool isInterestedInFileDrag(const juce::StringArray& files) override;
    void filesDropped(const juce::StringArray& files, int x, int y) override;

private:
   
    std::shared_ptr<AudioEditor> mAudioEditor = std::make_shared<AudioEditor>();
    SampleButtonWindow mSampleButtonWindow;

    WalsheeySamplerAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WalsheeySamplerAudioProcessorEditor)
};
