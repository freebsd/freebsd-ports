# New ports collection makefile for:	wmanager
# Version required:	0.2
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	wmanager-0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://heuss.techfak.uni-bielefeld.de/www/mtessmer/wmanager/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk/

USE_QT=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
MAKE_ENV=	prefix=${PREFIX}

WRKSRC=		${WRKDIR}/wmanager

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/wmanager
	@${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${PREFIX}/share/wmanager/wmanagerrc_sample
	@${INSTALL_DATA} ${WRKSRC}/.xinitrc ${PREFIX}/share/wmanager/xinitrc_sample
	@${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/wmanager/
	@${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/wmanager/
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/wmanager/
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/wmanager/
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/wmanager/
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/wmanager/
	@${ECHO}
	@${ECHO} "Docs have been installed in ${PREFIX}/share/wmanager/."
	@${ECHO} "You are advised to have a look at the sample .wmanagerrc"
	@${ECHO} "and .xinitrc's available there."
	@${ECHO}

.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${PREFIX}/bin

.include <bsd.port.mk>
