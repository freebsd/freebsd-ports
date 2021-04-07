PORTNAME=	xnotify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Read notifications from stdin and display them on the screen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		xorg
USE_GITHUB=	yes
USE_XORG=	x11 xft xinerama
GH_ACCOUNT=	phillbush
MAKE_ARGS=	CC="${CC}" CPPFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LDFLAGS="${LDFLAGS} \$${LIBS}" \
		PREFIX="${PREFIX}" \
		LOCALINC="${LOCALBASE}/include" \
		LOCALLIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		${NULL}
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		${NULL}

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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
