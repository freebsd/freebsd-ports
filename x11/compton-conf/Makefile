# $FreeBSD$

PORTNAME=	compton-conf
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Controls compton settings

LICENSE=	LGPL21+

LIB_DEPENDS=	libconfig.so:devel/libconfig
RUN_DEPENDS=	compton:x11-wm/compton

USES=	cmake compiler:c++11-lib localbase:ldflags lxqt qt:5 \
	pkgconfig tar:xz
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools

PLIST_FILES=	bin/compton-conf \
		share/applications/compton-conf.desktop \
 		etc/xdg/autostart/lxqt-compton.desktop \
		${DATADIR}/compton.conf.example

.include <bsd.port.mk>
