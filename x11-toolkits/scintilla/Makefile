# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scintilla
DISTVERSION=	4.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	scite${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured free source code editing component for GTK+

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USES=		compiler:c++14-lang gmake iconv pkgconfig tar:tgz
MAKEFILE=	makefile
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
CFLAGS+=	-DPIC ${PICFLAG}

MAJOR=		2
AGE=		0
REVISION=	0
MAKE_ARGS=	MAJOR="${MAJOR}" AGE="${AGE}" REVISION="${REVISION}"
PLIST_SUB=	MAJOR="${MAJOR}" AGE="${AGE}" REVISION="${REVISION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -Os||g' ${WRKSRC}/makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${STAGEDIR}${PREFIX}/include/scintilla
.for f in libscintilla.so libscintilla_lexers.so
	${INSTALL_LIB} ${WRKSRC}/${f}.${MAJOR}.${AGE}.${REVISION} \
		${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -sf ${f}.${MAJOR}.${AGE}.${REVISION} ${f}.${MAJOR} && \
		${LN} -sf ${f}.${MAJOR} ${f})
.endfor

.include <bsd.port.post.mk>
