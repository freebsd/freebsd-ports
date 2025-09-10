PORTNAME=	hyprviz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GUI for configuring Hyprland
WWW=		https://github.com/timasoft/hyprviz

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gnome

USE_GITHUB=	yes
GH_ACCOUNT=	timasoft

USE_GNOME=	glib20 gtk40

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop
PORTDOCS=	readme.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
