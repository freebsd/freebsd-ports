# New ports collection makefile for:	scintilla
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/scintilla/Makefile,v 1.3 2006/09/17 21:58:56 marcus Exp $

PORTNAME=	scintilla
PORTVERSION=	1.78
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	scite${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A full-featured free source code editing component for GTK+

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_GMAKE=	yes
USE_ICONV=	yes
MAKEFILE=	makefile
USE_LDCONFIG=	yes

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
PKGNAMESUFFIX:=	-gtk2
.else
USE_GNOME=	gtk12
MAKE_ARGS+=	GTK1=yes
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
MAKE_ARGS+=	PICFLAGS=-DPIC
.else
MAKE_ARGS+=	PICFLAGS="-DPIC -fPIC -fpic"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]CC[)]|(CXX)|g ; s|[(]CCOMP[)]|(CC)|g ; \
		s| -Os||g' ${WRKSRC}/makefile

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${PREFIX}/include/scintilla
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla.so.1 ${PREFIX}/lib/libscintilla.so
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla_lexers.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla_lexers.so.1 ${PREFIX}/lib/libscintilla_lexers.so

.include <bsd.port.post.mk>
