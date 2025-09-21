PORTNAME=	hyprls
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	LSP server for Hyprland config files
WWW=		https://gwen.works/hyprls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25,modules

USE_GITHUB=	nodefault
GH_TUPLE=	hyprwm:hyprland-wiki:6c123a2f295b6b1846511587df0b68616dff1a47:hyprland_wiki/hyprland-wiki

GO_MODULE=	github.com/hyprland-community/hyprls
GO_TARGET=	./cmd/hyprls

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
