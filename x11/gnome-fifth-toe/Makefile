# New ports collection makefile for:	gnome
# Date created:				18th April 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-fifth-toe
PORTVERSION=	1.4.1b2
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	gabber:${PORTSDIR}/net/gabber \
		galeon:${PORTSDIR}/www/galeon \
		pan:${PORTSDIR}/news/pan \
		gnumeric:${PORTSDIR}/math/gnumeric \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		atomix:${PORTSDIR}/games/atomix \
		balsa:${PORTSDIR}/mail/balsa \
		bombermaze:${PORTSDIR}/games/bombermaze \
		dia:${PORTSDIR}/graphics/dia \
		eog:${PORTSDIR}/graphics/eog \
		gedit:${PORTSDIR}/editors/gedit \
		gimp:${PORTSDIR}/graphics/gimp1 \
		glimmer:${PORTSDIR}/editors/glimmer \
		gnomeicu:${PORTSDIR}/net/gnomeicu \
		gob:${PORTSDIR}/x11-toolkits/gob \
		gtm:${PORTSDIR}/ftp/gtm \
		gnucash:${PORTSDIR}/deskutils/gnucash \
		AbiWord:${PORTSDIR}/editors/AbiWord \
		anjuta:${PORTSDIR}/devel/anjuta \
		guppi-gnumeric:${PORTSDIR}/math/guppi \
		gnomoku:${PORTSDIR}/games/gnomoku \
		evolution:${PORTSDIR}/mail/evolution \
		gfax:${PORTSDIR}/comms/gfax

# We're still missing a few things from the "official" distribution
# All can be found in stable/sources on MASTER_SITE_GNOME
#
# firestarter, fpm, gfax, gnome-db, gnome-lokkit,
# gnorpm, googlizer, merlin-cpufire, radioactive, toutdoux

NO_BUILD=	yes
USE_PYTHON=	yes

.if !defined(WITH_MOZILLA)
RUN_DEPENDS+=	${X11BASE}/lib/mozilla/run-mozilla.sh:${PORTSDIR}/www/mozilla
.else
.if ${WITH_MOZILLA}=="mozilla-vendor" || ${WITH_MOZILLA}=="mozilla-devel"
RUN_DEPENDS+=	${X11BASE}/lib/${WITH_MOZILLA}/run-mozilla.sh:${PORTSDIR}/www/${WITH_MOZILLA}
.else
RUN_DEPENDS+=	${X11BASE}/lib/mozilla/run-mozilla.sh:${PORTSDIR}/www/mozilla
.endif
.endif

do-install:	# empty

.include <bsd.port.mk>
