PORTNAME=	coreterminal
DISTVERSION=	4.5.0
CATEGORIES=	x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal emulator from the CoreApps family
WWW=		https://gitlab.com/cubocore/coreterminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget-qt5 \
		libcprime-core.so:deskutils/libcprime
RUN_DEPENDS=	coregarage:deskutils/coregarage

USES=		cmake desktop-file-utils localbase:ldflags qt:5
USE_QT=		buildtools:build core gui qmake:build serialport widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	a04d47537f2d01d1742d11dd4d28adc401a19a0c

PLIST_FILES=	bin/coreterminal \
		share/applications/org.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreTerminal.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreterminal|${PREFIX}/bin/coreterminal|g' \
		${WRKSRC}/org.cubocore.CoreTerminal.desktop

.include <bsd.port.mk>
