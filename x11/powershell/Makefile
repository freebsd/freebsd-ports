# Ports collection Makefile for:	powershell
# Date created:				6 May 2000
# Whom:					Scott A. Moberly <smoberly@xavier.dyndns.org>
#
# $FreeBSD$
#    $MCom: ports/x11/powershell/Makefile,v 1.1 2006/10/04 19:44:10 ahze Exp $

PORTNAME=	powershell
PORTVERSION=	0.8
PORTREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator for the X11

USE_GNOME=	gnomelibs gnomehier
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include  `${IMLIB_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib  `${IMLIB_CONFIG} --libs`"
ALL_TARGET=	${PORTNAME}

.include <bsd.port.mk>
