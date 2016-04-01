# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-fusion
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Metaport of compiz-fusion

LIB_DEPENDS=	libcompizconfig.so:x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:x11-wm/ccsm

USES=		metaport

OPTIONS_DEFINE=	EXTRA UNSUP EMERALD GCONF
OPTIONS_DEFAULT=	GCONF EXTRA EMERALD

EXTRA_DESC=	Enable extra plugins
UNSUP_DESC=	Enable unsupported plugins
EMERALD_DESC=	Enable emerald window decorator

EXTRA_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libaddhelper.so:x11-wm/compiz-plugins-extra
UNSUP_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libfakeargb.so:x11-wm/compiz-plugins-unsupported
EMERALD_RUN_DEPENDS=	${LOCALBASE}/bin/emerald:x11-wm/emerald \
		${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:x11-themes/emerald-themes

GCONF_RUN_DEPENDS=	${LOCALBASE}/lib/compizconfig/backends/libgconf.so:x11-wm/compizconfig-backend-gconf

.include <bsd.port.mk>
