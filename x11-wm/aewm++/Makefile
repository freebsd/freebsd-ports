# ex:ts=8
# Ports collection makefile for:	aewm++
# Date created:			Jan 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aewm++
PORTVERSION=	1.0.29
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sapphire

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ version of aewm

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		ADDITIONAL_CFLAGS="" prefix="${PREFIX}" \
		INCLUDES="-I${X11BASE}/include" LIBPATH="-L${X11BASE}/lib"
MAN1=		aewm++.1x
PLIST_FILES=	bin/aewm++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
