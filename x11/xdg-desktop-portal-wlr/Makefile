PORTNAME=	xdg-desktop-portal-wlr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	32b009a12aa5.patch:-p1 # https://github.com/emersion/xdg-desktop-portal-wlr/pull/308

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for wlroots
WWW=		https://github.com/emersion/xdg-desktop-portal-wlr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libinih.so:devel/inih \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		grim:x11/grim \
		slurp:x11/slurp

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		gbm
GH_ACCOUNT=	emersion
MESON_ARGS=	-Dsd-bus-provider=basu -Dsystemd=disabled
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.wlr.service \
		share/xdg-desktop-portal/portals/wlr.portal

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/${PORTNAME}.5.scd

.include <bsd.port.mk>
