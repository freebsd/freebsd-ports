# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	5.0.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Qt Widgets for Technical Applications

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build
USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	DESIGNER_PLUGIN "Install plugin for Qt Designer" on

PLUGINDIR=	${PREFIX}/lib/qt4/plugins/designer

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.man>

QPRO_DIRS=	src
.if !defined(WITHOUT_DESIGNER_PLUGIN)
QPRO_DIRS+=	designer
#QT_COMPONENTS+=	designer xml rcc_build
BUILD_DEPENDS+=	${LOCALBASE}/bin/rcc:${PORTSDIR}/devel/qt4-rcc
LIB_DEPENDS+=	QtXml:${PORTSDIR}/textproc/qt4-xml \
		QtDesigner:${PORTSDIR}/devel/qt4-designer
PLIST_SUB+=	DESIGNER_PLUGIN=""
.else
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.endif

do-configure:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -unix)
.endfor

post-configure:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d} && \
	${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/${d}/Makefile)
.endfor

do-build:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d}; ${SETENV} ${MAKE_ENV} ${GMAKE})
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqwt.so.${PORTVERSION} ${PREFIX}/lib/libqwt.so.${PORTVERSION:R:R}
	${LN} -fs ${PREFIX}/lib/libqwt.so.${PORTVERSION:R:R} ${PREFIX}/lib/libqwt.so
	(cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} '*.h' ${PREFIX}/include/${PORTNAME})
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${PREFIX}/man/man3
.if !defined(WITHOUT_DESIGNER_PLUGIN)
	${MKDIR} ${PLUGINDIR} && \
	${INSTALL_PROGRAM} ${WRKSRC}/designer/plugins/designer/libqwt_designer_plugin.so ${PLUGINDIR}
.endif
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
