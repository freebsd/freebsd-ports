PORTNAME=	halley
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	x11-wm

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Spatial Wayland compositor built around infinite workspace navigation
WWW=		https://saltnpepper97.github.io/halley-site/

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE GPLv3 ISCL MIT MPL20 \
		UNICODE UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS+=	libinput.so:x11/libinput \
		libpipewire-0.3.so:multimedia/pipewire \
		libseat.so:sysutils/seatd \
		libudev.so:devel/libudev-devd \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo gl pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	saltnpepper97
USE_GL=		gbm

CARGO_FEATURES=		dbus,xwayland
CARGO_BUILD_ARGS=	--workspace

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e 's,/usr/bin,${PREFIX}/bin,g' \
		${WRKSRC}/packaging/wayland-sessions/halley-session \
		${WRKSRC}/packaging/dbus-1/services/org.freedesktop.impl.portal.desktop.halley.service

do-install:
. for program in halley halleyctl halley-lift xdg-desktop-portal-halley
	(cd ${CARGO_TARGET_DIR}/release && \
		${INSTALL_PROGRAM} ${program} ${STAGEDIR}${PREFIX}/bin)
. endfor
	${INSTALL_SCRIPT} ${WRKSRC}/packaging/wayland-sessions/halley-session ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/wayland-sessions
	${INSTALL_DATA} ${WRKSRC}/packaging/wayland-sessions/halley.desktop \
		${STAGEDIR}${PREFIX}/share/wayland-sessions/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals
	${INSTALL_DATA} ${WRKSRC}/packaging/xdg-desktop-portal/halley-portals.conf \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/
	${INSTALL_DATA} ${WRKSRC}/packaging/xdg-desktop-portal/portals/halley.portal \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/packaging/dbus-1/services/org.freedesktop.impl.portal.desktop.halley.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
