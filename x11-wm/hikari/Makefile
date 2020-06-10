# $FreeBSD$

PORTNAME=	hikari
DISTVERSION=	2.0.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://hikari.acmelabs.space/releases/

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

MAKE_ARGS+=	${WITH_DEBUG:DDEBUG=YES} \
		WITHOUT_SUID=YES

OPTIONS_DEFINE=		GAMMA LAYERSHELL SCREENCOPY SUID X11
OPTIONS_DEFAULT=	GAMMA LAYERSHELL SCREENCOPY SUID X11

GAMMA_DESC=		Include gammacontrol protocol (required by, e.g., Redshift)
LAYERSHELL_DESC=	Include layer_shell protocol (required by, e.g., waybar)
SCREENCOPY_DESC=	Include screenshot protocol (required by, e.g., grim)
SUID_DESC=		Setuid bit on binaries (required for DRM and PAM)

GAMMA_MAKE_ARGS=	WITH_GAMMACONTROL=YES
LAYERSHELL_MAKE_ARGS=	WITH_LAYERSHELL=YES
SCREENCOPY_MAKE_ARGS=	WITH_SCREENCOPY=YES
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""
X11_MAKE_ARGS=		WITH_XWAYLAND=YES

post-install:
.ifndef WITH_DEBUG
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hikari
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hikari-unlocker
.endif
	${MV} ${STAGEDIR}${ETCDIR}/hikari.conf \
		${STAGEDIR}${ETCDIR}/hikari.conf.sample

.include <bsd.port.mk>
