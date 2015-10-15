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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AuralizerAudioProcessorEditor::AuralizerAudioProcessorEditor (AuralizerAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (bypassButton_ = new ToggleButton ("bypassButton"));
    bypassButton_->setButtonText (TRANS("Bypass"));
    bypassButton_->addListener (this);
    bypassButton_->setColour (ToggleButton::textColourId, Colours::blueviolet);

    addAndMakeVisible (outputGainSlider_ = new Slider ("outputGainSlider"));
    outputGainSlider_->setRange (0.5, 2, 0.01);
    outputGainSlider_->setSliderStyle (Slider::RotaryVerticalDrag);
    outputGainSlider_->setTextBoxStyle (Slider::TextBoxBelow, true, 40, 20);
    outputGainSlider_->setColour (Slider::backgroundColourId, Colours::red);
    outputGainSlider_->setColour (Slider::thumbColourId, Colours::blueviolet);
    outputGainSlider_->setColour (Slider::trackColourId, Colour (0x00ffffff));
    outputGainSlider_->setColour (Slider::rotarySliderFillColourId, Colours::blueviolet);
    outputGainSlider_->setColour (Slider::rotarySliderOutlineColourId, Colours::blueviolet);
    outputGainSlider_->setColour (Slider::textBoxTextColourId, Colours::blueviolet);
    outputGainSlider_->setColour (Slider::textBoxBackgroundColourId, Colour (0xff2a2a2a));
    outputGainSlider_->setColour (Slider::textBoxHighlightColourId, Colour (0xffc17eff));
    outputGainSlider_->setColour (Slider::textBoxOutlineColourId, Colours::blueviolet);
    outputGainSlider_->addListener (this);

    addAndMakeVisible (titleLabel_ = new Label ("titleLabel",
                                                TRANS("AURALIZER")));
    titleLabel_->setFont (Font (28.00f, Font::plain));
    titleLabel_->setJustificationType (Justification::centredLeft);
    titleLabel_->setEditable (false, false, false);
    titleLabel_->setColour (Label::backgroundColourId, Colour (0x00ff0000));
    titleLabel_->setColour (Label::textColourId, Colours::blueviolet);
    titleLabel_->setColour (Label::outlineColourId, Colour (0x008a2be2));
    titleLabel_->setColour (TextEditor::textColourId, Colours::white);
    titleLabel_->setColour (TextEditor::backgroundColourId, Colour (0xac000000));
    titleLabel_->setColour (TextEditor::highlightColourId, Colour (0x001111ee));

    addAndMakeVisible (preGainSlider_ = new Slider ("preGainSlider"));
    preGainSlider_->setRange (0.5, 2, 0.01);
    preGainSlider_->setSliderStyle (Slider::RotaryVerticalDrag);
    preGainSlider_->setTextBoxStyle (Slider::TextBoxBelow, true, 40, 20);
    preGainSlider_->setColour (Slider::backgroundColourId, Colours::red);
    preGainSlider_->setColour (Slider::thumbColourId, Colours::blueviolet);
    preGainSlider_->setColour (Slider::trackColourId, Colour (0x00ffffff));
    preGainSlider_->setColour (Slider::rotarySliderFillColourId, Colours::blueviolet);
    preGainSlider_->setColour (Slider::rotarySliderOutlineColourId, Colours::blueviolet);
    preGainSlider_->setColour (Slider::textBoxTextColourId, Colours::blueviolet);
    preGainSlider_->setColour (Slider::textBoxBackgroundColourId, Colour (0xff2a2a2a));
    preGainSlider_->setColour (Slider::textBoxHighlightColourId, Colours::blueviolet);
    preGainSlider_->setColour (Slider::textBoxOutlineColourId, Colours::blueviolet);
    preGainSlider_->addListener (this);

    addAndMakeVisible (angleSlider_ = new Slider ("angleSlider"));
    angleSlider_->setRange (0, 359, 1);
    angleSlider_->setSliderStyle (Slider::RotaryVerticalDrag);
    angleSlider_->setTextBoxStyle (Slider::TextBoxBelow, true, 40, 20);
    angleSlider_->setColour (Slider::backgroundColourId, Colours::red);
    angleSlider_->setColour (Slider::thumbColourId, Colours::blueviolet);
    angleSlider_->setColour (Slider::trackColourId, Colours::white);
    angleSlider_->setColour (Slider::rotarySliderFillColourId, Colours::blueviolet);
    angleSlider_->setColour (Slider::rotarySliderOutlineColourId, Colours::blueviolet);
    angleSlider_->setColour (Slider::textBoxTextColourId, Colours::blueviolet);
    angleSlider_->setColour (Slider::textBoxBackgroundColourId, Colour (0xff2a2a2a));
    angleSlider_->setColour (Slider::textBoxHighlightColourId, Colour (0xffc17eff));
    angleSlider_->setColour (Slider::textBoxOutlineColourId, Colours::blueviolet);
    angleSlider_->addListener (this);

    addAndMakeVisible (preGainLabel_ = new Label ("preGainLabel",
                                                  TRANS("Pre Gain (dB)")));
    preGainLabel_->setFont (Font (14.00f, Font::plain));
    preGainLabel_->setJustificationType (Justification::centred);
    preGainLabel_->setEditable (false, false, false);
    preGainLabel_->setColour (Label::textColourId, Colours::blueviolet);
    preGainLabel_->setColour (TextEditor::textColourId, Colours::black);
    preGainLabel_->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputGainLabel_ = new Label ("outputGainLabel",
                                                     TRANS("Output Gain (dB)")));
    outputGainLabel_->setFont (Font (14.00f, Font::plain));
    outputGainLabel_->setJustificationType (Justification::centredLeft);
    outputGainLabel_->setEditable (false, false, false);
    outputGainLabel_->setColour (Label::textColourId, Colours::blueviolet);
    outputGainLabel_->setColour (TextEditor::textColourId, Colours::black);
    outputGainLabel_->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (angleLabel_ = new Label ("angleLabel",
                                                TRANS("Angle")));
    angleLabel_->setFont (Font (14.00f, Font::plain));
    angleLabel_->setJustificationType (Justification::centredLeft);
    angleLabel_->setEditable (false, false, false);
    angleLabel_->setColour (Label::textColourId, Colours::blueviolet);
    angleLabel_->setColour (TextEditor::textColourId, Colours::black);
    angleLabel_->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (automationButton_ = new ToggleButton ("automationButton"));
    automationButton_->setButtonText (TRANS("Automation"));
    automationButton_->addListener (this);
    automationButton_->setColour (ToggleButton::textColourId, Colours::blueviolet);

    addAndMakeVisible (speedSlider_ = new Slider ("speedSlider"));
    speedSlider_->setRange (1, 10, 1);
    speedSlider_->setSliderStyle (Slider::RotaryVerticalDrag);
    speedSlider_->setTextBoxStyle (Slider::TextBoxBelow, true, 30, 15);
    speedSlider_->setColour (Slider::backgroundColourId, Colours::red);
    speedSlider_->setColour (Slider::thumbColourId, Colours::blueviolet);
    speedSlider_->setColour (Slider::trackColourId, Colour (0x00ffffff));
    speedSlider_->setColour (Slider::rotarySliderFillColourId, Colours::blueviolet);
    speedSlider_->setColour (Slider::rotarySliderOutlineColourId, Colours::blueviolet);
    speedSlider_->setColour (Slider::textBoxTextColourId, Colours::blueviolet);
    speedSlider_->setColour (Slider::textBoxBackgroundColourId, Colour (0xff2a2a2a));
    speedSlider_->setColour (Slider::textBoxHighlightColourId, Colours::blueviolet);
    speedSlider_->setColour (Slider::textBoxOutlineColourId, Colours::blueviolet);
    speedSlider_->addListener (this);

    addAndMakeVisible (speedLabel_ = new Label ("speedLabel",
                                                TRANS("Speed")));
    speedLabel_->setFont (Font (14.00f, Font::plain));
    speedLabel_->setJustificationType (Justification::centred);
    speedLabel_->setEditable (false, false, false);
    speedLabel_->setColour (Label::textColourId, Colours::blueviolet);
    speedLabel_->setColour (TextEditor::textColourId, Colours::black);
    speedLabel_->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (450, 250);


    //[Constructor] You can add your own custom stuff here..
    startTimer(100);
    //[/Constructor]
}

