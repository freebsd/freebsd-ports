# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-fusion
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Metaport of compiz-fusion

LIB_DEPENDS=	compizconfig:${PORTSDIR}/x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:${PORTSDIR}/x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:${PORTSDIR}/x11-wm/ccsm

NO_BUILD=	yes

OPTIONS_DEFINE=	EXTRA UNSUP EMERALD GCONF
OPTIONS_DEFAULT=	GCONF EXTRA EMERALD

EXTRA_DESC=	Enable extra plugins
UNSUP_DESC=	Enable unsupported plugins
EMERALD_DESC=	Enable emerald window decorator

do-install:	# empty

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXTRA}
RUN_DEPENDS+=	${LOCALBASE}/lib/compiz/libaddhelper.so:${PORTSDIR}/x11-wm/compiz-plugins-extra
.endif

.if ${PORT_OPTIONS:MUNSUP}
RUN_DEPENDS+=	${LOCALBASE}/lib/compiz/libfakeargb.so:${PORTSDIR}/x11-wm/compiz-plugins-unsupported
.endif

.if ${PORT_OPTIONS:MEMERALD}
RUN_DEPENDS+=	${LOCALBASE}/bin/emerald:${PORTSDIR}/x11-wm/emerald \
		${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:${PORTSDIR}/x11-themes/emerald-themes
.endif

.if ${PORT_OPTIONS:MGCONF}
RUN_DEPENDS+=	${LOCALBASE}/lib/compizconfig/backends/libgconf.so:${PORTSDIR}/x11-wm/compizconfig-backend-gconf
.endif

.include <bsd.port.mk>
