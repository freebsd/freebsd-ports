PORTNAME=	nwg-displays
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.25
CATEGORIES=	x11 wayland python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Output management utility for sway and Hyprland
WWW=		https://github.com/nwg-piotr/nwg-displays

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}i3ipc>0:x11/py-i3ipc@${PY_FLAVOR}

USES=		gnome python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	nwg-piotr

USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	nwg_displays/main.py

PLIST_FILES=	share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.svg
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
