# New ports collection makefile for:	E-FancyLauncher
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-FancyLauncher
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://user.it.uu.se/~adavid/Epplets/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible and easily configurable button bar for Enlightenment

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/libepplet

WRKSRC=		${WRKDIR}/E-FancyLauncher

USE_X_PREFIX=	yes

CPPFLAGS=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${X11BASE}/lib -lepplet ${PTHREAD_LIBS}

E_ROOT=		${PREFIX}/share/enlightenment

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME}.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.epplet ${PREFIX}/bin
	@${MKDIR} ${E_ROOT}/epplet_data/${PORTNAME}
	${TAR} -C ${WRKSRC} -cf - E-FancyLauncher.ABOUT 1.gif 2.gif 3.gif | \
		${TAR} -C ${E_ROOT}/epplet_data/${PORTNAME} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREMODE} ${E_ROOT}/epplet_data/${PORTNAME}
	@${MKDIR} ${E_ROOT}/epplet_icons
	${INSTALL_DATA} ${WRKSRC}/E-FancyLauncher.icon ${E_ROOT}/epplet_icons

.include <bsd.port.mk>
