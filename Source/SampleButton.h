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
    float getVol();
    int getIndex();
    juce::File getFile(); 

    void setFileName(juce::String);
    void setVol(float);
    void setFile(const juce::File&);

private:
    juce::File mFile;
    int mMidiNote;
    juce::String mButtonName;
    juce::String mFileName;
    int mIndex;
    float mVol;
    bool mIsHighlighted; 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SampleButton)
};

