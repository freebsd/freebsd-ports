# New ports collection makefile for:	ede
# Date created:				28 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ede
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ede

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Equinox Desktop Environment

LIB_DEPENDS=	efltk.2:${PORTSDIR}/x11-toolkits/efltk

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL}

.include <bsd.port.mk>
