# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USE_QT4=	gui opengl svg xml moc_build qmake_build
USE_BZIP2=	yes
USE_GMAKE=	yes
QMAKE_ARGS+=	-recursive PREFIX=${PREFIX}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

LATEST_LINK=	qwt6

PORTDOCS=	*
PLIST_SUB=	INCLUDEDIR=include/${LATEST_LINK} \
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

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS})

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
