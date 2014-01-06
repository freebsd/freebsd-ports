# Created by: Morten Slot Kristensen
# $FreeBSD$

PORTNAME=	dzen2
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://gotmor.googlepages.com/

MAINTAINER=	msk@nullpointer.dk
COMMENT=	General purpose messaging, notification and menuing program for X11

USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	XPM XINERAMA
OPTIONS_DEFAULT=	XPM XINERAMA

LDFLAGS=	-L${LOCALBASE}/lib
CFLAGS=		-I${LOCALBASE}/include
XPM_USE=	XORG=xpm
XPM_CFLAGS=	-DDZEN_XPM
XPM_LDFLAGS=	-lXpm
XINERAMA_USE=	XORG=xinerama
XINERAMA_LDFLAGS=	-lXinerama
XINERAMA_CLAGS=	-DDZEN_XINERAMA

MAKE_ARGS=	LDFLAGS="${LDFLAGS} \$${LIBS}" \
		CFLAGS="${CFLAGS} ${INCS} -DVERSION=\\\"\$${VERSION}\\\""

.include <bsd.port.mk>
