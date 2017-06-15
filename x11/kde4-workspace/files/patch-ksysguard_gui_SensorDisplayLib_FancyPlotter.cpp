* Fix the unit handling in KSysGuard's Plotter to respect user's unit preferences
*
* Improve the handling of labels so the display is nicer when horizontally constrained
*
* Use reasonable units for the Plotter's tooltip (used to be unscaled)
*
* Allow a stored description for sensors to override the label
*
--- ksysguard/gui/SensorDisplayLib/FancyPlotter.cpp.orig	2015-06-26 03:17:21 UTC
+++ ksysguard/gui/SensorDisplayLib/FancyPlotter.cpp
@@ -48,6 +48,7 @@ class SensorToAdd {
     QRegExp name;
     QString hostname;
     QString type;
+    QString description;
     QList<QColor> colors;
     QString summationName;
 };
@@ -58,13 +59,15 @@ class FancyPlotterLabel : public QLabel 
         setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
         longHeadingWidth = 0;
         shortHeadingWidth = 0;
+        minHeadingWidth = 0;
         textMargin = 0;
         setLayoutDirection(Qt::LeftToRight); //We do this because we organise the strings ourselves.. is this going to muck it up though for RTL languages?
     }
     ~FancyPlotterLabel() {
     }
     void setLabel(const QString &name, const QColor &color) {
-        labelName = name;
+        labelLongName = name;
+        labelShortName = name.split(QChar(' ')).first();
 
         if(indicatorSymbol.isNull()) {
             if(fontMetrics().inFont(QChar(0x25CF)))
@@ -73,7 +76,6 @@ class FancyPlotterLabel : public QLabel 
                 indicatorSymbol = '#';
         }
         changeLabel(color);
-
     }
     void setValueText(const QString &value) {
         //value can have multiple strings, separated with the 0x9c character
@@ -87,63 +89,72 @@ class FancyPlotterLabel : public QLabel 
         if(valueText.isEmpty()) {
             if(longHeadingWidth < width())
                 setText(longHeadingText);
-            else
+            else if(shortHeadingWidth < width())
                 setText(shortHeadingText);
+            else
+                setText(minHeadingText);
             return;
         }
-        QString value = valueText.first();
 
-        int textWidth = fm.boundingRect(value).width();
-        if(textWidth + longHeadingWidth < width())
-            setBothText(longHeadingText, value);
-        else if(textWidth + shortHeadingWidth < width())
-            setBothText(shortHeadingText, value);
-        else {
-            int valueTextCount = valueText.count();
-            int i;
-            for(i = 1; i < valueTextCount; ++i) {
-                textWidth = fm.boundingRect(valueText.at(i)).width();
-                if(textWidth + shortHeadingWidth <= width()) {
-                    break;
-                }
+        int i, textWidth, valueTextCount = valueText.count();
+        for(i = 0; i < valueTextCount; ++i) {
+            textWidth = fm.boundingRect(valueText.at(i)).width();
+            if(textWidth + longHeadingWidth <= width()) {
+                setBothText(longHeadingText, valueText.at(i));
+                return;
             }
-            if(i < valueTextCount)
+            if(textWidth + shortHeadingWidth <= width()) {
                 setBothText(shortHeadingText, valueText.at(i));
-            else
-                setText(noHeadingText + valueText.last()); //This just sets the color of the text
+                return;
+            }
         }
+        for(i = 0; i < valueTextCount; ++i) {
+            textWidth = fm.boundingRect(valueText.at(i)).width();
+            if(textWidth + minHeadingWidth <= width()) {
+                setBothText(minHeadingText, valueText.at(i));
+                return;
+            }
+        }
+        setBothText(noHeadingText, valueText.last()); //This just sets the color of the text
     }
     void changeLabel(const QColor &_color) {
         color = _color;
 
-        if ( kapp->layoutDirection() == Qt::RightToLeft )
-            longHeadingText = QString(": ") + labelName + " <font color=\"" + color.name() + "\">" + indicatorSymbol + "</font>";
-        else
-            longHeadingText = QString("<qt><font color=\"") + color.name() + "\">" + indicatorSymbol + "</font> " + labelName + " :";
-        shortHeadingText = QString("<qt><font color=\"") + color.name() + "\">" + indicatorSymbol + "</font>";
+        if ( kapp->layoutDirection() == Qt::RightToLeft ) {
+            longHeadingText = QString(" : ") + labelLongName + " <font color=\"" + color.name() + "\">" + indicatorSymbol + "</font>";
+            shortHeadingText = QString(" :") + labelShortName + " <font color=\"" + color.name() + "\">" + indicatorSymbol + "</font>";
+        } else {
+            longHeadingText = QString("<qt><font color=\"") + color.name() + "\">" + indicatorSymbol + "</font> " + labelLongName + " : ";
+            shortHeadingText = QString("<qt><font color=\"") + color.name() + "\">" + indicatorSymbol + "</font> " + labelShortName + ": ";
+        }
+        minHeadingText = QString("<qt><font color=\"") + color.name() + "\">" + indicatorSymbol + "</font> ";
         noHeadingText = QString("<qt><font color=\"") + color.name() + "\">";
 
-        textMargin = fontMetrics().width('x') + margin()*2 + frameWidth()*2;
-        longHeadingWidth = fontMetrics().boundingRect(labelName + " :" + indicatorSymbol + " x").width() + textMargin;
-        shortHeadingWidth = fontMetrics().boundingRect(indicatorSymbol).width() + textMargin;
-        setMinimumWidth(shortHeadingWidth);
+        textMargin = margin()*2 + frameWidth()*2;
+        longHeadingWidth = fontMetrics().boundingRect(labelLongName + " : " + indicatorSymbol + " x").width() + textMargin;
+        shortHeadingWidth = fontMetrics().boundingRect(labelShortName + ": " + indicatorSymbol + " x").width() + textMargin;
+        minHeadingWidth = fontMetrics().boundingRect(indicatorSymbol + " x").width() + textMargin;
+        setMinimumWidth(minHeadingWidth);
         update();
     }
   private:
     void setBothText(const QString &heading, const QString & value) {
         if(QApplication::layoutDirection() == Qt::LeftToRight)
-            setText(heading + ' ' + value);
+            setText(heading + value);
         else
-            setText("<qt>" + value + ' ' + heading);
+            setText("<qt>" + value + heading);
     }
     int textMargin;
     QString longHeadingText;
     QString shortHeadingText;
+    QString minHeadingText;
     QString noHeadingText;
     int longHeadingWidth;
     int shortHeadingWidth;
+    int minHeadingWidth;
     QList<QString> valueText;
-    QString labelName;
+    QString labelLongName;
+    QString labelShortName;
     QColor color;
     static QChar indicatorSymbol;
 };
@@ -162,6 +173,7 @@ FancyPlotter::FancyPlotter( QWidget* par
     mUseManualRange = false;
     mNumAnswers = 0;
     mLabelsWidget = NULL;
+    mRealUnits = (KGlobal::locale()->binaryUnitDialect() == KLocale::JEDECBinaryDialect);
 
     //The unicode character 0x25CF is a big filled in circle.  We would prefer to use this in the tooltip.
     //However it's maybe possible that the font used to draw the tooltip won't have it.  So we fall back to a 
@@ -510,10 +522,17 @@ void FancyPlotter::setTooltip()
 
         if(sensor->isOk()) {
             lastValue = KGlobal::locale()->formatNumber( sensor->lastValue, (sensor->isInteger)?0:-1 );
-            if (sensor->unit() == "%")
+            if (sensor->unit() == "%") {
                 lastValue = i18nc("units", "%1%", lastValue);
-            else if( !sensor->unit().isEmpty() )
-                lastValue = i18nc("units", QString(QString("%1 ") + sensor->unit()).toUtf8(), lastValue);
+            } else if( !sensor->unit().isEmpty() ) {
+                qreal scale = (mPlotter->scaleDownBy() == 1) ? 1 : (sensor->lastValue / mPlotter->scaleDownBy() < 0.1) ? (mPlotter->scaleDownBy() / 1024) : mPlotter->scaleDownBy();
+                if(scale > 1) {
+                    QString unit = (scale == 1024) ? (sensor->unit()).replace("K","M") : (scale == 1024*1024) ? (sensor->unit()).replace("K","G") : (sensor->unit()).replace("K","T");
+                    lastValue = i18nc("units", QString(QString("%1 ") + unit).toUtf8(), KGlobal::locale()->formatNumber( sensor->lastValue / scale ));
+                } else {
+                    lastValue = i18nc("units", QString(QString("%1 ") + sensor->unit()).toUtf8(), lastValue);
+                }
+            }
         } else {
             lastValue = i18n("Error");
         }
@@ -615,33 +634,33 @@ void FancyPlotter::plotterAxisScaleChang
     disconnect(mPlotter, SIGNAL(axisScaleChanged()), this, SLOT(plotterAxisScaleChanged()));
     KLocalizedString unit;
     double value = mPlotter->currentMaximumRangeValue();
-    if(mUnit  == "KiB") {
-        if(value >= 1024*1024*1024*0.7) {  //If it's over 0.7TiB, then set the scale to terabytes
+    if(mUnit  == "KB" || mUnit == "KiB") {
+        if(value >= 1024*1024*1024) {
             mPlotter->setScaleDownBy(1024*1024*1024);
-            unit = ki18nc("units", "%1 TiB"); // the unit - terabytes
-        } else if(value >= 1024*1024*0.7) {  //If it's over 0.7GiB, then set the scale to gigabytes
+            unit = ki18nc("units", mRealUnits ? "%1 TB" : "%1 TiB"); // the unit - terabytes
+        } else if(value >= 1024*1024) {
             mPlotter->setScaleDownBy(1024*1024);
-            unit = ki18nc("units", "%1 GiB"); // the unit - gigabytes
+            unit = ki18nc("units", mRealUnits ? "%1 GB" : "%1 GiB"); // the unit - gigabytes
         } else if(value > 1024) {
             mPlotter->setScaleDownBy(1024);
-            unit = ki18nc("units", "%1 MiB"); // the unit - megabytes
+            unit = ki18nc("units", mRealUnits ? "%1 MB" : "%1 MiB"); // the unit - megabytes
         } else {
             mPlotter->setScaleDownBy(1);
-            unit = ki18nc("units", "%1 KiB"); // the unit - kilobytes
+            unit = ki18nc("units", mRealUnits ? "%1 KB" : "%1 KiB"); // the unit - kilobytes
         }
-    } else if(mUnit == "KiB/s") {
-        if(value >= 1024*1024*1024*0.7) {  //If it's over 0.7TiB, then set the scale to terabytes
+    } else if(mUnit == "KB/s" || mUnit == "KiB/s") {
+        if(value >= 1024*1024*1024) {
             mPlotter->setScaleDownBy(1024*1024*1024);
-            unit = ki18nc("units", "%1 TiB/s"); // the unit - terabytes per second
-        } else if(value >= 1024*1024*0.7) {  //If it's over 0.7GiB, then set the scale to gigabytes
+            unit = ki18nc("units", mRealUnits ? "%1 TB/s" : "%1 TiB/s"); // the unit - terabytes per second
+        } else if(value >= 1024*1024) {
             mPlotter->setScaleDownBy(1024*1024);
-            unit = ki18nc("units", "%1 GiB/s"); // the unit - gigabytes per second
+            unit = ki18nc("units", mRealUnits ? "%1 GB/s" : "%1 GiB/s"); // the unit - gigabytes per second
         } else if(value > 1024) {
             mPlotter->setScaleDownBy(1024);
-            unit = ki18nc("units", "%1 MiB/s"); // the unit - megabytes per second
+            unit = ki18nc("units", mRealUnits ? "%1 MB/s" : "%1 MiB/s"); // the unit - megabytes per second
         } else {
             mPlotter->setScaleDownBy(1);
-            unit = ki18nc("units", "%1 KiB/s"); // the unit - kilobytes per second
+            unit = ki18nc("units", mRealUnits ? "%1 KB/s" : "%1 KiB/s"); // the unit - kilobytes per second
         }
     } else if(mUnit == "%") {
         mPlotter->setScaleDownBy(1);
@@ -694,9 +713,9 @@ void FancyPlotter::answerReceived( int i
         KSGRD::SensorFloatInfo info( answer );
         QString unit = info.unit();
         if(unit.toUpper() == "KB" || unit.toUpper() == "KIB")
-            unit = "KiB";
+            unit = mRealUnits ? "KB" : "KiB";
         if(unit.toUpper() == "KB/S" || unit.toUpper() == "KIB/S")
-            unit = "KiB/s";
+            unit = mRealUnits ? "KB/s" : "KiB/s";
 
         if(id == 100) //if we are the first sensor, just use that sensors units as the global unit
             mUnit = unit;
@@ -714,7 +733,8 @@ void FancyPlotter::answerReceived( int i
         sensor->maxValue = info.max();
         sensor->minValue = info.min();
         sensor->setUnit( unit );
-        sensor->setDescription( info.name() );
+        if(sensor->description().isEmpty())
+            sensor->setDescription( info.name() );
 
         QString summationName = sensor->summationName;
         int beamId = sensor->beamId;
@@ -723,7 +743,7 @@ void FancyPlotter::answerReceived( int i
         Q_ASSERT(beamId < mLabelLayout->count());
 
         if(summationName.isEmpty())
-            static_cast<FancyPlotterLabel *>((static_cast<QWidgetItem *>(mLabelLayout->itemAt(beamId)))->widget())->setLabel(info.name(), mPlotter->beamColor(beamId));
+            static_cast<FancyPlotterLabel *>((static_cast<QWidgetItem *>(mLabelLayout->itemAt(beamId)))->widget())->setLabel(sensor->description(), mPlotter->beamColor(beamId));
 
     } else if( id == 200) {
         /* FIXME This doesn't check the host!  */
@@ -743,8 +763,8 @@ void FancyPlotter::answerReceived( int i
                         else if(KSGRD::Style->numSensorColors() != 0)
                             color = KSGRD::Style->sensorColor( beamId % KSGRD::Style->numSensorColors());
                         addSensor( sensor->hostname, sensorName,
-                                (sensor->type.isEmpty()) ? "float" : sensor->type
-                                , "", color, sensor->name.pattern(), beamId, sensor->summationName);
+                                (sensor->type.isEmpty()) ? "float" : sensor->type,
+                                sensor->description, color, sensor->name.pattern(), beamId, sensor->summationName);
                     }
                 }
             }
@@ -823,7 +843,7 @@ bool FancyPlotter::restoreSettings( QDom
         } else
             addSensor( el.attribute( "hostName" ), el.attribute( "sensorName" ),
                     ( el.attribute( "sensorType" ).isEmpty() ? "float" :
-                      el.attribute( "sensorType" ) ), "", restoreColor( el, "color",
+                      el.attribute( "sensorType" ) ), el.attribute( "description" ), restoreColor( el, "color",
                       KSGRD::Style->sensorColor( i ) ), QString(), mBeams, el.attribute("summationName") );
     }
 
@@ -873,16 +893,18 @@ bool FancyPlotter::saveSettings( QDomDoc
         } else {
             QDomElement beam = doc.createElement( "beam" );
             element.appendChild( beam );
+            beam.setAttribute( "sensorType", sensor->type() );
             beam.setAttribute( "hostName", sensor->hostName() );
-            if(regExpName.isEmpty())
+            if(regExpName.isEmpty()) {
                 beam.setAttribute( "sensorName", sensor->name() );
-            else {
+                if(sensor->hasDescription)
+                    beam.setAttribute( "description", sensor->description() );
+            } else {
                 beam.setAttribute( "regexpSensorName", sensor->regExpName() );
                 hash[regExpName] = beam;
+                if(!sensor->summationName.isEmpty())
+                    beam.setAttribute( "summationName", sensor->summationName);
             }
-            if(!sensor->summationName.isEmpty())
-                beam.setAttribute( "summationName", sensor->summationName);
-            beam.setAttribute( "sensorType", sensor->type() );
             saveColor( beam, "color", mPlotter->beamColor( beamId ) );
         }
     }
@@ -918,6 +940,7 @@ FPSensorProperties::FPSensorProperties( 
     minValue = 0;
     lastValue = 0;
     isInteger = (type == "integer");
+    hasDescription = !description.isEmpty();
 }
 
 FPSensorProperties::~FPSensorProperties()
