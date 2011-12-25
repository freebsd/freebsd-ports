# New ports collection makefile for:	termit
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	termit
PORTVERSION=	2.9.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://cloud.github.com/downloads/nonstop/termit/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Small terminal emulator

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNOME=	vte
USE_LUA=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1

TERMIT_ETC=	${PREFIX}/etc/xdg/${PORTNAME}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DDEBUG:BOOL=YES
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=NO
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|../COPYING||' ${WRKSRC}/doc/CMakeLists.txt
.else
	@${REINPLACE_CMD} '/TERMIT_DOCS/s|^|#|' ${WRKSRC}/doc/CMakeLists.txt
.endif
	@${REINPLACE_CMD} 's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} 's|ADD_SUBDIRECTORY(etc)||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/src/lua_conf.c

post-install:
	${MKDIR} ${TERMIT_ETC}
.for file in colormaps.lua rc.lua utils.lua
	${CP} ${WRKSRC}/etc/termit/${file} ${TERMIT_ETC}/${file}.sample
	@if [ ! -f ${TERMIT_ETC}/${file} ]; then \
		${CP} -p ${TERMIT_ETC}/${file}.sample ${TERMIT_ETC}/${file}; \
	fi
.endfor

.include <bsd.port.mk>
