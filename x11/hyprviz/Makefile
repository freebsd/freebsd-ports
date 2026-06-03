PORTNAME=	hyprviz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GUI for configuring Hyprland
WWW=		https://github.com/timasoft/hyprviz

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gnome

USE_GITHUB=	yes
GH_ACCOUNT=	timasoft

USE_GNOME=	cairo glib20 gtk40

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/icons/hicolor/512x512/apps/${PORTNAME}.png
PORTDOCS=	readme.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/src/system_info.rs

post-install:
	${INSTALL_DATA} ${WRKSRC}/assets/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/assets/${PORTNAME}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg
	${INSTALL_DATA} ${WRKSRC}/assets/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
