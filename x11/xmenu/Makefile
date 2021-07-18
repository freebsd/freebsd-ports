PORTNAME=	xmenu
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.5
CATEGORIES=	x11

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	X11 menu utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libImlib2.so:graphics/imlib2

USES=		compiler:c11 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	phillbush
USE_XORG=	x11 xft xinerama

MAKE_ARGS=	FREETYPEINC="${LOCALBASE}/include/freetype2" \
		MANPREFIX="${PREFIX}/man" \
		PREFIX="${PREFIX}"

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG README.md
PORTEXAMPLES=	icons/* xmenu.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
