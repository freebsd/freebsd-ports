# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-fifth-toe
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric2 \
		pan:${PORTSDIR}/news/pan2 \
		xchat:${PORTSDIR}/irc/xchat2 \
		balsa:${PORTSDIR}/mail/balsa2 \
		gimp-1.3:${PORTSDIR}/graphics/gimp-devel \
		gnomeicu:${PORTSDIR}/net/gnomeicu2 \
		ggv:${PORTSDIR}/print/ggv2 \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gthumb:${PORTSDIR}/graphics/gthumb2 \
		${X11BASE}/lib/gtk-2.0/2.0.0/engines/libcrux-engine.so:${PORTSDIR}/x11-toolkits/crux \
		mergeant:${PORTSDIR}/databases/mergeant \
		ghex2:${PORTSDIR}/editors/ghex2

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
