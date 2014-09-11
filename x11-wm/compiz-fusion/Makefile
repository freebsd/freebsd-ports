# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-fusion
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Metaport of compiz-fusion

LIB_DEPENDS=	libcompizconfig.so:${PORTSDIR}/x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:${PORTSDIR}/x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:${PORTSDIR}/x11-wm/ccsm

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	EXTRA UNSUP EMERALD GCONF
OPTIONS_DEFAULT=	GCONF EXTRA EMERALD

EXTRA_DESC=	Enable extra plugins
UNSUP_DESC=	Enable unsupported plugins
EMERALD_DESC=	Enable emerald window decorator

EXTRA_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libaddhelper.so:${PORTSDIR}/x11-wm/compiz-plugins-extra
UNSUP_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libfakeargb.so:${PORTSDIR}/x11-wm/compiz-plugins-unsupported
EMERALD_RUN_DEPENDS=	${LOCALBASE}/bin/emerald:${PORTSDIR}/x11-wm/emerald \
		${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:${PORTSDIR}/x11-themes/emerald-themes

GCONF_RUN_DEPENDS=	${LOCALBASE}/lib/compizconfig/backends/libgconf.so:${PORTSDIR}/x11-wm/compizconfig-backend-gconf

.include <bsd.port.mk>
