# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	5.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USE_QT_VER=	4
QT_COMPONENTS=	gui svg moc_build qmake_build
USE_BZIP2=	yes
USE_GMAKE=	yes
QMAKE_ARGS+=	-unix -recursive PREFIX=${PREFIX}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

STRIP_FILES=	lib/libqwt.so.${PORTVERSION}

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.man>

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS})

post-install:
	${MKDIR} ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${PREFIX}/man/man3
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