AuralizerAudioProcessorEditor::~AuralizerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    bypassButton_ = nullptr;
    outputGainSlider_ = nullptr;
    titleLabel_ = nullptr;
    preGainSlider_ = nullptr;
    angleSlider_ = nullptr;
    preGainLabel_ = nullptr;
    outputGainLabel_ = nullptr;
    angleLabel_ = nullptr;
    automationButton_ = nullptr;
    speedSlider_ = nullptr;
    speedLabel_ = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AuralizerAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff383838));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AuralizerAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    bypassButton_->setBounds (296, 8, 70, 24);
    outputGainSlider_->setBounds (268, 72, 70, 70);
    titleLabel_->setBounds (8, 8, 150, 24);
    preGainSlider_->setBounds (38, 72, 70, 70);
    angleSlider_->setBounds (136, 57, 100, 100);
    preGainLabel_->setBounds (28, 48, 100, 24);
    outputGainLabel_->setBounds (256, 48, 100, 24);
    angleLabel_->setBounds (166, 31, 60, 24);
    automationButton_->setBounds (224, 184, 80, 24);
    speedSlider_->setBounds (90, 167, 60, 60);
    speedLabel_->setBounds (71, 145, 100, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AuralizerAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton_)
    {
        //[UserButtonCode_bypassButton_] -- add your button handler code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kBypassParam, (float)bypassButton_->getToggleState());
        //[/UserButtonCode_bypassButton_]
    }
    else if (buttonThatWasClicked == automationButton_)
    {
        //[UserButtonCode_automationButton_] -- add your button handler code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kAutomationParam, (float)automationButton_->getToggleState());
        //[/UserButtonCode_automationButton_]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void AuralizerAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == outputGainSlider_)
    {
        //[UserSliderCode_outputGainSlider_] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kOutputGainParam, (float)outputGainSlider_->getValue());
        //[/UserSliderCode_outputGainSlider_]
    }
    else if (sliderThatWasMoved == preGainSlider_)
    {
        //[UserSliderCode_preGainSlider_] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kPreGainParam, (float)preGainSlider_->getValue());
        //[/UserSliderCode_preGainSlider_]
    }
    else if (sliderThatWasMoved == angleSlider_)
    {
        //[UserSliderCode_angleSlider_] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kAngleParam, (float)angleSlider_->getValue());
        //[/UserSliderCode_angleSlider_]
    }
    else if (sliderThatWasMoved == speedSlider_)
    {
        //[UserSliderCode_speedSlider_] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(AuralizerAudioProcessor::kSpeedParam, (float)speedSlider_->getValue());
        //[/UserSliderCode_speedSlider_]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AuralizerAudioProcessorEditor::timerCallback()
{
    AuralizerAudioProcessor* ourProcessor = getProcessor();

    // Exchange data between UI elements and the plug-in processor
    outputGainSlider_->setValue(ourProcessor->outputGain_, dontSendNotification);
    preGainSlider_->setValue(ourProcessor->preGain_, dontSendNotification);
    angleSlider_->setValue(ourProcessor->angle_, dontSendNotification);
    speedSlider_->setValue(ourProcessor->speed_, dontSendNotification);
    automationButton_->setToggleState(ourProcessor->automation_, dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AuralizerAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="450" initialHeight="250">
  <BACKGROUND backgroundColour="ff383838"/>
  <TOGGLEBUTTON name="bypassButton" id="d3c82e7365bceab9" memberName="bypassButton_"
                virtualName="" explicitFocusOrder="0" pos="296 8 70 24" txtcol="ff8a2be2"
                buttonText="Bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <SLIDER name="outputGainSlider" id="90c0e00f11d36534" memberName="outputGainSlider_"
          virtualName="" explicitFocusOrder="0" pos="268 72 70 70" bkgcol="ffff0000"
          thumbcol="ff8a2be2" trackcol="ffffff" rotarysliderfill="ff8a2be2"
          rotaryslideroutline="ff8a2be2" textboxtext="ff8a2be2" textboxbkgd="ff2a2a2a"
          textboxhighlight="ffc17eff" textboxoutline="ff8a2be2" min="0.5"
          max="2" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="titleLabel" id="8af08588f304bba3" memberName="titleLabel_"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 24" bkgCol="ff0000"
         textCol="ff8a2be2" outlineCol="8a2be2" edTextCol="ffffffff" edBkgCol="ac000000"
         hiliteCol="1111ee" labelText="AURALIZER" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="28" bold="0" italic="0" justification="33"/>
  <SLIDER name="preGainSlider" id="bc5b45b3c4b7229e" memberName="preGainSlider_"
          virtualName="" explicitFocusOrder="0" pos="38 72 70 70" bkgcol="ffff0000"
          thumbcol="ff8a2be2" trackcol="ffffff" rotarysliderfill="ff8a2be2"
          rotaryslideroutline="ff8a2be2" textboxtext="ff8a2be2" textboxbkgd="ff2a2a2a"
          textboxhighlight="ff8a2be2" textboxoutline="ff8a2be2" min="0.5"
          max="2" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="angleSlider" id="631ba3c6eda89434" memberName="angleSlider_"
          virtualName="" explicitFocusOrder="0" pos="136 57 100 100" bkgcol="ffff0000"
          thumbcol="ff8a2be2" trackcol="ffffffff" rotarysliderfill="ff8a2be2"
          rotaryslideroutline="ff8a2be2" textboxtext="ff8a2be2" textboxbkgd="ff2a2a2a"
          textboxhighlight="ffc17eff" textboxoutline="ff8a2be2" min="0"
          max="355" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="preGainLabel" id="714f57101916f4b9" memberName="preGainLabel_"
         virtualName="" explicitFocusOrder="0" pos="28 48 100 24" textCol="ff8a2be2"
         edTextCol="ff000000" edBkgCol="0" labelText="Pre Gain (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="outputGainLabel" id="1d880b0959ed8e66" memberName="outputGainLabel_"
         virtualName="" explicitFocusOrder="0" pos="256 48 100 24" textCol="ff8a2be2"
         edTextCol="ff000000" edBkgCol="0" labelText="Output Gain (dB)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="angleLabel" id="4709eea852957313" memberName="angleLabel_"
         virtualName="" explicitFocusOrder="0" pos="166 31 60 24" textCol="ff8a2be2"
         edTextCol="ff000000" edBkgCol="0" labelText="Angle" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="automationButton" id="99ea03f07cdb667e" memberName="automationButton_"
                virtualName="" explicitFocusOrder="0" pos="224 184 80 24" txtcol="ff8a2be2"
                buttonText="Automation" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <SLIDER name="speedSlider" id="9f2e7f3976a557c2" memberName="speedSlider_"
          virtualName="" explicitFocusOrder="0" pos="90 167 60 60" bkgcol="ffff0000"
          thumbcol="ff8a2be2" trackcol="ffffff" rotarysliderfill="ff8a2be2"
          rotaryslideroutline="ff8a2be2" textboxtext="ff8a2be2" textboxbkgd="ff2a2a2a"
          textboxhighlight="ff8a2be2" textboxoutline="ff8a2be2" min="1"
          max="10" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="30" textBoxHeight="15" skewFactor="1"/>
  <LABEL name="speedLabel" id="dfad3287fd21b87c" memberName="speedLabel_"
         virtualName="" explicitFocusOrder="0" pos="71 145 100 24" textCol="ff8a2be2"
         edTextCol="ff000000" edBkgCol="0" labelText="Speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
