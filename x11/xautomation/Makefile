# ex:ts=8
# Ports collection makefile for:	xautomation
# Date created:			Sep 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xautomation
PORTVERSION=	1.03
CATEGORIES=	x11
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control X from the command line for scripts

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XORG=	xtst
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/pat2ppm bin/patextract bin/png2pat bin/rgb2pat \
		bin/visgrep bin/xmousepos bin/xte

MAN1=		pat2ppm.1 patextract.1 png2pat.1 rgb2pat.1 \
		visgrep.1 xmousepos.1 xte.1
MAN7=		xautomation.7

.include <bsd.port.mk>
