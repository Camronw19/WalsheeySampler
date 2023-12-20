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


    //Show channel toggle buttons
    std::pair<bool, bool> showChannel = mAudioDisplay.getShowChannels(); 
    addAndMakeVisible(mChan1Toggle);
    mChan1Toggle.addListener(this); 
    mChan1Toggle.setToggleState(showChannel.first, juce::NotificationType::dontSendNotification);

    addAndMakeVisible(mChan2Toggle);
    mChan2Toggle.addListener(this);
    mChan2Toggle.setToggleState(showChannel.second, juce::NotificationType::dontSendNotification);
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
    
    auto toggleBounds = bounds.removeFromLeft(50); 
    mChan1Toggle.setBounds(toggleBounds.removeFromTop(toggleBounds.getHeight() / 2)); 
    mChan2Toggle.setBounds(toggleBounds); 
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

void AudioEditor::buttonClicked(juce::Button* button)
{
    if (button == &mChan1Toggle || button == &mChan2Toggle)
    {
        if (!mChan1Toggle.getToggleState() && !mChan2Toggle.getToggleState())
        {
            juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
                "Alert",
                "At least one channel must be selected!",
                "OK");

            if (button == &mChan1Toggle)
            {
                mChan1Toggle.setToggleState(true, juce::dontSendNotification); 
            }
            else if (button == &mChan2Toggle)
            {
                mChan2Toggle.setToggleState(true, juce::dontSendNotification);

            }
        }

        mAudioDisplay.setShowChannels(mChan1Toggle.getToggleState(), mChan2Toggle.getToggleState());
    }
}
