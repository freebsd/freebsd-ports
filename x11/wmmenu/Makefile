# New ports collection makefile for:	wmmenu
# Date created:		16 November 2000
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	wmmenu
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.fcoutant.freesurf.fr/download/

MAINTAINER=	karlj000@unbc.ca
COMMENT=	A popup menu of icons that launch programs for the WindowMaker dock

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	libcapplet gdkpixbuf
USE_GMAKE=	yes

MAN1=		wmmenu.1

post-patch:
	@${MV} ${WRKSRC}/example/defaults ${WRKSRC}/example/defaults.presed
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${WRKSRC}/example/defaults.presed \
	> ${WRKSRC}/example/defaults

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wmmenu
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmmenu
	${INSTALL_DATA} ${WRKSRC}/example/apps ${PREFIX}/share/doc/wmmenu/apps.sample
	${INSTALL_DATA} ${WRKSRC}/example/defaults ${PREFIX}/share/doc/wmmenu/defaults.sample
.endif
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${PKGMESSAGE} | ${SED} -e 's#%%PORTNAME%%#${PORTNAME}#g'

.include <bsd.port.mk>
