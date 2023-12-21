/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WalsheeySamplerAudioProcessorEditor::WalsheeySamplerAudioProcessorEditor (WalsheeySamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(*mAudioEditor); 

    addAndMakeVisible(mSampleButtonWindow);
    mSampleButtonWindow.setListener(std::weak_ptr<AudioEditor>(mAudioEditor)); 

    setResizeLimits(400, 300, 1200, 900); 
    setResizable(true, true); 
    setSize (800, 600);

 
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
    mAudioEditor->setBounds(bounds.removeFromTop(getHeight() / 2));
}


bool WalsheeySamplerAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for (auto file : files)
        if (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"))
            return true;
   
    return false;
}

void WalsheeySamplerAudioProcessorEditor::filesDropped(const juce::StringArray& filePaths, int x, int y)
{
    auto localPoint = mSampleButtonWindow.getLocalPoint(this, juce::Point<int>(x, y));

    for (auto filePath : filePaths)
    {
        if (isInterestedInFileDrag(filePath))
        {
            for (int i = 0; i < mSampleButtonWindow.getNumButtons(); i++)
            {
                if (mSampleButtonWindow.getSampleButtons()[i]->getBounds().contains(localPoint))
                {
                    const juce::File file(filePath); 

                    //Update button 
                    SampleButton& buttonToUpdate = *mSampleButtonWindow.getSampleButtons()[i]; 
                    buttonToUpdate.setFile(file);
                    buttonToUpdate.setFileName(file.getFileName());
                    buttonToUpdate.repaint();
                    buttonToUpdate.setButtonText(file.getFileName()); 

                    //Highlight Button
                    mSampleButtonWindow.HighlightDragAndDrop(&buttonToUpdate);

                    //Update sampler in processor
                    audioProcessor.loadSamplerSoundDragAndDrop(file, buttonToUpdate.getMidiNote());

                }
            }
        }
    }
}