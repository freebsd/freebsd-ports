# New ports collection makefile for:	compiz-fusion
# Date created:				2007-10-22
# Whom:					Robert C. Noland III <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-fusion
PORTVERSION=	0.8.4
CATEGORIES=	x11-wm
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Metaport of compiz-fusion

LIB_DEPENDS=	compizconfig:${PORTSDIR}/x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:${PORTSDIR}/x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:${PORTSDIR}/x11-wm/ccsm

NO_BUILD=	yes

OPTIONS=	EXTRA "Enable extra plugins" on \
		UNSUP "Enable unsupported plugins" off \
		EMERALD "Enable emerald window decorator" on \
		GCONF "Enable the gconf backend" on
# Hold off on this until I can get a clean tb run...
#		KCONFIG "Enable kconfig backend" off

do-install:	# empty

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXTRA)
RUN_DEPENDS+=	${LOCALBASE}/lib/compiz/libaddhelper.so:${PORTSDIR}/x11-wm/compiz-plugins-extra
.endif

.if defined(WITH_UNSUP)
RUN_DEPENDS+=	${LOCALBASE}/lib/compiz/libfakeargb.so:${PORTSDIR}/x11-wm/compiz-plugins-unsupported
.endif

.if !defined(WITHOUT_EMERALD)
RUN_DEPENDS+=	${LOCALBASE}/bin/emerald:${PORTSDIR}/x11-wm/emerald \
		${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:${PORTSDIR}/x11-themes/emerald-themes
.endif

.if !defined(WITHOUT_GCONF)
RUN_DEPENDS+=	${LOCALBASE}/lib/compizconfig/backends/libgconf.so:${PORTSDIR}/x11-wm/compizconfig-backend-gconf
.endif

#.if defined(WITH_KCONFIG)
#RUN_DEPENDS+=	${LOCALBASE}/lib/compizconfig/backends/libkconfig.so:${PORTSDIR}/x11-wm/compizconfig-backend-kconfig
#.endif

.include <bsd.port.post.mk>
