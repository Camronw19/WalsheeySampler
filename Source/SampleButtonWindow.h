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
#include "AudioEditor.h"

//==============================================================================
/*
*/


class SampleButtonWindow  : public juce::Component, 
                            public juce::Button::Listener
                           
{
public:
    SampleButtonWindow();
    ~SampleButtonWindow() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void initializeButtons(); 
    void buttonClicked(juce::Button* button) override; 
    void setListener(std::weak_ptr<AudioEditor> listener); 
    const std::vector<std::unique_ptr<SampleButton>>& getSampleButtons() const;
    const int getNumButtons() const;
    void setLastClickedButton(SampleButton*);
    void HighlightLastClickedButton(SampleButton*);
    void HighlightDragAndDrop(SampleButton*);
    void drawWaveform(SampleButton*);
private:

    std::vector<std::unique_ptr<SampleButton>> mSampleButtons;
    std::weak_ptr<AudioEditor> mEditorListener; 

    SampleButton* LastClickedButton = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleButtonWindow)
};
