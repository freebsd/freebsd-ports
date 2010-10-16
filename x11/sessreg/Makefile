# New ports collection makefile for:	sessreg
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sessreg
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Manage utmp/wtmp entries for non-init X clients

BUILD_DEPENDS+=	${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros

XORG_CAT=	app
USE_XORG=	x11

USE_AUTOTOOLS=	aclocal:111 autoheader:268 automake:111 autoconf:268
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal

PLIST_FILES=	bin/sessreg

MAN1=		sessreg.1

.include <bsd.port.mk>
