# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	5.2.3
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	5-designerplugin

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Designer plugin for Qwt

LIB_DEPENDS=	libqwt.so:${PORTSDIR}/x11-toolkits/qwt5

USES=		gmake qmake
USE_QT4=	designer moc_build rcc_build
USE_BZIP2=	yes
QMAKE_ARGS+=	CONFIG+=QwtDesigner \
		PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}
PORTSCOUT=	limit:^5\.

STRIP_FILES=	${QT_PLUGINDIR_REL}/designer/libqwt_designer_plugin.so

CONFIGURE_WRKSRC=	${WRKSRC}/designer
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
