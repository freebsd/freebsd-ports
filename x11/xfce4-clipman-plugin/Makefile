# New ports collection makefile for:	xfce4-clipman-plugin
# Date created:		23 November 2003
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.1.3
PORTREVISION=	4
CATEGORIES=	x11 xfce
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/${PORTNAME}/1.1/
DIST_SUBDIR=	xfce4

MAINTAINER=	rene@FreeBSD.org
COMMENT=	XFce 4 clipboard module for xfce4-panel

OPTIONS=	UNIQUE	"Enable Unique (single instance) support" on

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil panel
USE_XORG=	x11 ice sm xpm

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_UNIQUE)
LIB_DEPENDS+=	unique-1:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=	--enable-unique
.else
CONFIGURE_ARGS+=	--disable-unique
.endif

.include <bsd.port.post.mk>
