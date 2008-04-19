# New ports collection makefile for:	treewm
# Date created:		09 Sep 2003
# Whom:			Rudolf Polzer
#
# $FreeBSD$
#

PORTNAME=	treewm
PORTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Manager that arranges the windows in a tree

BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 ice sm xext xmu xpm xt xxf86vm

PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	AUTHORS ChangeLog INSTALL PROBLEMS README README.tiling TODO default.cfg sample.cfg

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

post-build:
	@${SED} 's|%%D%%|${DOCSDIR}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/src/treewm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xprop/xprop ${PREFIX}/bin/xprop-treewm
	${INSTALL_PROGRAM} ${WRKSRC}/xkill/xkill ${PREFIX}/bin/xkill-treewm
	${INSTALL_DATA} ${WRKSRC}/src/pixmaps/*.xpm ${DATADIR}/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
