# Created by: chinsan
# $FreeBSD$

PORTNAME=	termit
PORTVERSION=	2.10.0
CATEGORIES=	x11-toolkits gnome

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Small terminal emulator with Lua scripting

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	nonstop
GH_COMMIT=	7d6e712

USES=		cmake lua pkgconfig tar:bzip2
USE_GNOME=	gdkpixbuf2 vte

CFLAGS+=	-I${LOCALBASE}/include/vte-0.0

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
