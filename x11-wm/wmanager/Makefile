# New ports collection makefile for:	wmanager
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmanager
PORTVERSION=	0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://kassandra.techfak.uni-bielefeld.de/mtessmer/wmanager/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk/

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	1
USE_GMAKE=	yes
MAKE_ENV=	prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/wmanager
	${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${PREFIX}/share/wmanager/wmanagerrc_sample
	${INSTALL_DATA} ${WRKSRC}/.xinitrc ${PREFIX}/share/wmanager/xinitrc_sample
.for file in FAQ HISTORY INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/wmanager
.endfor
	@${ECHO}
	@${ECHO} "Docs have been installed in ${PREFIX}/share/wmanager/."
	@${ECHO} "You are advised to have a look at the sample .wmanagerrc"
	@${ECHO} "and .xinitrc's available there."
	@${ECHO}
.endif

.include <bsd.port.mk>
