# $FreeBSD$

PORTNAME=	labwc
PORTVERSION=	s20210303
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	53a6d4fd32cc.patch:-p1 # https://github.com/johanmalm/labwc/pull/19

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Openbox alternative for Wayland

LICENSE=	GPLv2

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wlroots>=0.11.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_TAGNAME=	2738ff2
USE_GNOME=	cairo libxml2 pango
USE_XORG=	pixman
GH_ACCOUNT=	johanmalm
PLIST_FILES=	"${MAYBE_SUID}bin/${PORTNAME}"

OPTIONS_DEFINE=	MANPAGES SUID X11
OPTIONS_DEFAULT=MANPAGES SUID X11

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man5/${PORTNAME}-actions.5.gz \
			man/man5/${PORTNAME}-config.5.gz \
			man/man5/${PORTNAME}-theme.5.gz

SUID_DESC=		setuid bit on "${PORTNAME}" binary (to claim DRM without seatd/console-kit-daemon)
SUID_VARS=		MAYBE_SUID="@(,,4755) "

X11_MESON_ENABLED=	xwayland

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/docs/${PORTNAME}-config.5.md \
		${WRKSRC}/src/common/dir.c

post-install-MANPAGES-on:
	@${MV} ${STAGEDIR}${PREFIX}/man/man*.1/* ${STAGEDIR}${PREFIX}/man/man1
	@${MV} ${STAGEDIR}${PREFIX}/man/man*.5/* ${STAGEDIR}${PREFIX}/man/man5
	@${FIND} ${STAGEDIR}${PREFIX}/man -type d -empty -delete

.include <bsd.port.mk>
