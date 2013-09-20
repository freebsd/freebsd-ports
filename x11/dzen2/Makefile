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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXPM}
USE_XORG+=	xpm
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.endif

post-patch:
.if ${PORT_OPTIONS:MXPM}
	${REINPLACE_CMD} -e 's/^LIBS =\(.*\)$$/LIBS =\1 -lXpm/g'	\
	  	-e 's/^CFLAGS =\(.*\)$$/CFLAGS =\1 -DDZEN_XPM/g'	\
		${WRKSRC}/config.mk
.endif
.if ${PORT_OPTIONS:MXINERAMA}
	${REINPLACE_CMD} -e 's/^LIBS =\(.*\)$$/LIBS =\1 -lXinerama/g'	\
	  	-e 's/^CFLAGS =\(.*\)$$/CFLAGS =\1 -DDZEN_XINERAMA/g'	\
		${WRKSRC}/config.mk
.endif
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'       \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
