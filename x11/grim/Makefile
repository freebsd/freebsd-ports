PORTNAME=	grim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Grab images from a Wayland compositor
WWW=		https://gitlab.freedesktop.org/emersion/grim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.37:graphics/wayland-protocols
LIB_DEPENDS=	libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITLAB=	yes
USE_GNOME=	cairo
USE_XORG=	pixman
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	JPEG MANPAGES
OPTIONS_DEFAULT=JPEG MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

JPEG_USES=	jpeg
JPEG_MESON_ENABLED=	jpeg

.include <bsd.port.mk>
