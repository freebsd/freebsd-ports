PORTNAME=	qtermwidget
PORTVERSION=	2.3.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Terminal widget for QTerminal
WWW=		https://github.com/lxde/qtermwidget

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang gettext-runtime lxqt:2 \
		pkgconfig qt:6 tar:xz
USE_LDCONFIG=	yes
USE_QT=		base:run tools:build
USE_LXQT=	buildtools2

CMAKE_ARGS+=	-DQTERMWIDGET_USE_UTEMPTER=ON

.include <bsd.port.mk>
