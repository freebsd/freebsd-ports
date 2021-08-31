PORTNAME=	coreterminal
DISTVERSION=	4.3.0
CATEGORIES=	x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal emulator from the CoreApps family

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget \
		libcprime-core.so:deskutils/libcprime
RUN_DEPENDS=	coregarage:deskutils/coregarage

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	c61e5f8e0941dee2ab8920f2470fe93d21d717a2

PLIST_FILES=	bin/coreterminal \
		share/applications/org.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreTerminal.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreterminal|${PREFIX}/bin/coreterminal|g' \
		${WRKSRC}/org.cubocore.CoreTerminal.desktop

.include <bsd.port.mk>
