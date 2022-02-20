PORTNAME=	wshowkeys
DISTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://github.com/ammgws/${PORTNAME}/commit/
PATCHFILES+=	35b6f15bd088.patch:-p1 # https://old.reddit.com/r/swaywm/comments/ovfzpv/new_custodianmaintainerbugfix_needed_for_wshowkeys/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display keystrokes for screencasts on wlroots compositors

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango
PLIST_FILES=	"@(,video,4750) bin/${PORTNAME}"

.include <bsd.port.mk>
