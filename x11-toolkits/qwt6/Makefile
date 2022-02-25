PORTNAME=	qwt
PORTVERSION=	6.2.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	6-${FLAVOR}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications
WWW=		http://qwt.sourceforge.net/

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		compiler:c++11-lang gl gmake qmake qt:${FLAVOR:S/qt//} tar:bzip2
USE_GL=		gl
_USE_QT_qt5=	concurrent core designer dbus gui opengl printsupport svg xml widgets buildtools:build qmake:build
_USE_QT_qt6=	base svg tools
USE_QT=		${_USE_QT_${FLAVOR}}
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

DOCSDIR=	${PREFIX}/share/doc/qwt6-${FLAVOR}
PORTDOCS=	*
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R} \
		FLAVOR=${FLAVOR:S/qt/Qt/}

QMAKE_ARGS+=	PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLS.*doc/d' ${WRKSRC}/doc/doc.pro
	@${REINPLACE_CMD} \
			-e 's|%%QT_INCDIR%%|${QT_INCDIR}|g' \
			-e 's|%%QT_LIBDIR%%|${QT_LIBDIR}|g' \
			-e 's|%%QT_MKSPECDIR%%|${QT_MKSPECDIR}|g' \
			${WRKSRC}/qwtconfig.pri

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
