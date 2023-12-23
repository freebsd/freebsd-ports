PORTNAME=	dashboard
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
PKGNAMEPREFIX=	xfce4-
DISTNAME=	xfdashboard-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GNOME shell like dashboard for the Xfce desktop
WWW=		https://docs.xfce.org/apps/xfdashboard/start

LICENSE=	GPLv2

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gl gmake gnome localbase libtool \
		pathfix perl5 pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libwnck3
USE_XFCE=	garcon xfconf
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xinerama xrandr
USE_GL=		egl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

.include <bsd.port.mk>
