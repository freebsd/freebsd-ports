PORTNAME=	termit
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome

MAINTAINER=	bob@eager.cx
COMMENT=	Small terminal emulator with Lua scripting
WWW=		https://github.com/nonstop/termit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2

USES=		cmake gnome lua:53 pkgconfig xorg
USE_CSTD=	c99

USE_GITHUB=	yes
GH_ACCOUNT=	nonstop
USE_GNOME=	cairo gdkpixbuf gtk30 vte3
USE_XORG=	x11

CPPFLAGS+=	-I${LOCALBASE}/include/vte-0.0

SUB_FILES=	pkg-message

TERMIT_ETC=	${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS NLS
OPTIONS_SUB=	yes

DEBUG_CMAKE_ON=	-DDEBUG:BOOL=YES

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=NO

post-install:
	@${MKDIR} ${TERMIT_ETC}
.for file in colormaps.lua rc.lua utils.lua
	${CP} ${WRKSRC}/etc/termit/${file} ${TERMIT_ETC}/${file}.sample
.endfor

.include <bsd.port.mk>
