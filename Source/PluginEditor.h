/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_928D350013A8FDD2__
#define __JUCE_HEADER_928D350013A8FDD2__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AuralizerAudioProcessorEditor  : public AudioProcessorEditor,
                                       public ButtonListener,
                                       public SliderListener,
                                       public Timer
{
public:
    //==============================================================================
    AuralizerAudioProcessorEditor (AuralizerAudioProcessor& ownerFilter);
    ~AuralizerAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    AuralizerAudioProcessor* getProcessor() const
    {
        return static_cast<AuralizerAudioProcessor*> (getAudioProcessor());
    }

    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToggleButton> bypassButton_;
    ScopedPointer<Slider> outputGainSlider_;
    ScopedPointer<Label> titleLabel_;
    ScopedPointer<Slider> preGainSlider_;
    ScopedPointer<Slider> angleSlider_;
    ScopedPointer<Label> preGainLabel_;
    ScopedPointer<Label> outputGainLabel_;
    ScopedPointer<Label> angleLabel_;
    ScopedPointer<ToggleButton> automationButton_;
    ScopedPointer<Slider> speedSlider_;
    ScopedPointer<Label> speedLabel_;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_928D350013A8FDD2__
