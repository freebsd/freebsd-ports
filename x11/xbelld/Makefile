# New ports collection makefile for:	xbelld
# Date created:				17 September 2004
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	xbelld
PORTVERSION=	0.2b2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.meowfishies.com/code/
DISTNAME=	${PORTNAME}-0.2beta2
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	XBellD is a small daemon for replacing the standard X terminal bell

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_IMAKE=	yes
USE_XORG=	ice sm xtrap xmu xt
USE_GNOME=	esound

PLIST_FILES=	bin/xbelld \
		lib/X11/app-defaults/XBellD
MAN1=		xbelld.1
XFREE86_HTML_MAN=no

post-install:
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
