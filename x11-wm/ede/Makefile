# New ports collection makefile for:	ede
# Date created:				28 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ede
PORTVERSION=	1.0.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ede

MAINTAINER=	sem@ciam.ru
COMMENT=	Equinox Desktop Environment

LIB_DEPENDS=	efltk.2:${PORTSDIR}/x11-toolkits/efltk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
USE_AUTOMAKE_VER=	14
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL}

.include <bsd.port.mk>
