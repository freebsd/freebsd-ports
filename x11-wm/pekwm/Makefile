# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.pekdon.net/files/source/

MAINTAINER=	anders@andersa.net
COMMENT=	A windowmanager based on aewm++

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

.if defined(WITH_PCRE)
CONFIGURE_ARGS+=       --enable-pcre
CONFIGURE_ENV= LDFLAGS="-L${LOCALBASE}/lib"
LIB_DEPENDS+=  pcre.0:${PORTSDIR}/devel/pcre
.endif

pre-everything::
.if !defined(WITH_XINERAMA)
	@${ECHO_CMD} "To enable xinerama support define WITH_XINERAMA"
.endif
.if !defined(WITH_HARBOUR)
	@${ECHO_CMD} "To enable basic DockApp support define WITH_HARBOUR"
.endif
.if !defined(WITH_PCRE)
	@${ECHO_CMD} "To enable pcre support define WITH_PCRE"
.endif

MAN1=		pekwm.1

post-install:
	@strip ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
