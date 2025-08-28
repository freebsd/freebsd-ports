PORTNAME=	lxqt-globalkeys
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Global keyboard shortcuts registration
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang kde:6 xorg lxqt:2 perl5 pkgconfig qt:6 \
		tar:xz gnome
USE_PERL5=	build
USE_QT=		base:run tools:build
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2 lxqt

.include <bsd.port.mk>
