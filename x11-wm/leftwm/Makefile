PORTNAME=	leftwm
DISTVERSION=	0.5.1
CATEGORIES=	x11-wm

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tiling window manager for Adventurers
WWW=		https://leftwm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	a value of type `Vec<i32>` cannot be built from an iterator over elements of type `i64`

USES=		cargo desktop-file-utils xorg
USE_GITHUB=	yes
USE_XORG=	xinerama xrandr

CARGO_INSTALL_PATH=	./leftwm

OPTIONS_DEFINE=	DOCS THEMES
OPTIONS_DEFAULT=	THEMES
OPTIONS_SUB=	yes

THEMES_DESC=	LeftWM Basic Themes

post-install:
.for l in leftwm-state leftwm-worker leftwm-check \
	leftwm-command leftwm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

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
