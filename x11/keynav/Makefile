# New ports collection makefile for:   keynav
# Date created:        29 June 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	keynav
DISTVERSION=	0.20100302.2713
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://semicomplete.googlecode.com/files/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Quickly select a portion of the screen using minimal keystrokes

LIB_DEPENDS=	xdo.2:${PORTSDIR}/x11/xdotool

USE_GNOME=	glib20
USE_XORG=	xtst x11 xinerama
USE_GMAKE=	yes

PLIST_FILES=	bin/keynav
PORTEXAMPLES=	keynavrc
MAKE_JOBS_SAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynav ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/keynavrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
