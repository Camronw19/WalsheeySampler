/*
  ==============================================================================

    AudioEditor.cpp
    Created: 19 Dec 2023 2:44:08pm
    Author:  camro

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AudioEditor.h"

//==============================================================================
AudioEditor::AudioEditor()
{

}

AudioEditor::~AudioEditor()
{
}

void AudioEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));  

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   

}

void AudioEditor::resized()
{

}
