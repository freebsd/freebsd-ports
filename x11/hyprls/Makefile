PORTNAME=	hyprls
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	LSP server for Hyprland config files
WWW=		https://gwen.works/hyprls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	nodefault
GH_TUPLE=	hyprwm:hyprland-wiki:e0ea9da1f78890ead3233cc26e6f5fd3ffc91517:hyprland_wiki/hyprland-wiki

GO_MODULE=	github.com/hyprland-community/hyprls
GO_TARGET=	./cmd/hyprls

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
