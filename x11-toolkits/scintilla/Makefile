# New ports collection makefile for:	scintilla
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scintilla
PORTVERSION=	1.42
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	scite${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gnome@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	makefile

post-extract:
	@${PERL} -pi -e  's|\x0d||' ${WRKSRC}/../include/*.h

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h ${PREFIX}/include/scintilla
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla.so.1 ${PREFIX}/lib/libscintilla.so
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/libscintilla_lexers.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libscintilla_lexers.so.1 ${PREFIX}/lib/libscintilla_lexers.so

.include <bsd.port.mk>
