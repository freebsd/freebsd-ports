# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	5.2.3
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	-designerplugin

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Designer plugin for Qwt

LIB_DEPENDS=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_QT4=	designer moc_build qmake_build rcc_build
USE_BZIP2=	yes
USE_GMAKE=	yes
QMAKE_ARGS+=	-recursive CONFIG+=QwtDesigner \
		PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}
HAS_CONFIGURE=	yes
PORTSCOUT=	limit:^5\.

STRIP_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt_designer_plugin.so

CONFIGURE_WRKSRC=	${WRKSRC}/designer
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

NO_STAGE=	yes
do-configure:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS})

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
