# $FreeBSD$

PORTNAME=	slurp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	74c4bdff012a.patch:-p1 7976828fe1a9.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Select a region in a Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -i '' "s/'scdoc/&-disabled/" ${WRKSRC}/meson.build

.include <bsd.port.mk>
