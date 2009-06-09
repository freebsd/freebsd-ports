# New ports collection makefile for:	dynamag
# Date created:        			2000-09-22
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	dynamag
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11 accessibility
MASTER_SITES=	ftp://trace.wisc.edu/pub/access_utils/unix/
DISTNAME=	unwindows
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Magnifying utility which updates continuously

ALL_TARGET=	dynamag
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/dynamag
USE_IMAKE=	yes
USE_XORG=	x11 xaw xext xmu xt xpm sm ice
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dynamag ${PREFIX}/bin

.include <bsd.port.mk>
