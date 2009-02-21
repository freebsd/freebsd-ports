# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	5.1.1
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

OPTIONS=	DESIGNER_PLUGIN "Install plugin for Qt Designer" on

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.man>

.if !defined(WITHOUT_DESIGNER_PLUGIN)
#QT_COMPONENTS+=	designer rcc_build
BUILD_DEPENDS+=	${LOCALBASE}/bin/rcc:${PORTSDIR}/devel/qt4-rcc
LIB_DEPENDS+=	QtDesigner:${PORTSDIR}/devel/qt4-designer
QMAKE_ARGS+=	CONFIG+=QwtDesigner PLUGINDIR=${PREFIX}/lib/qt4/plugins
PLIST_SUB+=	DESIGNER_PLUGIN=""
.else
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.endif

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS})

post-configure:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
