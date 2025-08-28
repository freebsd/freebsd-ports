PORTNAME=	lxqt-about
PORTVERSION= 	2.2.0
PORTREVISION=	3
CATEGORIES=	x11
DIST_SUBDIR=	lxqt

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	About dialog of LXQt
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++20-lang kde:6 lxqt:2 perl5 pkgconfig tar:xz qt:6 gnome xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_XORG=	x11
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools2 lxqt

.include <bsd.port.mk>
