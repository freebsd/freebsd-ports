# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dashboard
PORTVERSION=	0.7.7
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
PKGNAMEPREFIX=	xfce4-
DISTNAME=	xfdashboard-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GNOME shell like dashboard for the Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter

USES=		compiler:c11 gettext-tools gl gmake gnome localbase libtool \
		pathfix perl5 pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool libwnck3
USE_XFCE=	garcon xfconf
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xinerama xrandr
USE_GL=		egl gl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

post-patch:
# Decrease default value of desaturation factor (0.0 -> no desaturation)
# With some graphics cards, quick launch icons are totally black with
# default value
	${FIND} ${WRKSRC}/data/themes -type f -name 'effects.xml' \
		| ${XARGS} ${REINPLACE_CMD} -i "" 's|factor">1.0|factor">0.25|'

.include <bsd.port.mk>
