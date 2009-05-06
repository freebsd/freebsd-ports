# New ports collection makefile for:	verve plugin for xfce4
# Date created:				11 September 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	verve-plugin
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-verve-plugin/
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A command line plugin for xfce4

RUN_DEPENDES=	dbus-daemon:${PORTSDIR}/devel/dbus
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel libexo libutil

.include <bsd.port.mk>
