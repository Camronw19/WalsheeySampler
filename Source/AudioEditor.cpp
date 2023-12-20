/*
  ==============================================================================

    AudioEditor.cpp
    Created: 19 Dec 2023 2:44:08pm
    Author:  camro

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AudioEditor.h"

//==============================================================================
AudioEditor::AudioEditor()
{
    addAndMakeVisible(mAudioDisplay); 
}

AudioEditor::~AudioEditor()
{
}

void AudioEditor::paint (juce::Graphics& g)
{
    
}



void AudioEditor::resized()
{
    auto bounds = getLocalBounds(); 
    mAudioDisplay.setBounds(bounds.reduced(50)); 
}


void AudioEditor::setThumbnailSource(const juce::File& inputSource)
{
    mAudioDisplay.setThumbnailSource(inputSource); 
}
