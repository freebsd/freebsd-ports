# New ports collection makefile for:	wmbutton
# Date created:			10 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmbutton
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://greek0.net/wmbutton/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that displays 9 buttons to run apps of your choice

LICENSE=	GPLv2

USE_XORG=	xpm

SUB_FILES=	pkg-message

PORTDOCS=	README
PORTEXAMPLES=	dot.wmbutton
PLIST_FILES=	bin/wmbutton

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} \
		-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include \
		wmb_libs.c wmbutton.c -o wmbutton \
		-L${LOCALBASE}/lib -lXpm -lXext -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbutton ${PREFIX}/bin/wmbutton
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmbutton ${EXAMPLESDIR}/dot.wmbutton
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
