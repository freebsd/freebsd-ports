# New ports collection makefile for:	e17-modules
# Date created:				12 November 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	e17-modules
PORTVERSION=	20111128
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	magik@roorback.net
COMMENT=	Meta-port for e17 modules

NO_BUILD=	yes
WANT_EFL=	yes
E17_ARCH=	freebsd${OSREL}-${ARCH}

MODULES=	alarm calendar comp-scale cpu deskshow diskio drawer e-tiling elfe empris engage eooorg \
		everything-aspell everything-mpris everything-pidgin everything-places \
		everything-shotgun everything-wallpaper everything-websearch exebuf execwatch \
		flame forecasts iiirk itask language mail mem moon mpdule net news \
		penguins photo places quickaccess rain screenshot slideshow snow \
		taskbar tclock tiling uptime weather winlist-ng winselector wlan xkbswitch

COMP_SCALE_PATH=	scale
EVERYTHING_MPRIS_PATH=	evry-mpris
EVERYTHING_PIDGIN_PATH=	evry-pidgin
EVERYTHING_SHOTGUN_PATH=	evry-shotgun
EVERYTHING_WEBSEARCH_PATH=	evry-websearch

.for M in ${MODULES}
OPTIONS+=	${M:U:S,-,_,g} "Install ${M} module"
. if !defined(${M:U:S,-,_,g}_OFF)
OPTIONS+=	on
. else
OPTIONS+=	off
. endif
.endfor

.include <bsd.port.options.mk>

.for M in ${MODULES}
. if !defined(${M:U:S,-,_,g}_PATH)
${M:U:S,-,_,g}_PATH=	${M}
. endif
. if !defined(WITHOUT_${M:U:S,-,_,g})
RUN_DEPENDS+=	${LOCALBASE}/lib/enlightenment/modules/${${M:U:S,-,_,g}_PATH}/${E17_ARCH}/module.so:${PORTSDIR}/x11-wm/e17-module-${M}
. endif
.endfor

do-install:	# empty

.include <bsd.port.mk>
