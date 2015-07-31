--- plugins/lmp/plugins/fradj/eqbandwidget.cpp.orig	2014-07-28 18:35:44 UTC
+++ plugins/lmp/plugins/fradj/eqbandwidget.cpp
@@ -98,7 +98,7 @@ namespace Fradj
 				this,
 				SLOT (setGainBoxValue (int)));
 
-		Ui_.GainSlider_->setValue (std::round (value * SliderPrecision));
+		Ui_.GainSlider_->setValue (round (value * SliderPrecision));
 
 		connect (Ui_.GainSlider_,
 				SIGNAL (valueChanged (int)),
