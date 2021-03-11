# $FreeBSD$

PORTNAME=	mako
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	67f2ed1862a9.patch:-p1 # https://github.com/emersion/mako/pull/311
PATCHFILES+=	affb38d8a4c4.patch:-p1 # https://github.com/emersion/mako/pull/311
PATCHFILES+=	47a1b0b80ca2.patch:-p1
PATCHFILES+=	88e0263a8481.patch:-p1 # https://github.com/emersion/mako/pull/324
PATCHFILES+=	0e9bcb06e0c6.patch:-p1 # https://github.com/emersion/mako/pull/324
PATCHFILES+=	d46e9fd6ced8.patch:-p1 # https://github.com/emersion/mako/pull/345

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight Wayland notification daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
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

.include <bsd.port.mk>
