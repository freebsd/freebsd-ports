# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.2
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

.if defined(WITH_HARBOUR)
CONFIGURE_ARGS+=	--enable-harbour
.endif

pre-everything:
.if !defined(WITH_XINERAMA)
	@${ECHO_CMD} "To enable xinerama support define WITH_XINERAMA"
.endif
.if !defined(WITH_HARBOUR)
	@${ECHO_CMD} "To enable basic DockApp support define WITH_HARBOUR"
.endif

MAN1=		pekwm.1

post-install:
	@strip ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
