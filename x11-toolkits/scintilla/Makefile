# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scintilla
PORTVERSION=	3.3.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	scite${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured free source code editing component for GTK+

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USES=		gmake iconv pkgconfig
MAKEFILE=	makefile
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
CFLAGS+=	-DPIC ${PICFLAG}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

CCISCLANG!=     ${CC} --version

.if empty(CCISCLANG:M*clang*)
CPPSTDRE=	-e 's|--std=c++0x||'
.else
CPPSTDRE=	
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]CC[)]|(CXX)|g ; s|[(]CCOMP[)]|(CC)|g' \
		${CPPSTDRE} \
		${WRKSRC}/makefile

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${PREFIX}/include/scintilla
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla.so.2 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla.so.2 ${PREFIX}/lib/libscintilla.so
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla_lexers.so.2 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla_lexers.so.2 ${PREFIX}/lib/libscintilla_lexers.so

.include <bsd.port.post.mk>
