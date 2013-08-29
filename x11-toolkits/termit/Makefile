# Created by: chinsan
# $FreeBSD$

PORTNAME=	termit
PORTVERSION=	2.9.6
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://cloud.github.com/downloads/nonstop/termit/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Small terminal emulator

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_LUA=	yes
USE_GNOME=	gdkpixbuf2 vte

CFLAGS+=	-I${LOCALBASE}/include/vte-0.0

MAN1=		${PORTNAME}.1

TERMIT_ETC=	${PREFIX}/etc/xdg/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS NLS
OPTIONS_SUB=	yes

DEBUG_CMAKE_ON=	-DDEBUG:BOOL=YES

NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=NO
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} 's|../COPYING||' ${WRKSRC}/doc/CMakeLists.txt
.else
	@${REINPLACE_CMD} '/TERMIT_DOCS/s|^|#|' ${WRKSRC}/doc/CMakeLists.txt
.endif
	@${REINPLACE_CMD} 's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} 's|ADD_SUBDIRECTORY(etc)||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/src/lua_conf.c
	@${REINPLACE_CMD} 's|/usr/lib/liblua.a|${LUA_LIBDIR}/liblua.a|' \
		${WRKSRC}/src/CMakeLists.txt

post-install:
	${MKDIR} ${TERMIT_ETC}
.for file in colormaps.lua rc.lua utils.lua
	${CP} ${WRKSRC}/etc/termit/${file} ${TERMIT_ETC}/${file}.sample
	@if [ ! -f ${TERMIT_ETC}/${file} ]; then \
		${CP} -p ${TERMIT_ETC}/${file}.sample ${TERMIT_ETC}/${file}; \
	fi
.endfor

.include <bsd.port.mk>
