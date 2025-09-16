PORTNAME=	coreterminal
DISTVERSION=	5.0.0
CATEGORIES=	x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Terminal emulator from the CoreApps family
WWW=		https://gitlab.com/cubocore/coreterminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtermwidget6.so:x11-toolkits/qtermwidget \
		libcprime-widgets.so:deskutils/libcprime
RUN_DEPENDS=	coregarage:deskutils/coregarage

USES=		cmake desktop-file-utils gl localbase:ldflags qt:6
USE_GL=		gl
USE_QT=		base serialport tools:build
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	v5.0.0

PLIST_FILES=	bin/coreterminal \
		share/applications/cc.cubocore.CoreTerminal.desktop \
		share/icons/hicolor/scalable/apps/cc.cubocore.CoreTerminal.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/coreterminal|${PREFIX}/bin/coreterminal|g' \
		${WRKSRC}/cc.cubocore.CoreTerminal.desktop

.include <bsd.port.mk>
