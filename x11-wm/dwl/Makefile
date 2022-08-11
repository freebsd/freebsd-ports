PORTNAME=	dwl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cba259e9bf4a.patch:-p1 # https://github.com/djpohly/dwl/pull/212

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	dwm for Wayland

LICENSE=	CC0-1.0 GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE.tinywl
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.dwm

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		wlroots>=0.15.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	djpohly
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/wayland-sessions/${PORTNAME}.desktop
PORTDOCS=	README.md

OPTIONS_DEFINE=	ADDONS DOCS X11
OPTIONS_DEFAULT=ADDONS X11

ADDONS_DESC=		Install extra applications: ${ADDONS_RUN_DEPENDS:C/\:.*//}
ADDONS_RUN_DEPENDS?=	alacritty:x11/alacritty \
			bemenu-run:x11/bemenu

X11_USES=		xorg
X11_USE=		XORG=xcb
X11_CFLAGS=		-DXWAYLAND

pre-everything::
	@${ECHO_MSG} "To build ${PORTNAME} with your own config.h set ${PORTNAME:tu}_CONF variable"
	@${ECHO_MSG} "either in ${.CURDIR:T}/Makefile.local, make.conf(5), environ(7) or command line e.g.,"
	@${ECHO_MSG} "\$$ make install clean ${PORTNAME:tu}_CONF=/path/to/${PORTNAME}/config.h"

post-extract:
# .if exists(...) before bsd.port.mk ignores *_CONF in make.conf(5) and Makefile.local
	@if [ -e "${${PORTNAME:tu}_CONF}" ]; then \
		${ECHO_MSG} "Creating symlink: config.h -> ${${PORTNAME:tu}_CONF}"; \
		${LN} -fs "${${PORTNAME:tu}_CONF}" ${WRKSRC}/config.h; \
	fi

post-patch-X11-off:
	@${REINPLACE_CMD} 's/ xcb//' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/wayland-sessions
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/wayland-sessions
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
