# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e17-modules
PORTVERSION=	20130510
PORTREVISION=	1
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Meta-port for e17 modules

NO_BUILD=	yes
WANT_EFL=	yes
E17_ARCH=	${OPSYS:tl}${OSREL}-${ARCH}

MODULES=	alarm comp-scale cpu deskshow diskio eektool elfe empris engage eooorg \
		everything-aspell everything-mpris everything-pidgin everything-places \
		everything-shotgun everything-wallpaper everything-websearch exebuf execwatch \
		flame forecasts iiirk itask mail mem moon mpdule net news \
		penguins photo places rain rmb screenshot slideshow snow \
		taskbar tclock uptime weather winlist-ng winselector wlan

COMP_SCALE_PATH=	scale
EVERYTHING_MPRIS_PATH=	evry-mpris
EVERYTHING_PIDGIN_PATH=	evry-pidgin
EVERYTHING_SHOTGUN_PATH=	evry-shotgun
EVERYTHING_WEBSEARCH_PATH=	evry-websearch

.for M in ${MODULES}
OPTIONS_DEFINE+=	${M:tu:S,-,_,g}
OPTIONS_DEFAULT+=	${M:tu:S,-,_,g}
${M:tu:S,-,_,g}_DESC=	Install ${M} module
.endfor

.include <bsd.port.options.mk>

.for M in ${MODULES}
. if !defined(${M:tu:S,-,_,g}_PATH)
${M:tu:S,-,_,g}_PATH=	${M}
. endif
. if ${PORT_OPTIONS:M${M:tu:S,-,_,g}}
RUN_DEPENDS+=	${LOCALBASE}/lib/enlightenment/modules/${${M:tu:S,-,_,g}_PATH}/${E17_ARCH}/module.so:${PORTSDIR}/x11-wm/e17-module-${M}
. endif
.endfor

do-install:	# empty

.include <bsd.port.mk>
