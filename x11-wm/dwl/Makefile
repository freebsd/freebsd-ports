PORTNAME=	dwl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
CATEGORIES=	x11-wm wayland
MASTER_SITES=	https://codeberg.org/${PORTNAME}/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	dwm for Wayland
WWW=		https://codeberg.org/dwl/dwl

LICENSE=	CC0-1.0 GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE.tinywl
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.dwm

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots-0.18.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gmake pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRA_PATCHES=	${${PORTNAME:tu}_PATCHES}
MAKE_ARGS=	CC="${CC}" VERSION="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/wayland-sessions/${PORTNAME}.desktop
PORTDOCS=	README.md

OPTIONS_DEFINE=	ADDONS DOCS X11
OPTIONS_DEFAULT=ADDONS X11

ADDONS_DESC=		Install extra applications: ${ADDONS_RUN_DEPENDS:C/\:.*//}
ADDONS_RUN_DEPENDS?=	foot:x11/foot \
			bemenu-run:x11/bemenu

X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_USES=		xorg
X11_USE=		XORG=xcb
X11_MAKE_ARGS=		XWAYLAND="-DXWAYLAND" XLIBS="xcb xcb-icccm"

pre-everything::
	@${ECHO_MSG} "To build ${PORTNAME} with your own config.h set ${PORTNAME:tu}_CONF variable"
	@${ECHO_MSG} "either in ${.CURDIR:T}/Makefile.local, make.conf(5), environ(7) or command line e.g.,"
	@${ECHO_MSG} "\$$ make install clean ${PORTNAME:tu}_CONF=/path/to/${PORTNAME}/config.h"
	@${ECHO_MSG}
	@${ECHO_MSG} "To apply your own patches set ${PORTNAME:tu}_PATCHES (like ${PORTNAME:tu}_CONF)"
	@${ECHO_MSG} "to a list of files separated by space with optional -pX suffix e.g.,"
	@${ECHO_MSG} "\$$ make install clean ${PORTNAME:tu}_PATCHES='/path/to/foo.patch:-p1'"

post-extract:
# .if exists(...) before bsd.port.mk ignores *_CONF in make.conf(5) and Makefile.local
	@if [ -e "${${PORTNAME:tu}_CONF}" ]; then \
		${ECHO_MSG} "Creating symlink: config.h -> ${${PORTNAME:tu}_CONF}"; \
		${LN} -fs "${${PORTNAME:tu}_CONF}" ${WRKSRC}/config.h; \
	fi

post-patch:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=275328
	@${REINPLACE_CMD} -e 's/_POSIX_C_SOURCE=200809L/_XOPEN_SOURCE=700/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/wayland-sessions
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/wayland-sessions
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
