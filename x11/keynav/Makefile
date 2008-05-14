# New ports collection makefile for:   keynav
# Date created:        29 June 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	keynav
DISTVERSION=	20080509
CATEGORIES=	x11
MASTER_SITES=	http://www.semicomplete.com/files/keynav/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Quickly select a portion of the screen using minimal keystrokes

USE_GNOME=	pkgconfig
USE_XORG=	xtst x11
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/keynav
PORTEXAMPLES=	keynavrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynav ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/keynavrc ${EXAMPLESDIR}
.endif

# Because gcc in RELENG_6 doesn't support -Wno-missing-field-initializers
post-patch:
	@${REINPLACE_CMD} -e 's,-Wno-missing-field-initializers,,' ${WRKSRC}/xdotool/Makefile

.include <bsd.port.mk>
