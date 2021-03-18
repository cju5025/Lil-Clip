#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class SoftClipperAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SoftClipperAudioProcessorEditor (SoftClipperAudioProcessor&);
    ~SoftClipperAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    Slider mMixSlider;
    Slider mThresholdSlider;
    
    SoftClipperAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftClipperAudioProcessorEditor)
};
