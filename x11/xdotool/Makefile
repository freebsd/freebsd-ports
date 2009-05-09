# New ports collection makefile for:   xdotool
# Date created:        29 June 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	xdotool
DISTVERSION=	20090330
CATEGORIES=	x11
MASTER_SITES=	http://semicomplete.googlecode.com/files/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Programatically simulate keyboard input or mouse activity

USE_GNOME=	pkgconfig
USE_XORG=	x11 xtst
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/xdotool
MAKE_JOBS_SAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdotool ${PREFIX}/bin

# Older GCC on RELENG_6 doesn't like -Wno-missing-field-initializers
post-patch:
	@${REINPLACE_CMD} -e 's,-Wno-missing-field-initializers,,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
