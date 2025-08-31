PORTNAME=	wvkbd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~proycon/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard for wlroots
WWW=		https://git.sr.ht/~proycon/wvkbd

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland

USES=		gmake gnome pkgconfig
USE_GNOME=	cairo pango
EXTRA_PATCHES=	${${PORTNAME:tu}_PATCHES}
MAKE_ARGS=	VERSION="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME}-mobintl \
		share/man/man1/${PORTNAME}.1.gz
LDFLAGS+=	-Wl,--as-needed # pango deps

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
	@${REINPLACE_CMD} -e '/^PKGS/s/$$/ epoll-shim/' \
		-e 's/ xkbcommon//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^PREFIX/s/=/?=/' \
		-e '/^CFLAGS/s/=/+=/' \
		${WRKSRC}/config.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}*

.include <bsd.port.mk>
