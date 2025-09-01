PORTNAME=	leftwm
DISTVERSION=	0.5.4
PORTREVISION=	5
CATEGORIES=	x11-wm

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tiling window manager for Adventurers
WWW=		https://leftwm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo desktop-file-utils xorg
USE_GITHUB=	yes
USE_XORG=	xinerama xrandr

CARGO_INSTALL_PATH=	./leftwm

OPTIONS_DEFINE=	DOCS THEMES
OPTIONS_DEFAULT=	THEMES
OPTIONS_SUB=	yes

THEMES_DESC=	LeftWM Basic Themes

post-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/xsessions
	(cd ${WRKSRC} && ${INSTALL_DATA} leftwm.desktop \
		${STAGEDIR}${LOCALBASE}/share/xsessions/)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for l in CHANGELOG.md CONTRIBUTING.md README.md
	${INSTALL_MAN} ${WRKSRC}/${l} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-THEMES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} themes \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
