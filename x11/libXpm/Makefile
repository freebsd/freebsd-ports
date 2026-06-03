PORTNAME=	libXpm
DISTVERSION=	3.5.19
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Pixmap (XPM) image file format library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxpm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe localbase:ldflags tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto x11 xext xt

CPE_VENDOR=	libxpm_project

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENV_OFF=	ac_cv_search_gettext=no

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
