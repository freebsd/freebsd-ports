# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-fusion
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	x11-wm

MAINTAINER=	samy.mahmoudi@gmail.com
COMMENT=	Metaport of compiz-fusion

LICENSE=	GPLv2+ LGPL21+ MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libcompizconfig.so:x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:x11-wm/ccsm

USES=		gnome metaport xorg
USE_GNOME=	libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xrandr

OPTIONS_DEFINE=		EMERALD EXTRA GCONF UNSUP
OPTIONS_DEFAULT=	EMERALD EXTRA GCONF

EMERALD_DESC=	Enable emerald window decorator
EXTRA_DESC=	Enable extra plugins
UNSUP_DESC=	Enable unsupported plugins

EMERALD_RUN_DEPENDS=	${LOCALBASE}/bin/emerald:x11-wm/emerald \
			${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:x11-themes/emerald-themes

EXTRA_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libaddhelper.so:x11-wm/compiz-plugins-extra

GCONF_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
GCONF_RUN_DEPENDS=	${LOCALBASE}/lib/compizconfig/backends/libgconf.so:x11-wm/compizconfig-backend-gconf

UNSUP_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libfakeargb.so:x11-wm/compiz-plugins-unsupported

.include <bsd.port.mk>
