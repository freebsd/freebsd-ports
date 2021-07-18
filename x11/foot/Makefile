PORTNAME=	foot
DISTVERSION=	1.8.2
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

OPTIONS_DEFINE=	NOTIFY UTF8PROC XDG
OPTIONS_DEFAULT=NOTIFY UTF8PROC XDG

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

UTF8PROC_DESC=		Grapheme clustering using libutf8proc
UTF8PROC_LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc
UTF8PROC_MESON_ENABLED=	grapheme-clustering

XDG_DESC=		Open files with xdg-open
XDG_RUN_DEPENDS=	xdg-open:devel/xdg-utils

.if exists(/usr/bin/tic)
# Add site- suffix to avoid conflict with terminfo-db (part of ncurses)
MESON_ARGS+=	-Dterminfo-install-location="${PLIST_FILES:M*terminfo*:[1]:H:H}"
PKGMESSAGE=	${NONEXISTENT}
PLIST_FILES+=	share/site-terminfo/f/${PORTNAME} \
		share/site-terminfo/f/${PORTNAME}-direct
.else
MESON_ARGS+=	-Dterminfo=disabled
.endif

.include <bsd.port.mk>
