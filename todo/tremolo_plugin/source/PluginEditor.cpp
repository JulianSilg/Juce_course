namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) {
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

 auto logoImage = juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize);
  logo.setImage(logoImage);
  logoCenter.setImage(logoImage);
  logoRight.setImage(logoImage);


  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  addAndMakeVisible(logoCenter);
  addAndMakeVisible(logoRight);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

void PluginEditor::resized() {
  const auto bounds = getLocalBounds();

    DBG(bounds.toString());

  background.setBounds(bounds);

  logo.setBounds({16, 16, 105, 24});
  logoCenter.setBounds({bounds.getCentreX() - (105 / 2), 16, 105, 24});
  logoRight.setBounds({bounds.getWidth() - 105 - 16, 16, 105, 24});


}
}  // namespace tremolo
