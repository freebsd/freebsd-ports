# New ports collection makefile for:	scintilla
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scintilla
PORTVERSION=	1.58
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	scite${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A full-featured free source code editing component for GTK+

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME=	gtk12
MAKE_ARGS=	GTK1=yes
.endif

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${PREFIX}/include/scintilla
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla.so.1 ${PREFIX}/lib/libscintilla.so
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla_lexers.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla_lexers.so.1 ${PREFIX}/lib/libscintilla_lexers.so

.include <bsd.port.mk>
