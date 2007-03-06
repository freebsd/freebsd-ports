# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	5.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Qt Widgets for Technical Applications

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

CONFLICTS=	qwt-4.*

USE_QT_VER=	3
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"
USE_LDCONFIG=	yes

OPTIONS=	DESIGNER_PLUGIN "Install plugin for Qt Designer" on

QMAKE=		qmake
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
PLUGINDIR=	${PREFIX}/lib/kde3/plugins/designer

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.man>

.if !defined(WITHOUT_DESIGNER_PLUGIN)
PLIST_SUB+=	DESIGNER_PLUGIN=""
.else
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.endif

QPRO_DIRS=	src
.if !defined(WITHOUT_DESIGNER_PLUGIN)
QPRO_DIRS+=	designer
.endif

do-build:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d} && ${QMAKE} -spec ${QMAKESPEC} && \
	${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/${d}/Makefile && \
	${SETENV} ${MAKE_ENV} ${GMAKE})
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libqwt.so.5.0.0 ${PREFIX}/lib/libqwt.so.5
	${LN} -fs ${PREFIX}/lib/libqwt.so.5 ${PREFIX}/lib/libqwt.so
	${MKDIR} ${PREFIX}/include/qwt && \
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include/qwt
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${PREFIX}/man/man3
.if !defined(WITHOUT_DESIGNER_PLUGIN)
	${MKDIR} ${PLUGINDIR} && \
	${INSTALL_DATA} ${WRKSRC}/designer/plugins/designer/libqwtplugin.so ${PLUGINDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qwt && \
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/qwt
.endif

.include <bsd.port.post.mk>
