# New ports collection makefile for:	quicklauncher plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (freebsd@unixfreunde.de)
#
# $FreeBSD$
#

PORTNAME=	xfce4-quicklauncher-plugin
PORTVERSION=	1.9.2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4
PATCH_SITES=	http://people.freebsd.org/~oliver/xfce/
PATCHFILES=	gcc295-xfce4-quicklauncher-plugin-2.patch

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Quicklauncher plugin for xfce

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
USE_XLIB=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11-wm/xfce4/bsd.xfce.mk"
.include <bsd.port.post.mk>
