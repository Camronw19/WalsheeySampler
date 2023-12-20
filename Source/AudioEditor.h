/*
  ==============================================================================

    AudioEditor.h
    Created: 19 Dec 2023 2:44:08pm
    Author:  camro

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AudioDisplay.h"

//==============================================================================
/*
*/
class AudioEditor  : public juce::Component
                     
{
public:
    AudioEditor();
    ~AudioEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;
    
    void setThumbnailSource(const juce::File& inputSource);

private:
    AudioDisplay mAudioDisplay; 
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioEditor)
};
