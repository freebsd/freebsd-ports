# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.0
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	-designerplugin

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Designer plugin for Qwt

LIB_DEPENDS=	qwt6.6:${PORTSDIR}/x11-toolkits/qwt6

USE_QT4=	designer moc_build qmake_build rcc_build
USE_BZIP2=	yes
USE_GMAKE=	yes
QMAKE_ARGS+=	-recursive CONFIG+=QwtDesigner \
		PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

LATEST_LINK=	qwt6${PKGNAMESUFFIX}

PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt6_designer_plugin.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/designer \
		${QT_PLUGINDIR_REL}

STRIP_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt6_designer_plugin.so

CONFIGURE_WRKSRC=	${WRKSRC}/designer
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

do-configure:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS})

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
