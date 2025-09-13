PORTNAME=	hamclock
DISTVERSION=	4.21
CATEGORIES=	x11 hamradio
MASTER_SITES=	https://www.clearskyinstitute.com/ham/HamClock/
DISTNAME=	ESPHamClock

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Handy clock with features for amateur radio operators
WWW=		https://www.clearskyinstitute.com/ham/HamClock/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		desktop-file-utils gmake xorg zip
USE_XORG=	x11

PLIST_FILES=	bin/hamclock \
		share/applications/hamclock.desktop \
		share/icons/hicolor/48x48/apps/hamclock.png

OPTIONS_DEFAULT=		SIZE1
OPTIONS_SINGLE=			RESOLUTION
OPTIONS_SINGLE_RESOLUTION=	SIZE1 SIZE2 SIZE3 SIZE4
SIZE1_DESC=			Use 800x440 resolution
SIZE2_DESC=			Use 1600x960 resolution
SIZE3_DESC=			Use 2400x1440 resolution
SIZE4_DESC=			Use 3200x1920 resolution

SIZE1_ALL_TARGET=	hamclock-800x480
SIZE2_ALL_TARGET=	hamclock-1600x960
SIZE3_ALL_TARGET=	hamclock-2400x1440
SIZE4_ALL_TARGET=	hamclock-3200x1920

post-patch:
	${REINPLACE_CMD} -e 's|CXX =|CXX ?=|g' ${WRKSRC}/ArduinoLib/Makefile
	${REINPLACE_CMD} -e 's|/home/pi/.hamclock/||g' ${WRKSRC}/${PORTNAME}.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

.include <bsd.port.mk>
