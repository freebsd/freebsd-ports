# New ports collection makefile for:	plib
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	plib
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	des@FreeBSD.org
COMMENT=	A portable library for joystick/sound/OpenGL GUI/3D math

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-GL=${X11BASE} --with-x

.include <bsd.port.mk>
