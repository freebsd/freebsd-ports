# New ports collection makefile for:	skippy-xd
# Date created:		2004-05-19
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	skippy-xd
PORTVERSION=	0.5.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen X11 task-switcher like Apple's Expose

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_REINPLACE=	yes
PLIST_FILES=	bin/skippy-xd \
		%%DATADIR%%/skippy-xd.rc-default
PLIST_DIRS=	%%DATADIR%%
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|; \
		s|/usr/local|${LOCALBASE}|; s|gcc|${CC}|' \
			${WRKSRC}/Makefile
post-build:
	@${SED} 's|%%DATADIR%%|${DATADIR}|' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/skippy-xd ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/skippy-xd.rc-default ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
BROKEN=	XFree86 does not support XComposite.
.endif

.include <bsd.port.post.mk>
