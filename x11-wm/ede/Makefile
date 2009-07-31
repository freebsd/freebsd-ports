# New ports collection makefile for:	ede
# Date created:				28 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ede
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Equinox Desktop Environment

LIB_DEPENDS=	efltk.2:${PORTSDIR}/x11-toolkits/efltk

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL}

.include <bsd.port.mk>
