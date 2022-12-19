PORTNAME=	labwc
DISTVERSION=	0.6.0
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	1e66ba8fd75e.patch:-p1 # https://github.com/labwc/labwc/pull/629
PATCHFILES+=	ae17cd2c8d57.patch:-p1 # https://github.com/labwc/labwc/pull/682

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland stacking compositor
WWW=		https://github.com/labwc/labwc

LICENSE=	GPLv2

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		wlroots>=0.16.0<0.17.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo libxml2 pango
PLIST_FILES=	bin/${PORTNAME} \
		share/wayland-sessions/${PORTNAME}.desktop

OPTIONS_DEFINE=	MANPAGES NLS X11
OPTIONS_DEFAULT=MANPAGES NLS X11

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man5/${PORTNAME}-actions.5.gz \
			man/man5/${PORTNAME}-config.5.gz \
			man/man5/${PORTNAME}-menu.5.gz \
			man/man5/${PORTNAME}-theme.5.gz

NLS_USES=		gettext
NLS_MESON_ENABLED=	nls
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/it/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/sv/LC_MESSAGES/${PORTNAME}.mo

X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_MESON_ENABLED=	xwayland

post-patch:
# Force system dependencies
	@${RM} ${WRKSRC}/subprojects/*.wrap
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Respect PREFIX for system-wide config and Openbox themes
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/docs/${PORTNAME}-config.5.scd \
		${WRKSRC}/src/common/dir.c
# XXX Drop after FreeBSD 12.3 EOL around 2023-03-01
# https://cgit.freebsd.org/src/commit/?id=773538247007
	@if [ ${OPSYS} = FreeBSD -a ${OSVERSION} -lt 1203501 ]; then \
		${REINPLACE_CMD} -e '/_POSIX_C_SOURCE/d' ${WRKSRC}/src/cursor.c; \
	fi

.include <bsd.port.mk>
