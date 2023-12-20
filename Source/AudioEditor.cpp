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

    mVerticalZoom.addListener(this); 
    mVerticalZoom.setSliderStyle(juce::Slider::LinearBarVertical); 
    addAndMakeVisible(mVerticalZoom); 
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
    mVerticalZoom.setBounds(bounds.removeFromRight(20)); 
}


void AudioEditor::setThumbnailSource(const juce::File& inputSource)
{
    mAudioDisplay.setThumbnailSource(inputSource); 
}

void AudioEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &mVerticalZoom)
    {
        float sliderValue = static_cast<float>(mVerticalZoom.getValue());
        float normalizedSliderValue = juce::jmap(sliderValue, static_cast<float>(mVerticalZoom.getMaximum()), static_cast<float>(mVerticalZoom.getMinimum()), 1.0f, 0.1f);
        mAudioDisplay.setVerticalZoom(normalizedSliderValue);
    }
}
