# New ports collection makefile for:   silo
# Date created:        26 October 2003
# Whom:                DoubleF <doublef@tele-kom.ru>
#
# $FreeBSD$
#

PORTNAME=	silo
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://doublef.nm.ru/silo/sources/

MAINTAINER=	doublef@tele-kom.ru
COMMENT=	A simple X11 launcher extensible in any programming language

USE_BZIP2=	yes
USE_XORG=	xpm x11

pre-everything::
.if defined(WITHOUT_IMLIB)
	@${ECHO_CMD} "Disabling Imlib support; only XPM images are supported"
.else
	@${ECHO_CMD} "You can disable Imlib support by defining WITHOUT_IMLIB"
USE_GNOME=	imlib
.endif

#SRC = silo.c
IMG=	audacitya.png audacityi.png sylpheeda.png sylpheedi.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/silo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pushbutton ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}/img/
	${MKDIR} ${EXAMPLESDIR}/prg/
.for file in ${IMG}
	${INSTALL_DATA} ${WRKSRC}/share/img/${file} ${EXAMPLESDIR}/img/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/share/prg/audacity ${EXAMPLESDIR}/prg/
	${INSTALL_SCRIPT} ${WRKSRC}/share/prg/sylpheed ${EXAMPLESDIR}/prg/
	${INSTALL_SCRIPT} ${WRKSRC}/share/topright.sh ${EXAMPLESDIR}/

.include <bsd.port.mk>
