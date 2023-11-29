PORTNAME=	dwlb
PORTVERSION=	s20231128
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Feature-complete bar for DWL
WWW=		https://github.com/kolunmi/dwlb

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.1:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft

USES=		gmake pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	kolunmi
GH_TAGNAME=	d215054
EXTRA_PATCHES=	${${PORTNAME:tu}_PATCHES}
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
