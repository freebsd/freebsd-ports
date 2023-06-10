PORTNAME=	somebar
DISTVERSION=	1.0.3
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~raphi/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	dwm-like bar for dwl
WWW=		https://sr.ht/~raphi/somebar/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GNOME=	cairo pango
EXTRA_PATCHES=	${${PORTNAME:tu}_PATCHES}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

pre-everything::
	@${ECHO_MSG} "To build ${PORTNAME} with your own config.hpp set ${PORTNAME:tu}_CONF variable"
	@${ECHO_MSG} "either in ${.CURDIR:T}/Makefile.local, make.conf(5), environ(7) or command line e.g.,"
	@${ECHO_MSG} "\$$ make install clean ${PORTNAME:tu}_CONF=/path/to/${PORTNAME}/config.hpp"
	@${ECHO_MSG}
	@${ECHO_MSG} "To apply your own patches set ${PORTNAME:tu}_PATCHES (like ${PORTNAME:tu}_CONF)"
	@${ECHO_MSG} "to a list of files separated by space with optional -pX suffix e.g.,"
	@${ECHO_MSG} -n "\$$ make install clean ${PORTNAME:tu}_PATCHES='\$${WRKSRC}/contrib/foo.patch:-p1"
	@${ECHO_MSG} " /path/to/bar.patch'"

post-extract:
	@${ECHO_MSG} "Creating symlink: config.hpp -> ${${PORTNAME:tu}_CONF:Uconfig.def.hpp}"
	@${LN} -fs "${${PORTNAME:tu}_CONF:Uconfig.def.hpp}" ${WRKSRC}/src/config.hpp

.include <bsd.port.mk>
