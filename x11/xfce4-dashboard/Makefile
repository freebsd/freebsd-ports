PORTNAME=	dashboard
PORTVERSION=	1.1.0
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
		libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gettext-tools gl gnome meson pathfix perl5 \
		pkgconfig tar:xz xfce xorg
USE_GL=		egl
USE_GNOME=	glib20 gtk30 libwnck3
USE_LDCONFIG=	yes
USE_XFCE=	garcon xfconf
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xinerama xrandr

MESON_ARGS=	-Dclutter-gdk=enabled \
		-Dxcomposite=enabled \
		-Dxdamage=enabled \
		-Dxinerama=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
