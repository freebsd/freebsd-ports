PORTNAME=	fswm
DISTVERSION=	g20230808
CATEGORIES=	x11-wm

MAINTAINER=	pyrus@bsdmail.com
COMMENT=	Fullscreen window manager in XCB
WWW=		https://github.com/pbizopoulos/fswm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	pbizopoulos
GH_TAGNAME=	ce007a8
USE_XORG=	xcb

MAKE_ARGS=	CC="cc" \
		CFLAGS="${CFLAGS}" \
		LDLIBS="${LDFLAGS} ${LIBS} -lxcb -lxcb-keysyms -lxcb-util" \
		PREFIX="${PREFIX}"
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS SXHKD THINGYLAUNCH

SXHKD_DESC=		Depend on SXHKD (Simple X hotkey daemon)
THINGYLAUNCH_DESC=	Depend on the thingylaunch launcher

SXHKD_RUN_DEPENDS=		sxhkd:x11/sxhkd
THINGYLAUNCH_RUN_DEPENDS=	thingylaunch:x11/thingylaunch

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/fswm
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
