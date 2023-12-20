/*
  ==============================================================================

    SampleButtonWindow.h
    Created: 19 Dec 2023 4:32:35pm
    Author:  liamw

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SampleButton.h"

//==============================================================================
/*
*/
class SampleButtonWindow  : public juce::Component
{
public:
    SampleButtonWindow();
    ~SampleButtonWindow() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void initializeButtons(); 

private:
    std::vector<std::unique_ptr<SampleButton>> mSampleButtons;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleButtonWindow)
};
