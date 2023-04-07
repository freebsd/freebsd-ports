PORTNAME=	compton-conf
PORTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Controls compton settings
WWW=		https://github.com/lxqt/compton-conf

LICENSE=	LGPL21+

LIB_DEPENDS=	libconfig.so:devel/libconfig
RUN_DEPENDS=	compton:x11-wm/compton

USES=	cmake compiler:c++14-lang localbase:ldflags lxqt perl5 qt:5 \
	pkgconfig tar:xz
USE_PERL5=	build
USE_QT=	buildtools:build qmake:build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools

.include <bsd.port.mk>
