PORTNAME=	euclid-wm
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	x11-wm

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Minimalist, tiling window manager for X11
WWW=		https://euclid-wm.sourceforge.net

LICENSE=	BSD3CLAUSE

USES=		gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	wmdiem
GH_TAGNAME=	b6b0319
USE_XORG=	x11

ALL_TARGET=		noxinerama

PLIST_FILES=	bin/euclid-wm \
		bin/start-euclid \
		share/man/man1/euclid-wm.1.gz \
		share/xsessions/euclid.desktop \
		%%DATADIR%%/VERSION \
		%%DATADIR%%/euclid-wm.conf \
		%%DATADIR%%/euclidrc \
		%%EUCLID_MENU%%bin/euclid-menu \
		%%EUCLID_MENU%%share/euclid-menu/handlers/.echo_file.sh \
		%%EUCLID_MENU%%share/euclid-menu/handlers/c.sh \
		%%EUCLID_MENU%%share/euclid-menu/handlers/default.sh

OPTIONS_DEFINE=		XINERAMA EUCLID_MENU
OPTIONS_DEFAULT=	XINERAMA
OPTIONS_SUB=		yes

EUCLID_MENU_DESC=	Custom built menuing program (work in progress)

EUCLID_MENU_ALL_TARGET=	euclid-menu
XINERAMA_USE=		XORG=xinerama
XINERAMA_ALL_TARGET=	euclid-wm

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e 's|^CFLAGS = |CFLAGS = -Wno-error=int-conversion |g' \
		${WRKSRC}/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/euclid-wm

post-install-EUCLID_MENU-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/euclid-menu

.include <bsd.port.post.mk>
