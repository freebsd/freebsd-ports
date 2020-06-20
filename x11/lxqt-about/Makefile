# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-about
PORTVERSION=	0.15.0
CATEGORIES=	x11
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	About dialog of LXQt

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 lxqt pkgconfig tar:xz qt:5 gnome
USE_QT=		buildtools_build qmake_build core dbus gui svg widgets \
		x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt

.include <bsd.port.mk>
