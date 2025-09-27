PORTNAME=	walker
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
CATEGORIES=	x11 wayland
PKGNAMESUFFIX=	-launcher

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Multi-purpose launcher with a lot of features
WWW=		https://github.com/abenz1267/walker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell
RUN_DEPENDS=	elephant:sysutils/elephant

USES=		cargo gnome

USE_GITHUB=	yes
GH_ACCOUNT=	abenz1267

USE_GNOME=	cairo gtk40

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PKGBASE}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/resources/config.toml \
		${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}
	cd ${WRKSRC}/resources && \
	${COPYTREE_SHARE} themes ${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
