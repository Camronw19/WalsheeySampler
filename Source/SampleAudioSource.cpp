/*
  ==============================================================================

    SampleAudioSource.cpp
    Created: 19 Dec 2023 12:15:29pm
    Author:  camro

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SampleAudioSource.h"

//==============================================================================
SampleAudioSource::SampleAudioSource(juce::MidiKeyboardState& keyboardState)
    :mKeyboardState(keyboardState)
{
    mFormatManager.registerBasicFormats();
    mSampler.addVoice(new juce::SamplerVoice());
}

SampleAudioSource::~SampleAudioSource()
{
}

void SampleAudioSource::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mSampler.setCurrentPlaybackSampleRate(sampleRate); 
}

void SampleAudioSource::releaseResources()
{

}

void SampleAudioSource::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
  
}

void SampleAudioSource::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::MidiBuffer& midiMessages)
{
    bufferToFill.clearActiveBufferRegion();

    // Add keyboard component midi messages to external midi messages
    juce::MidiBuffer keyboardMidi;
    mKeyboardState.processNextMidiBuffer(keyboardMidi, 0, bufferToFill.buffer->getNumSamples(), true);
    midiMessages.addEvents(keyboardMidi, 0, bufferToFill.buffer->getNumSamples(), 0);

    mSampler.renderNextBlock(*bufferToFill.buffer, midiMessages, bufferToFill.startSample, bufferToFill.numSamples);
}

void SampleAudioSource::LoadSamplerSound()
{
    mFileChooser = std::make_unique<juce::FileChooser>("Select a file to load", juce::File{}, "*.wav");

    auto chooserFlags = juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles;
    mFileChooser->launchAsync(chooserFlags, [this](const juce::FileChooser& fc)
        {
            juce::File file = fc.getResult();

            if (file != juce::File{})
            {
                std::unique_ptr<juce::AudioFormatReader> reader(mFormatManager.createReaderFor(file));

                if (reader != nullptr)
                {
                    juce::BigInteger midiRange;
                    midiRange.setRange(0, 128, true);
                    mSampler.addSound(new juce::SamplerSound(file.getFileNameWithoutExtension(), *reader, midiRange, 60, 0.1, 0.1, 10));
                }
            }
        });
}
