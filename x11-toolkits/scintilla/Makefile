# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scintilla
PORTVERSION=	3.6.4
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

USES=		gmake iconv pkgconfig tar:tgz
MAKEFILE=	makefile
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
CFLAGS+=	-DPIC ${PICFLAG}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -Os||g' ${WRKSRC}/makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${STAGEDIR}${PREFIX}/include/scintilla
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla.so.2 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libscintilla.so.2 libscintilla.so)
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla_lexers.so.2 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libscintilla_lexers.so.2 libscintilla_lexers.so)

.include <bsd.port.post.mk>
