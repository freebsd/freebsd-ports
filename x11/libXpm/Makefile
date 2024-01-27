PORTNAME=	libXpm
PORTVERSION=	3.5.17
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Pixmap library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto x11 xext xt
LDFLAGS+=	-L${LOCALBASE}/lib

CPE_VENDOR=	libxpm_project

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENV_OFF=	ac_cv_search_gettext=no

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
