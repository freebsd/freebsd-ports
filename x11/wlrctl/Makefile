PORTNAME=	wlrctl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~brocellous/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Utility for miscellaneous wlroots extensions
WWW=		https://git.sr.ht/~brocellous/wlrctl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig
PLIST_FILES=	bin/${PORTNAME} \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
