/*
  ==============================================================================

    SampleButton.cpp
    Created: 19 Dec 2023 4:27:41pm
    Author:  liamw

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SampleButton.h"


//==============================================================================
SampleButton::SampleButton()
{
    midiNote = 0;
    buttonName = "";
    fileName = "";
    vol = 0.0;
}

SampleButton::SampleButton(int note, juce::String name, int ind)
{
    midiNote = note;
    buttonName = name;
    index = ind;
    fileName = "";
    vol = 0.0;
}

SampleButton::~SampleButton()
{
}

void SampleButton::paint(juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colour::fromRGB(47, 43, 41));

    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1);   // draw an outline around the component

    g.setColour(juce::Colours::lightsteelblue);
    g.setFont(10.0f);
    //Paint C1-C2
    g.drawText(buttonName, getLocalBounds(), juce::Justification::topLeft, true);
    //Paint FileNames When Loaded
    g.drawText(fileName, getLocalBounds(), juce::Justification::centred, true);

    if (isHighlighted)
    {
        g.fillAll(juce::Colour::fromRGB(112, 112, 112));

        g.setColour(juce::Colours::grey);
        g.drawRect(getLocalBounds(), 1);   // draw an outline around the component

        g.setColour(juce::Colours::lightsteelblue);
        g.setFont(10.0f);
        //Paint C1-C2
        g.drawText(buttonName, getLocalBounds(), juce::Justification::topLeft, true);
        //Paint FileNames When Loaded
        g.drawText(fileName, getLocalBounds(), juce::Justification::centred, true);
    }
}

void SampleButton::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}

int SampleButton::getMidiNote() {
    return midiNote;
}

juce::String SampleButton::getButtonName() {
    return buttonName;
}

void SampleButton::setFileName(juce::String name) {
    fileName = name;
}

juce::String SampleButton::getFileName() {
    return fileName;
}

void SampleButton::setVol(float x) {
    vol = x;
}

float SampleButton::getVol() {
    return vol;
}

int SampleButton::getIndex() {
    return index;
}