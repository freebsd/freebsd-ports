PORTNAME=	xdg-desktop-portal-wlr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ebb50839a560.patch:-p1 # https://github.com/emersion/xdg-desktop-portal-wlr/pull/114

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for wlroots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libiniparser.so:devel/iniparser \
		libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire

USES=		compiler:c11 localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.wlr.service \
		share/xdg-desktop-portal/portals/wlr.portal

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/${PORTNAME}.5.scd

.include <bsd.port.mk>
