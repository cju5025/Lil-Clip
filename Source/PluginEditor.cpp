#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoftClipperAudioProcessorEditor::SoftClipperAudioProcessorEditor (SoftClipperAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (200, 175);
    
    auto& params = processor.getParameters();
    
    //mix slider
    AudioParameterFloat* mMixParameter = (AudioParameterFloat*)params.getUnchecked(0);
    
    mMixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mMixSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 15);
    mMixSlider.setRange(mMixParameter->range.start, mMixParameter->range.end);
    mMixSlider.setValue(*mMixParameter);
    addAndMakeVisible(mMixSlider);
    
    mMixSlider.onValueChange = [this, mMixParameter] {*mMixParameter = mMixSlider.getValue(); };
    mMixSlider.onDragStart = [mMixParameter] {mMixParameter->beginChangeGesture(); };
    mMixSlider.onDragEnd = [mMixParameter] {mMixParameter->endChangeGesture(); };
    
    // threshold slider
    AudioParameterFloat* mThresholdParameter = (AudioParameterFloat*)params.getUnchecked(1);
    
    mThresholdSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mThresholdSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 15);
    mThresholdSlider.setRange(mThresholdParameter->range.start, mThresholdParameter->range.end);
    mThresholdSlider.setValue(*mThresholdParameter);
    addAndMakeVisible(mThresholdSlider);
    
    mThresholdSlider.onValueChange = [this, mThresholdParameter] {*mThresholdParameter = mThresholdSlider.getValue(); };
    mThresholdSlider.onDragStart = [mThresholdParameter] {mThresholdParameter->beginChangeGesture(); };
    mThresholdSlider.onDragEnd = [mThresholdParameter] {mThresholdParameter->endChangeGesture(); };
}

SoftClipperAudioProcessorEditor::~SoftClipperAudioProcessorEditor()
{
}

//==============================================================================
void SoftClipperAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
    g.drawText("Mix", ((getWidth() / 7) * 1) - (30), (getHeight() / 2) - 15, 100, 100, Justification::centred, false);
    g.drawText("Threshold", ((getWidth() / 5) * 2) + (15), (getHeight() / 2) - 15, 100, 100, Justification::centred, false);
}

void SoftClipperAudioProcessorEditor::resized()
{
    mMixSlider.setBounds(0, 0, 100, 100);
    mThresholdSlider.setBounds(100, 0, 100, 100);
}
