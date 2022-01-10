PORTNAME=	wvkbd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard for wlroots

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo pango
GH_ACCOUNT=	jjsullivan5196
MAKE_ARGS=	VERSION="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME}-mobintl
LDFLAGS+=	-Wl,--as-needed # pango deps

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

post-patch:
	@${REINPLACE_CMD} -e '/^PKGS/s/$$/ epoll-shim/' \
		-e 's/ xkbcommon//' \
		-e '/^LDFLAGS/s/=/+=/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} '/^CFLAGS/s/=/+=/' ${WRKSRC}/config.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}*

.include <bsd.port.mk>
