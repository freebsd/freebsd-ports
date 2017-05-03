# Created by: chinsan
# $FreeBSD$

PORTNAME=	termit
PORTVERSION=	3.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	x11-toolkits gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small terminal emulator with Lua scripting

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libgnutls.so:security/gnutls

USE_GITHUB=	yes
GH_ACCOUNT=	nonstop

USES=		cmake lua pkgconfig
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 gtk30 vte3

CPPFLAGS+=	-I${LOCALBASE}/include/vte-0.0

TERMIT_ETC=	${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS NLS
OPTIONS_SUB=	yes

DEBUG_CMAKE_ON=	-DDEBUG:BOOL=YES

NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=NO
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} 's|share/man|man|; s|../COPYING||' \
		${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} 's|OpenBSD|${OPSYS}|; s|lua52|lua-${LUA_VER}|' \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} 's|ADD_SUBDIRECTORY(etc)||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/src/lua_conf.c

post-install:
	@${MKDIR} ${TERMIT_ETC}
.for file in colormaps.lua rc.lua utils.lua
	${CP} ${WRKSRC}/etc/termit/${file} ${TERMIT_ETC}/${file}.sample
.endfor

.include <bsd.port.mk>
