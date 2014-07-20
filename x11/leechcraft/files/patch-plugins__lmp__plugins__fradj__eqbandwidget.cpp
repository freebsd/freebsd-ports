--- ./plugins/lmp/plugins/fradj/eqbandwidget.cpp.orig	2014-07-16 15:52:17.270849299 +0400
+++ ./plugins/lmp/plugins/fradj/eqbandwidget.cpp	2014-07-16 15:52:46.079846871 +0400
@@ -98,7 +98,7 @@
 				this,
 				SLOT (setGainBoxValue (int)));
 
-		Ui_.GainSlider_->setValue (std::round (value * SliderPrecision));
+		Ui_.GainSlider_->setValue (round (value * SliderPrecision));
 
 		connect (Ui_.GainSlider_,
 				SIGNAL (valueChanged (int)),
