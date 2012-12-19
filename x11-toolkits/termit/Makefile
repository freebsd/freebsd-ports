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

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_PKGCONFIG=	build
USE_ICONV=	yes
USE_LUA=	yes
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
USE_GNOME=	gdkpixbuf2 vte
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include/vte-0.0

MAN1=		${PORTNAME}.1

TERMIT_ETC=	${PREFIX}/etc/xdg/${PORTNAME}

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DDEBUG:BOOL=YES
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=NO
PLIST_SUB+=	NLS="@comment "
.endif

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
