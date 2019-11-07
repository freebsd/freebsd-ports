# $FreeBSD$

PORTNAME=	lxqt-globalkeys
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Global keyboard shortcuts registration

LICENSE=	LGPL21+

USES=		cmake compiler:c++14-lang kde:5 lxqt pkgconfig qt:5 tar:xz xorg
USE_QT=		buildtools_build qmake_build core dbus gui linguisttools \
		svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

.include <bsd.port.mk>
