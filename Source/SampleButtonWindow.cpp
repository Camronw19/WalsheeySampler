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
        addAndMakeVisible(*button); 
}

SampleButtonWindow::~SampleButtonWindow()
{
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
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(60, "C1", 0));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(61, "C#1", 1));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(62, "D1", 2));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(63, "D#1", 3));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(64, "E1", 4));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(65, "E#1", 5));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(66, "F1", 6));
    mSampleButtons.emplace_back(std::make_unique<SampleButton>(67, "F#1", 7));
}
