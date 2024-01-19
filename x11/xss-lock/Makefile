PORTNAME=	xss-lock
DISTVERSION=	0.3.0-g20140302
CATEGORIES=	x11
MASTER_SITES=	https://bitbucket.org/raymonad/xss-lock/get/
DISTNAME=	${BB_TAGNAME}	# commit hash: no embedded ${PORTNAME}
DIST_SUBDIR=	${PORTNAME}	# and that's why we need ${DIST_SUBDIR}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Use external locker as X11 screen saver
WWW=		https://bitbucket.org/raymonad/xss-lock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		cmake gnome pkgconfig tar:bzip2 xorg
USE_GNOME=	glib20
USE_XORG=	xcb

BB_TAGNAME=	1e158fb20108
WRKSRC=		${WRKDIR}/raymonad-${PORTNAME}-${BB_TAGNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
