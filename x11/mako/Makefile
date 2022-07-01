PORTNAME=	mako
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight Wayland notification daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.21:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo pango
GH_ACCOUNT=	emersion
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}ctl \
		share/dbus-1/services/fr.emersion.mako.service

OPTIONS_DEFINE=	MANPAGES PIXBUF
OPTIONS_DEFAULT=MANPAGES PIXBUF

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man1/${PORTNAME}ctl.1.gz \
			man/man5/${PORTNAME}.5.gz

PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_MESON_ENABLED=	icons

post-patch:
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},g' \
		${WRKSRC}/icon.c \
		${WRKSRC}/${PORTNAME}.5.scd

.include <bsd.port.mk>
