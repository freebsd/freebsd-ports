# New ports collection makefile for:	Qwt
# Date created:		02 March 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=qwt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qwt widget library for technical purposes

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_BZIP2=	yes
MAKE_ENV=	CXXFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		INCPATH="-I${X11BASE}/include/qt2" \
		LIBS="-L${X11BASE}/lib" \
		QTDIR="${X11BASE}"	\
		MOC=${MOC}
INSTALLS_SHLIB=	yes

MAN3=		QwtAnalogClock.3	\
		QwtArrayData.3		\
		QwtArrowButton.3	\
		QwtAutoScale.3		\
		QwtCPointerData.3	\
		QwtCompass.3		\
		QwtCompassMagnetNeedle.3	\
		QwtCompassWindArrow.3	\
		QwtCounter.3		\
		QwtCurve.3		\
		QwtData.3		\
		QwtDblRange.3		\
		QwtDiMap.3		\
		QwtDial.3		\
		QwtDialNeedle.3		\
		QwtDialScaleDraw.3	\
		QwtDialSimpleNeedle.3	\
		QwtDoublePoint.3	\
		QwtDoublePointData.3	\
		QwtDoubleRect.3		\
		QwtDoubleSize.3		\
		QwtDynGridLayout.3	\
		QwtEventPattern.3	\
		QwtGrid.3		\
		QwtKnob.3		\
		QwtLegend.3		\
		QwtLegendButton.3	\
		QwtLegendItem.3		\
		QwtLegendLabel.3	\
		QwtMarker.3		\
		QwtPaintBuffer.3	\
		QwtPainter.3		\
		QwtPicker.3		\
		QwtPickerClickPointMachine.3	\
		QwtPickerClickRectMachine.3	\
		QwtPickerDragPointMachine.3	\
		QwtPickerDragRectMachine.3	\
		QwtPickerMachine.3		\
		QwtPickerPolygonMachine.3	\
		QwtPlainText.3		\
		QwtPlot.3		\
		QwtPlotCanvas.3		\
		QwtPlotCurve.3		\
		QwtPlotGrid.3		\
		QwtPlotItem.3		\
		QwtPlotLayout.3		\
		QwtPlotMappedItem.3	\
		QwtPlotMarker.3		\
		QwtPlotPicker.3		\
		QwtPlotPrintFilter.3	\
		QwtPlotZoomer.3		\
		QwtPushButton.3		\
		QwtRect.3		\
		QwtRichText.3		\
		QwtScale.3		\
		QwtScaleDiv.3		\
		QwtScaleDraw.3		\
		QwtScaleIf.3		\
		QwtSlider.3		\
		QwtSliderBase.3		\
		QwtSpline.3		\
		QwtSymbol.3		\
		QwtText.3		\
		QwtThermo.3		\
		QwtWheel.3		\
		qwt_math.h.3

pre-build:
	cd ${WRKSRC}; qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qwt.pro -o Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libqwt.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs libqwt.so.${PORTVERSION} ${PREFIX}/lib/libqwt.so
	${LN} -fs libqwt.so.${PORTVERSION} ${PREFIX}/lib/libqwt.so.${PORTVERSION:R:R:R}
	${MKDIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/qwt_math.h.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
