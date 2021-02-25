# $FreeBSD$

PORTNAME=	foot
DISTVERSION=	1.6.4
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast, lightweight and minimalistic Wayland terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.4:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}

.if exists(/usr/bin/tic)
PKGMESSAGE=	${NONEXISTENT}
PLIST_FILES+=	share/site-terminfo/f/${PORTNAME} \
		share/site-terminfo/f/${PORTNAME}-direct
.else
MESON_ARGS+=	-Dterminfo=disabled
.endif

post-patch:
# Chase default TERMINFO_DIRS on FreeBSD, see lib/ncurses/ncurses/ncurses_cfg.h
	@${REINPLACE_CMD} '/datadir/s/terminfo/site-&/' ${WRKSRC}/meson.build

.include <bsd.port.mk>
