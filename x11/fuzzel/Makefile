# $FreeBSD$

PORTNAME=	fuzzel
DISTVERSION=	1.4.2
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://codeberg.org/dnkl/${PORTNAME}/commit/
PATCHFILES+=	902f8209cfe2.patch:-p1 # memfd_create
PATCHFILES+=	452c0161f66c.patch:-p1 # _POSIX_C_SOURCE
PATCHFILES+=	544c78f0bfdf.patch:-p1 # epoll-shim

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Application launcher for wlroots-based Wayland compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tllist>=1.0.1:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GNOME=	cairo librsvg2
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/zsh/site-functions/_${PORTNAME}

# XXX Drop after FreeBSD 12.1 EOL
.if exists(/usr/lib/clang/8.0.1)
# prompt.c:45:21: error: suggest braces around initialization of subobject [-Werror,-Wmissing-braces]
CFLAGS+=	-Wno-error=missing-braces
.endif

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/xdg.c

.include <bsd.port.mk>
