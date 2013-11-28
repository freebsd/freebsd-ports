# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.0
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	6-designerplugin

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Designer plugin for Qwt

LIB_DEPENDS=	libqwt6.so:${PORTSDIR}/x11-toolkits/qwt6

USES=		gmake qmake
USE_QT4=	designer moc_build rcc_build
USE_BZIP2=	yes
QMAKE_ARGS+=	CONFIG+=QwtDesigner \
		PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}

PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt6_designer_plugin.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/designer \
		${QT_PLUGINDIR_REL}

STRIP_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt6_designer_plugin.so

CONFIGURE_WRKSRC=	${WRKSRC}/designer
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
