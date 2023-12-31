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
SampleAudioSource::SampleAudioSource()
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
    mSampler.renderNextBlock(*bufferToFill.buffer, midiMessages, bufferToFill.startSample, bufferToFill.numSamples);
}

void SampleAudioSource::LoadSamplerSoundDragAndDrop(const juce::File& file, int midiNote) 
{
    std::unique_ptr<juce::AudioFormatReader> reader(mFormatManager.createReaderFor(file));

    //add sound to Synthesiser mSampler
    juce::BigInteger range;
    range.setRange(midiNote,1, true);
    mSampler.addSound(new juce::SamplerSound("Sample", *reader, range, midiNote, 0.1, 0.1, 10.0));
}
