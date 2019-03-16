# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	6-qt5

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Qt Widgets for Technical Applications

USES=		compiler:c++11-lang gl gmake qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build widgets gui core designer gui opengl svg xml printsupport concurrent
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

DOCSDIR=	${PREFIX}/share/doc/qwt6-qt5
PORTDOCS=	*
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R}

QMAKE_ARGS+=	PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}

PLIST_FILES=	${PREFIX}/${QT_PLUGINDIR_REL}/designer/libqwt6_designer_plugin.so

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLS.*doc/d' ${WRKSRC}/doc/doc.pro
	@${REINPLACE_CMD} -e 's/%%QT_VERSION%%/5/g' \
			-e 's|%%QT_INCDIR%%|${QT_INCDIR}|g' \
			-e 's|%%QT_LIBDIR%%|${QT_LIBDIR}|g' \
			-e 's|%%QT_MKSPECDIR%%|${QT_MKSPECDIR}|g' \
			${WRKSRC}/qwtconfig.pri

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
