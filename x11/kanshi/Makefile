# $FreeBSD$

PORTNAME=	kanshi
PORTVERSION=	s20190607
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic display configuration for Wayland

LICENSE=	MIT
# https://github.com/emersion/kanshi/issues/45
#LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TAGNAME=	76e9f41
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man5/${PORTNAME}.5.gz

.include <bsd.port.mk>
