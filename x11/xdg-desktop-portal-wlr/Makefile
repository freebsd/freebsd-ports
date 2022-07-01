PORTNAME=	xdg-desktop-portal-wlr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for wlroots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libinih.so:devel/inih \
		libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		gbm
GH_ACCOUNT=	emersion
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.wlr.service \
		share/xdg-desktop-portal/portals/wlr.portal

OPTIONS_DEFINE=	MANPAGES SLURP
OPTIONS_DEFAULT=MANPAGES SLURP

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man5/${PORTNAME}.5.gz

SLURP_DESC=		Simple output chooser
SLURP_RUN_DEPENDS=	slurp:x11/slurp

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/${PORTNAME}.5.scd

.include <bsd.port.mk>
