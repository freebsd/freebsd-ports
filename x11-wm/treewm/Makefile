# New ports collection makefile for:	treewm
# Date created:		09 Sep 2003
# Whom:			Rudolf Polzer
#
# $FreeBSD$
#

PORTNAME=	treewm
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd-dr@durchnull.de
COMMENT=	Window Manager that arranges the windows in a tree

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	AUTHORS ChangeLog INSTALL PROBLEMS README README.tiling TODO default.cfg sample.cfg

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-build:
	@${SED} 's|%%D%%|${DOCSDIR}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/share/treewm
	${MKDIR} ${PREFIX}/share/treewm/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/src/treewm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xprop/xprop ${PREFIX}/bin/xprop-treewm
	${INSTALL_PROGRAM} ${WRKSRC}/xkill/xkill ${PREFIX}/bin/xkill-treewm
	${INSTALL_DATA} ${WRKSRC}/src/pixmaps/*.xpm ${PREFIX}/share/treewm/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
