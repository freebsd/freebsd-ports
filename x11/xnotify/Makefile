PORTNAME=	xnotify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Read notifications from stdin and display them on the screen
WWW=		https://github.com/phillbush/xnotify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		xorg
USE_GITHUB=	yes
USE_XORG=	x11 xft xinerama
GH_ACCOUNT=	phillbush
EXTRA_PATCHES=	${${PORTNAME:tu}_PATCHES}
MAKE_ARGS=	MANPREFIX="${PREFIX}/share/man"
MAKE_ENV=	LOCALINC="${LOCALBASE}/include" \
		LOCALLIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib" \
		${NULL}
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		${NULL}

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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
