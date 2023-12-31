/*
  ==============================================================================

    SampleButtonWindow.cpp
    Created: 19 Dec 2023 4:32:35pm
    Author:  liamw

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SampleButtonWindow.h"

//==============================================================================
SampleButtonWindow::SampleButtonWindow()
{
    initializeButtons(); 

    for (auto& button : mSampleButtons)
    {
        button->addListener(this); 
        addAndMakeVisible(*button); 
    }
}

SampleButtonWindow::~SampleButtonWindow()
{
    for (auto& button : mSampleButtons)
        button->removeListener(this); 
}

void SampleButtonWindow::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void SampleButtonWindow::resized()
{
    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;
    using Px = juce::Grid::Px;

    grid.templateRows = { Track(Fr(1)), Track(Fr(1))};
    grid.templateColumns = { Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)) };
    grid.items = { juce::GridItem(*mSampleButtons[0]).withArea(1,1),
                   juce::GridItem(*mSampleButtons[1]).withArea(1,2),
                   juce::GridItem(*mSampleButtons[2]).withArea(1,3),
                   juce::GridItem(*mSampleButtons[3]).withArea(1,4),
                   juce::GridItem(*mSampleButtons[4]).withArea(2,1),
                   juce::GridItem(*mSampleButtons[5]).withArea(2,2),
                   juce::GridItem(*mSampleButtons[6]).withArea(2,3),
                   juce::GridItem(*mSampleButtons[7]).withArea(2,4),
                   };
    

    int gapSize = std::min(getWidth() / 25, getHeight() / 25);
    grid.setGap(juce::Grid::Px(gapSize));
    grid.performLayout(getLocalBounds().reduced(10));
}

void SampleButtonWindow::initializeButtons()
{
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(36 , "C1", 0));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(37, "C#1", 1));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(38, "D1", 2));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(39, "D#1", 3));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(40, "E1", 4));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(41, "E#1", 5));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(42, "F1", 6));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(43, "F#1", 7));

}

void SampleButtonWindow::buttonClicked(juce::Button* button)
{

    SampleButton* sampleButton = dynamic_cast<SampleButton*>(button);

    HighlightLastClickedButton(sampleButton);
    drawWaveform(sampleButton);
    
    
}

void SampleButtonWindow::setListener(std::weak_ptr<AudioEditor> listener)
{
    mEditorListener = listener; 
}

const std::vector<std::unique_ptr<SampleButton>>& SampleButtonWindow::getSampleButtons() const
{
    return mSampleButtons;
}

const int SampleButtonWindow::getNumButtons() const
{
    return mSampleButtons.size();
}

void SampleButtonWindow::setLastClickedButton(SampleButton* button)
{
    LastClickedButton = button;
}

void SampleButtonWindow::HighlightLastClickedButton(SampleButton* sampleButton)
{
    if (LastClickedButton != nullptr && LastClickedButton->getHighlightedState() == true)
    {
        // Reset Highlighted State
        LastClickedButton->setHighlightedState(false);
        LastClickedButton->repaint();

        // If the same button is clicked again, clear the last clicked button
        if (LastClickedButton == sampleButton)
        {
            setLastClickedButton(nullptr);
            
        }
        else
        {
            // Set Highlighted State and repaint for a different button
            sampleButton->setHighlightedState(true);
            sampleButton->repaint();
            setLastClickedButton(sampleButton);
        }
    }
    else
    {
        // Set Highlighted State and repaint for the first click
        sampleButton->setHighlightedState(true);
        sampleButton->repaint();
        setLastClickedButton(sampleButton);
    }
}

void SampleButtonWindow::HighlightDragAndDrop(SampleButton* sampleButton)
{
    if (LastClickedButton != nullptr) 
    {
        LastClickedButton->setHighlightedState(false);
        LastClickedButton->repaint();
    }

    sampleButton->setHighlightedState(true);
    sampleButton->repaint();
    setLastClickedButton(sampleButton);
    drawWaveform(sampleButton);

}

void SampleButtonWindow::drawWaveform(SampleButton* sampleButton)
{
    if (auto editorListener = mEditorListener.lock())
    {
        // The object exists: safely use editorListener as std::shared_ptr<AudioEditor>
        if (sampleButton->getHighlightedState() == true)
        {
        editorListener->setThumbnailSource(sampleButton->getFile());
        }
        else
        {
        editorListener->setThumbnailSource(juce::File());
        }

    }
    else
    {
        // The AudioEditor object has been destroyed
    }
}
