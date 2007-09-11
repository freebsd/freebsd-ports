# New ports collection makefile for:	verve plugin for xfce4
# Date created:				11 September 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	verve-plugin
PORTVERSION=	0.3.5
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	xfce4-
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A command line plugin for xfce4

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel libexo libutil
USE_XLIB=	yes

RUN_DEPENDES=	dbus-daemon:${PORTSDIR}/devel/dbus
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

.include <bsd.port.mk>
