PORTNAME=	wlrctl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~brocellous/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~brocellous/${PORTNAME}/commit/
PATCHFILES+=	a9f5699256c9.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Utility for miscellaneous wlroots extensions

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
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
