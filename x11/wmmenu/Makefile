# New ports collection makefile for:	wmmenu
# Date created:		16 November 2000
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	wmmenu
PORTVERSION=	0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.fcoutant.freesurf.fr/download/

MAINTAINER=	karlj000@unbc.ca

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp:install \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_GMAKE=	yes

post-patch:
	@ ${MV} ${WRKSRC}/example/defaults ${WRKSRC}/example/defaults.presed
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${WRKSRC}/example/defaults.presed \
	> ${WRKSRC}/example/defaults

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmmenu ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/wmmenu
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmmenu
	${MKDIR} ${PREFIX}/share/doc/wmmenu/example
	${INSTALL_DATA} ${WRKSRC}/example/apps ${PREFIX}/share/doc/wmmenu/example
	${INSTALL_DATA} ${WRKSRC}/example/defaults ${PREFIX}/share/doc/wmmenu/example

post-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.mk>
