# New ports collection makefile for:	skippy-xd
# Date created:		2004-05-19
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	skippy-xd
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://cdn.thegraveyard.org/releases/skippy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen X11 task-switcher like Apple's Expose

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2 \
		pkg-config>0:${PORTSDIR}/devel/pkg-config

USE_BZIP2=	yes
USE_XORG=	x11 xft xcomposite xdamage xfixes xrender xinerama xext xmu
PLIST_FILES=	bin/skippy-xd \
		%%DATADIR%%/skippy-xd.rc-default
PLIST_DIRS=	%%DATADIR%%
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|; \
		s|/usr/local|${LOCALBASE}|; s|gcc|${CC}|' \
			${WRKSRC}/Makefile

.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e 's|CARD32|CARD64|g' \
		${WRKSRC}/clientwin.c ${WRKSRC}/skippy.c \
		${WRKSRC}/wm.c ${WRKSRC}/wm.h
.endif

post-build:
	@${SED} 's|%%DATADIR%%|${DATADIR}|' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/skippy-xd ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/skippy-xd.rc-default ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
