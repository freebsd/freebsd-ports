# $FreeBSD$

PORTNAME=	hikari
DISTVERSION=	1.1.0
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
MAKE_ARGS=	${WITH_DEBUG:DDEBUG=YES}
SUB_FILES=	${PORTNAME}.desktop
SUB_LIST=	COMMENT="${COMMENT}"
PLIST_FILES=	"${MAYBE_SUID}bin/${PORTNAME}" \
		"${MAYBE_SUID}bin/${PORTNAME}-unlocker" \
		etc/pam.d/${PORTNAME}-unlocker \
		share/man/man1/${PORTNAME}.1.gz \
		share/wayland-sessions/${PORTNAME}.desktop
PORTEXAMPLES=	${PORTNAME}.conf

OPTIONS_DEFINE=		EXAMPLES GAMMA LAYERSHELL SCREENCOPY SUID X11
OPTIONS_DEFAULT=	GAMMA LAYERSHELL SCREENCOPY SUID X11

GAMMA_DESC=		Include gammacontrol protocol (required by, e.g., Redshift)
LAYERSHELL_DESC=	Include layer_shell protocol (required by, e.g., waybar)
SCREENCOPY_DESC=	Include screenshot protocol (required by, e.g., grim)
SUID_DESC=		Setuid bit on binaries (required for DRM and PAM)

GAMMA_MAKE_ARGS=	WITH_GAMMACONTROL=YES
LAYERSHELL_MAKE_ARGS=	WITH_LAYERSHELL=YES
SCREENCOPY_MAKE_ARGS=	WITH_SCREENCOPY=YES
SUID_VARS=		MAYBE_SUID="@(,,4755) "
X11_MAKE_ARGS=		WITH_XWAYLAND=YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hikari ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/hikari-unlocker ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/pam.d/hikari-unlocker.FreeBSD ${STAGEDIR}${PREFIX}/etc/pam.d/hikari-unlocker
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/share/examples/hikari/hikari.conf ${STAGEDIR}${EXAMPLESDIR}/hikari.conf
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/hikari.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/wayland-sessions
	${INSTALL_DATA} ${WRKDIR}/hikari.desktop ${STAGEDIR}${PREFIX}/share/wayland-sessions

.include <bsd.port.mk>
