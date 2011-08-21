# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	6.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USE_QT_VER=	4
QT_COMPONENTS=	gui svg xml moc_build qmake_build
USE_BZIP2=	yes
USE_GMAKE=	yes
QMAKE_ARGS+=	-recursive PREFIX=${PREFIX}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

LATEST_LINK=	qwt6

PLIST_SUB=	INCLUDEDIR=include/${LATEST_LINK} \
		SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R}

STRIP_FILES=	lib/libqwt6.so.${PORTVERSION} \
		lib/libqwtmathml.so.${PORTVERSION}

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS})

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
