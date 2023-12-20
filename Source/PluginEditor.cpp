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
  

    addAndMakeVisible(mKeyboard); 
    addAndMakeVisible(mSampleButtonWindow); 

    setResizeLimits(400, 300, 1200, 900); 
    setResizable(true, true); 
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
   

    mSampleButtonWindow.setBounds(bounds.removeFromBottom(getHeight() / 2)); 
}

void WalsheeySamplerAudioProcessorEditor::timerCallback()
{
    mKeyboard.grabKeyboardFocus(); 
    stopTimer(); 
}

//Funtion defenition for making sure file grabbed is valid format
bool WalsheeySamplerAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for (auto file : files)
    {
        if (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif")) {
            return true;
        }
    }
   

    return false;
}

void WalsheeySamplerAudioProcessorEditor::filesDropped(const juce::StringArray& files, int x, int y)
{
    auto localPoint = mSampleButtonWindow.getLocalPoint(this, juce::Point<int>(x, y));

    for (auto file : files)
    {
        if (isInterestedInFileDrag(file))
        {
            for (int i = 0; i < mSampleButtonWindow.getNumButtons(); i++)
            {
                if (mSampleButtonWindow.getSampleButtons()[i]->getBounds().contains(localPoint))
                {
                    audioProcessor.loadSamplerSoundDragAndDrop(file, *mSampleButtonWindow.getSampleButtons()[i]);
                    mSampleButtonWindow.getSampleButtons()[i]->setButtonText(file);
                }
            }
            //lastClickedButton = mSampleButtonWindow.mSampleButtons[i];

            /*
            if (buttons[i]->isHighlighted == true) {
                return;
            }

            //reset highlighted state
            for (int j = 0; j < 16; j++) {
                buttons[j]->isHighlighted = false;
                buttons[j]->repaint();
            }

            // Set the highlight state for the clicked button
            buttons[i]->isHighlighted = true;
            buttons[i]->repaint();
            */
        }
    }
}