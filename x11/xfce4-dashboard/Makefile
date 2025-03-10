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

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gettext-tools gl gmake gnome libtool localbase \
		pathfix perl5 pkgconfig tar:bzip2 xfce xorg
USE_GL=		egl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libwnck3
USE_LDCONFIG=	yes
USE_XFCE=	garcon xfconf
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xinerama xrandr

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
