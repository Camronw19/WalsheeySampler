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
    :mMidiNote(0), mButtonName(""), mIndex(-1), mFileName(""), mVol(0.0), mIsHighlighted(false)
{
 
}

SampleButton::SampleButton(int note, juce::String name, int i)
    :mMidiNote(note), mButtonName(name), mIndex(i), mFileName(""), mVol(0.0), mIsHighlighted(false)
{

}

SampleButton::~SampleButton()
{
}

void SampleButton::paint(juce::Graphics& g)
{
    //Fill backgound
    if (mIsHighlighted)
        g.setColour(juce::Colour::fromRGB(112, 112, 112));
    else
        g.setColour(juce::Colour::fromRGB(47, 43, 41));

    g.fillRoundedRectangle(getLocalBounds().toFloat(), 10);

    //Draw outline
    g.setColour(juce::Colours::grey);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 10, 1); 

    //Draw key
    g.setColour(juce::Colours::lightsteelblue);
    g.setFont(10.0f);
    g.drawText(mButtonName, getLocalBounds().reduced(10), juce::Justification::topLeft, true);

    //Draw file name
    g.drawText(mFileName, getLocalBounds(), juce::Justification::centred, true);
}

void SampleButton::resized()
{

}

void SampleButton::setFile(const juce::File& file)
{
    mFile = file; 
}

juce::File SampleButton::getFile()
{
    return mFile; 
}

int SampleButton::getMidiNote() {
    return mMidiNote;
}

juce::String SampleButton::getButtonName() {
    return mButtonName;
}

void SampleButton::setFileName(juce::String name) {
    mFileName = name;
}

juce::String SampleButton::getFileName() {
    return mFileName;
}

void SampleButton::setVol(float x) {
    mVol = x;
}

float SampleButton::getVol() {
    return mVol;
}

int SampleButton::getIndex() {
    return mIndex;
}


