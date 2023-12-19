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

private:

    SampleButton
        buttonC1{ 60, "C1", 0 }, buttonCs1{ 61, "C#1", 1 }, buttonD1{ 62 ,"D1", 2 }, buttonDs1{ 63, "D#1", 3 },
        buttonE1{ 64, "E1", 4 }, buttonEs1{ 65, "E#1", 5 }, buttonF1{ 66, "F1", 6 }, buttonFs1{ 67, "F#1", 7 };

    std::vector<SampleButton*> buttons =
    { &buttonC1, &buttonCs1, &buttonD1, &buttonDs1,
      &buttonE1, &buttonEs1, &buttonF1, &buttonFs1,
    };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleButtonWindow)
};
