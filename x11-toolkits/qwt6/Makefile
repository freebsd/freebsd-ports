# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	6

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USES=		gmake qmake
USE_QT4=	gui opengl svg xml moc_build
USE_BZIP2=	yes
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/qwt6

PORTDOCS=	*
PLIST_SUB=	INCLUDEDIR=include/qwt6 \
		SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R} \
		QT_MKSPECDIR=share/qt4/mkspecs

STRIP_FILES=	lib/libqwt6.so.${PORTVERSION} \
		lib/libqwtmathml.so.${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's,qwtAddLibrary(qwt),qwtAddLibrary(qwt6),g' \
		qwt.prf textengines/textengines.pri && \
	${REINPLACE_CMD} -e '/INSTALLS.*doc/d' doc/doc.pro

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
