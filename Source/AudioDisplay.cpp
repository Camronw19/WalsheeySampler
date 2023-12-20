/*
  ==============================================================================

    AudioDisplay.cpp
    Created: 20 Dec 2023 1:49:50pm
    Author:  camro

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AudioDisplay.h"

//==============================================================================
AudioDisplay::AudioDisplay()
    : mThumbnailCache(5),
    mThumbnail(512, mFormatManager, mThumbnailCache)
{
    mFormatManager.registerBasicFormats();
    mThumbnail.addChangeListener(this);
}

AudioDisplay::~AudioDisplay()
{
}

void AudioDisplay::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds();
    juce::Rectangle<int> thumbnailBounds(bounds);

    if (mThumbnail.getNumChannels() == 0)
        paintIfNoFileLoaded(g, thumbnailBounds);
    else
        paintIfFileLoaded(g, thumbnailBounds);
}

void AudioDisplay::paintIfNoFileLoaded(juce::Graphics& g, const juce::Rectangle<int>& thumbnailBounds)
{
    g.setColour(juce::Colours::darkgrey);
    g.fillRect(thumbnailBounds);
    g.setColour(juce::Colours::white);
    g.drawFittedText("No File Loaded", thumbnailBounds, juce::Justification::centred, 1);
}

void AudioDisplay::paintIfFileLoaded(juce::Graphics& g, const juce::Rectangle<int>& thumbnailBounds)
{
    g.setColour(juce::Colours::white);
    g.fillRect(thumbnailBounds);

    g.setColour(juce::Colours::red);
    mThumbnail.drawChannels(g, thumbnailBounds, 0.0, mThumbnail.getTotalLength(), 1.0f);
}

void AudioDisplay::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    // If the Thumbnail object has changed
    if (source == &mThumbnail)
    {
        thumbnailChanged();
    }
}

void AudioDisplay::thumbnailChanged()
{
    repaint();
}

void AudioDisplay::setThumbnailSource(const juce::File& inputSource)
{
    mThumbnail.setSource(new juce::FileInputSource(inputSource));
}


void AudioDisplay::resized()
{
  
}
