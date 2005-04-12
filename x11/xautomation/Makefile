# ex:ts=8
# Ports collection makefile for:	xautomation
# Date created:			Sep 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xautomation
PORTVERSION=	0.96
CATEGORIES=	x11
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control X from the command line for scripts

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_FILES=	bin/pat2ppm bin/patextract bin/png2pat bin/rgb2pat \
		bin/visgrep bin/xte

.include <bsd.port.mk>
