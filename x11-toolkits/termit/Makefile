PORTNAME=	termit
PORTVERSION=	3.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	x11-toolkits gnome

MAINTAINER=	bob@eager.cx
COMMENT=	Small terminal emulator with Lua scripting

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libgnutls.so:security/gnutls

USES=		cmake gnome lua:53+ pkgconfig xorg
USE_CSTD=	c99
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 gtk30 vte3

USE_GITHUB=	yes
GH_ACCOUNT=	nonstop

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include/vte-0.0

TERMIT_ETC=	${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS NLS
OPTIONS_SUB=	yes

DEBUG_CMAKE_ON=	-DDEBUG:BOOL=YES

NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=NO
NLS_USES=	gettext

post-install:
	@${MKDIR} ${TERMIT_ETC}
.for file in colormaps.lua rc.lua utils.lua
	${CP} ${WRKSRC}/etc/termit/${file} ${TERMIT_ETC}/${file}.sample
.endfor

.include <bsd.port.mk>
