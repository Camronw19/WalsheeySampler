/*
  ==============================================================================

    SampleButton.h
    Created: 19 Dec 2023 4:27:41pm
    Author:  liamw

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>


//==============================================================================
/*
*/
class SampleButton : public juce::TextButton
{
public:
    SampleButton();
    SampleButton(int, juce::String, int);
    ~SampleButton() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    int getMidiNote();
    juce::String getButtonName();
    juce::String getFileName();
    void setFileName(juce::String);
    void setVol(float);
    float getVol();
    int getIndex();

    bool isHighlighted = false;
    juce::File file;


private:

    int midiNote;
    juce::String buttonName;
    juce::String fileName;
    int index;
    float vol;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SampleButton)
};

