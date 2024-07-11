PORTNAME=	scintilla
DISTVERSION=	5.5.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://www.scintilla.org/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured free source code editing component for GTK
WWW=		https://www.scintilla.org/

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Lexilla, Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++17-lang cpe gmake gnome iconv pkgconfig tar:tgz

USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes

MAKEFILE=	makefile
MAKE_ARGS=	GTK3=1
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

CFLAGS+=	-DPIC -fpic

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=	CLANG=1
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h \
		${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_LIB} ${WRKSRC}/../bin/*.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
