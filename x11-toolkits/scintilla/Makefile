# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scintilla
DISTVERSION=	4.4.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	scite${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured free source code editing component for GTK+

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++17-lang gmake gnome iconv pkgconfig tar:tgz

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}/gtk
MAKEFILE=	makefile
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
CFLAGS+=	-DPIC ${PICFLAG}

MAKE_ARGS=	GTK3=1
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=	CLANG=1
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h \
		${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_LIB} ${WRKSRC}/../bin/*.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
