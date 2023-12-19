/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WalsheeySamplerAudioProcessorEditor::WalsheeySamplerAudioProcessorEditor (WalsheeySamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), mKeyboard(p.getKeyboardState(), juce::MidiKeyboardComponent::horizontalKeyboard)
{
    mLoadButton.setButtonText("Load"); 
    mLoadButton.onClick = [&] { onLoadButtonClicked(); };
    addAndMakeVisible(mLoadButton); 

    addAndMakeVisible(mKeyboard); 

    setSize (800, 600);
    startTimer(400); 
}

WalsheeySamplerAudioProcessorEditor::~WalsheeySamplerAudioProcessorEditor()
{
}

//==============================================================================
void WalsheeySamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void WalsheeySamplerAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds(); 
    mLoadButton.setBounds(bounds.removeFromTop(getHeight() / 4)); 

    mKeyboard.setBounds(bounds.removeFromBottom(getHeight() / 2)); 
}

void WalsheeySamplerAudioProcessorEditor::onLoadButtonClicked()
{
    audioProcessor.loadSamplerSound();
}

void WalsheeySamplerAudioProcessorEditor::timerCallback()
{
    mKeyboard.grabKeyboardFocus(); 
    stopTimer(); 
}