# ex:ts=8
# Ports collection makefile for:	xautomation
# Date created:			Sep 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xautomation
PORTVERSION=	0.86
CATEGORIES=	x11
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
