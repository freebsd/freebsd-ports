# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.babblica.net/files/source/

MAINTAINER=	anders@hack.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.if defined(WITH_XINERAMA)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.if !defined(WITH_XINERAMA)
pre-everything:
	@${ECHO_CMD} "To enable xinerama support define WITH_XINERAMA"
.endif

post-install:
	@strip ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
