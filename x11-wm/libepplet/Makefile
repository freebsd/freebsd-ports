# New ports collection makefile for:	libepplet
# Date created:        			18 October 1999
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	libepplet
PORTVERSION= 	0.5
CATEGORIES=	x11-wm devel
MASTER_SITES=	ftp://ftp.enlightenment.org/e/epplets/
DISTNAME=	epplet-base-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

WRKSRC=		${WRKDIR}/Epplets-0.5

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	EROOT=${X11BASE}/share/enlightenment \
		EBIN=${X11BASE}/bin \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		X_LIBS="-lxpg4"

MAKE_ENV=	${ECHO} -n; cd ${WRKSRC}/api;

.include <bsd.port.mk>
