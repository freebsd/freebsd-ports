# New ports collection makefile for:	skippy
# Date created:		2004-05-15
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	skippy
PORTVERSION=	0.5.0
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen X11 task-switcher like Apple's Expose

USE_XORG=	x11 xext xinerama xft xmu
USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_EFL=	imlib2
PLIST_FILES=	bin/skippy \
		%%DATADIR%%/skippyrc-default
PLIST_DIRS=	%%DATADIR%%
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|; \
		s|/usr/local|${LOCALBASE}|; s|gcc|${CC}|' \
			${WRKSRC}/Makefile
post-build:
	@${SED} 's|%%DATADIR%%|${DATADIR}|' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/skippy ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/skippyrc-default ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
