# New ports collection makefile for:	Qwt
# Date created:		02 March 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	0.4.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=qwt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qwt widget library for technical purposes

USE_QT_VER=	3
USE_BZIP2=	yes
MAKE_ENV=	CXXFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		INCPATH="-I${X11BASE}/include/qt2" \
		LIBS="-L${X11BASE}/lib" \
		QTDIR="${X11BASE}"	\
		MOC=${MOC}

MAN3=		Qwt.3			\
		QwtArrowButton.3	\
		QwtAutoScale.3		\
		QwtCounter.3		\
		QwtCurve.3		\
		QwtDblRange.3		\
		QwtDiMap.3		\
		QwtGrid.3		\
		QwtKnob.3		\
		QwtLegend.3		\
		QwtLegendItem.3		\
		QwtMarker.3		\
		QwtPlot.3		\
		QwtPlotCanvas.3		\
		QwtPlotCurve.3		\
		QwtPlotGrid.3		\
		QwtPlotItem.3		\
		QwtPlotMappedItem.3	\
		QwtPlotMarker.3		\
		QwtPlotPrintFilter.3	\
		QwtRect.3		\
		QwtScale.3		\
		QwtScaleDiv.3		\
		QwtScaleDraw.3		\
		QwtScaleIf.3		\
		QwtSlider.3		\
		QwtSliderBase.3		\
		QwtSpline.3		\
		QwtSymbol.3		\
		QwtThermo.3		\
		QwtWheel.3		\
		changes.3		\
		install.3		\
		qwt_math.h.3		\
		screenshots.3

pre-build:
	cd ${WRKSRC}; qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qwt.pro -o Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libqwt.so.0.4.1 ${PREFIX}/lib
	${LN} -fs libqwt.so.0.4.1 ${PREFIX}/lib/libqwt.so
	${MKDIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/* ${PREFIX}/man/man3

.include <bsd.port.mk>
