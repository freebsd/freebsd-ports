# ex:ts=8
# Ports collection makefile for:	aewm++
# Date created:			Jan 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aewm++
PORTVERSION=	1.1.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://frankhale.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ version of aewm

DEPRECATED=	The project is dead, a fork exists: xaewm
EXPIRATION_DATE=2006-07-01

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		ADDITIONAL_CFLAGS="" prefix="${PREFIX}" \
		INCLUDES="-I${X11BASE}/include" LIBPATH="-L${X11BASE}/lib"
PLIST_FILES=	bin/aewm++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
