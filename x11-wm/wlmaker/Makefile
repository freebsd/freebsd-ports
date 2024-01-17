PORTNAME=	wlmaker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-430
DISTVERSIONSUFFIX=	-ged7a302
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	0179c3c5a837.patch:-p1 # https://github.com/phkaeser/libbase/pull/2
PATCHFILES+=	811db3b1582a.patch:-p1 # https://github.com/phkaeser/libbase/pull/2
PATCHFILES+=	486758619471.patch:-p1 # https://github.com/phkaeser/wlmaker/pull/11
PATCHFILES+=	3a64446b128a.patch:-p1 # https://github.com/phkaeser/wlmaker/pull/11
PATCHFILES+=	2a7108e964e0.patch:-p1 # https://github.com/phkaeser/wlmaker/pull/11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland compositor inspired by Window Maker
WWW=		https://github.com/phkaeser/wlmaker

LICENSE=	APACHE20

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.31:graphics/wayland-protocols
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c11 gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	phkaeser
GH_TUPLE=	phkaeser:libbase:c215f7d:libbase/submodules/libbase
LDFLAGS+=	-Wl,--as-needed # https://github.com/phkaeser/wlmaker/issues/12
PLIST_FILES=	bin/${PORTNAME} \
		bin/wlmclock \
		share/icons/${PORTNAME}/chrome-48x48.png \
		share/icons/${PORTNAME}/clip-48x48.png \
		share/icons/${PORTNAME}/firefox-48x48.png \
		share/icons/${PORTNAME}/terminal-48x48.png \
		${NULL}

post-patch:
# Drop dependency on unreleased version of libwayland
	@${REINPLACE_CMD} -e 's/1\.22\.90/1.22.0/' \
		${WRKSRC}/CMakeLists.txt
# Respect LOCALBASE for apps and use open source Chrome
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,' \
		 -e 's/google-chrome/chrome/' \
		${WRKSRC}/src/dock.c \
		${WRKSRC}/src/${PORTNAME}.c

.include <bsd.port.mk>
