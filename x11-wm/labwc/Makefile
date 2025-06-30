PORTNAME=	labwc
DISTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland stacking compositor
WWW=		https://github.com/labwc/labwc

LICENSE=	GPLv2

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.35:graphics/wayland-protocols
LIB_DEPENDS=	libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.18.so:x11-toolkits/wlroots018 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GNOME=	cairo libxml2 pango
USE_XORG=	pixman
GL_TUPLE=	https://gitlab.freedesktop.org:vyivel:libsfdo:v0.1.4:libsfdo/subprojects/libsfdo-basedir
PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/scalable/apps/${PORTNAME}-symbolic.svg \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/wayland-sessions/${PORTNAME}.desktop \
		share/xdg-desktop-portal/${PORTNAME}-portals.conf
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES LIBRSVG2 MANPAGES NLS X11
OPTIONS_DEFAULT=EXAMPLES LIBRSVG2 MANPAGES NLS X11
OPTIONS_EXCLUDE=${LIBRSVG2_DEFAULT:Mlegacy:C/.+/LIBRSVG2/}

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	svg

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}-actions.5.gz \
			share/man/man5/${PORTNAME}-config.5.gz \
			share/man/man5/${PORTNAME}-menu.5.gz \
			share/man/man5/${PORTNAME}-theme.5.gz

NLS_USES=		gettext
NLS_MESON_ENABLED=	nls
NLS_PLIST_FILES=	share/locale/ar/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ca/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/cs/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/da/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/de/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/el/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/et/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/eu/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/fa/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/fi/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/fr/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/gl/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/hu/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/id/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/it/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ja/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ka/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ko/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/lt/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ms/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/nl/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/pa/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/pl/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/pt/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/pt_BR/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/ru/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/sv/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/tr/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/uk/LC_MESSAGES/${PORTNAME}.mo \
			share/locale/zh_CN/LC_MESSAGES/${PORTNAME}.mo

X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_USE=		XORG=xcb
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
# Respect hier(7) for examples
	@${REINPLACE_CMD} '/datadir/s/doc/examples/' \
		${WRKSRC}/docs/meson.build

.ifdef GL_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

.include <bsd.port.mk>
