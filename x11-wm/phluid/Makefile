# New ports collection makefile for:   phluid
# Date created:        11 August 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phluid
PORTVERSION=	0.0.3
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phluid

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS='-I${X11BASE}/include' \
		LIBS='-L${X11BASE}/lib -lX11'

.include <bsd.port.mk>
