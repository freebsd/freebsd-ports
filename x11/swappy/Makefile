# $FreeBSD$

PORTNAME=	swappy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b59700f47085.patch:-p1 # https://github.com/jtheoof/swappy/pull/42
PATCHFILES+=	f82390dcec74.patch:-p1 # https://github.com/jtheoof/swappy/pull/42
PATCHFILES+=	d7df51363873.patch:-p1 # https://github.com/jtheoof/swappy/pull/42

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Snapshot editing for Wayland (a la Snappy on macOS)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
GH_ACCOUNT=	jtheoof
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	CLIPBOARD ICONSFONT MANPAGES NOTIFY
OPTIONS_DEFAULT=CLIPBOARD ICONSFONT MANPAGES NOTIFY

CLIPBOARD_DESC=		Copy to clipboard support
CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard

ICONSFONT_DESC=		Install Font Awesome to properly render icons
ICONSFONT_RUN_DEPENDS=	font-awesome>0:x11-fonts/font-awesome

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_ENABLED=	libnotify

.include <bsd.port.mk>
