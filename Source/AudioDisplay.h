/*
  ==============================================================================

    AudioDisplay.h
    Created: 20 Dec 2023 1:49:50pm
    Author:  camro

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AudioDisplay  : public juce::Component,
                      public juce::ChangeListener
{
public:
    AudioDisplay();
    ~AudioDisplay() override;

    void paint (juce::Graphics&) override;
    void paintIfNoFileLoaded(juce::Graphics& g, const juce::Rectangle<int>& thumbnailBounds);
    void paintIfFileLoaded(juce::Graphics& g, const juce::Rectangle<int>& thumbnailBounds);

    void resized() override;
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    void setThumbnailSource(const juce::File& inputSource);
    void thumbnailChanged();

private:
    juce::AudioFormatManager mFormatManager;
    juce::AudioThumbnailCache mThumbnailCache;
    juce::AudioThumbnail mThumbnail;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioDisplay)
};
