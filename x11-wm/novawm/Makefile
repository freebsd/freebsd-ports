# New ports collection makefile for:	NovaWM
# Date created:				20 June 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	novawm
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	NovaWM-${PORTVERSION}_alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A window manager for X, developed with speed, size, and style in mind

USE_BZIP2=	yes
USE_XORG=	x11 xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	INCLUDES=-I${LOCALBASE}/include \
		CXXFLAGS="${CXXFLAGS} -D_WIN_GNOME_SUPPORT" \
		novawm_LDFLAGS=-L${LOCALBASE}/lib

PLIST_FILES=	bin/novawm
.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog INSTALL README TODO
.endif

DEPRECATED=	 	Project is dead
EXPIRATION_DATE=	2007-10-28

post-extract:
	@${CHMOD} -R +w ${WRKSRC}/src/xpm/.xvpics
	@${CHMOD} -R +w ${WRKSRC}/.xvpics

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
