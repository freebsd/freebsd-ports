PORTNAME=	euclid-wm
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Minimalist, tiling window manager for X11

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	wmdiem
GH_PROJECT=	euclid-wm
GH_TAGNAME=	b6b0319

OPTIONS_DEFINE=		XINERAMA EUCLID_MENU
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	XINERAMA
EUCLID_MENU_DESC=	Custom built menuing program (work in progress)

ALL_TARGET=		noxinerama
XINERAMA_ALL_TARGET=	euclid-wm
EUCLID_MENU_ALL_TARGET=	euclid-menu
XINERAMA_USE=		XORG=xinerama

USES=		gmake xorg
USE_XORG=	x11

PLIST_FILES=	bin/euclid-wm \
		bin/start-euclid \
		man/man1/euclid-wm.1.gz \
		share/xsessions/euclid.desktop \
		%%DATADIR%%/VERSION \
		%%DATADIR%%/euclid-wm.conf \
		%%DATADIR%%/euclidrc \
		%%EUCLID_MENU%%bin/euclid-menu \
		%%EUCLID_MENU%%share/euclid-menu/handlers/.echo_file.sh \
		%%EUCLID_MENU%%share/euclid-menu/handlers/c.sh \
		%%EUCLID_MENU%%share/euclid-menu/handlers/default.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/euclid-wm

post-install-EUCLID_MENU-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/euclid-menu

.include <bsd.port.mk>
