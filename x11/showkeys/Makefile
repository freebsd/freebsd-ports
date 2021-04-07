PORTNAME=	showkeys
DISTVERSION=	g20191004
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Display keystrokes during screencasts or presentations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxosd.so:misc/xosd

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	nibrahim
GH_TAGNAME=	187d59c
USE_XORG=	x11 xext xinerama xtst

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
