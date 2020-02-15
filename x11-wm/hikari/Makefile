# $FreeBSD$

PORTNAME=	hikari
DISTVERSION=	1.0.0-alpha3
CATEGORIES=	x11-wm
MASTER_SITES=	https://acmelabs.space/~raichoo/

MAINTAINER=	ports@xanderio.de
COMMENT=	Stacking Wayland compositor with tiling capabilities

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.9.0<0.11.0:x11-toolkits/wlroots
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libinput.so:x11/libinput \
		libucl.so:textproc/libucl \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome pkgconfig xorg
USE_GNOME=	cairo glib20 pango
USE_XORG=	pixman
ALL_TARGET=	${WITH_DEBUG:Ddebug}
PLIST_FILES=	"${MAYBE_SUID}bin/${PORTNAME}" \
		"${MAYBE_SUID}bin/${PORTNAME}-unlocker"
PORTEXAMPLES=	${PORTNAME}.conf

OPTIONS_DEFINE=		EXAMPLES SUID X11
OPTIONS_DEFAULT=	SUID

SUID_DESC=	setuid bit on binaries (required for DRM and PAM)

SUID_VARS=	MAYBE_SUID="@(,,4755) "
X11_MAKE_ARGS=	WITH_XWAYLAND=yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hikari ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/hikari-unlocker ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/example_hikari.conf ${STAGEDIR}${EXAMPLESDIR}/hikari.conf

.include <bsd.port.mk>
