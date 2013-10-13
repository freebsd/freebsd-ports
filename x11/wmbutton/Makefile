# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmbutton
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://greek0.net/wmbutton/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays 9 buttons to run apps of your choice

LICENSE=	GPLv2

USE_XORG=	xpm

SUB_FILES=	pkg-message

PORTDOCS=	README
PORTEXAMPLES=	dot.wmbutton
PLIST_FILES=	bin/wmbutton

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} \
		-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include \
		wmb_libs.c wmbutton.c -o wmbutton \
		-L${LOCALBASE}/lib -lXpm -lXext -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbutton ${PREFIX}/bin/wmbutton
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmbutton ${EXAMPLESDIR}/dot.wmbutton
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
