# New ports collection makefile for:	xfdesktop
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-desktop
PORTVERSION=	4.8.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/xfdesktop/${PORTVERSION:R}
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 desktop background manager and root menu

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv garcon libgui libmenu libutil panel xfconf \
		libexo

OPTIONS=	FAM	"Enable FAM support"		on \
		THUNAR	"Enable thunar support"		on

MAN1=		xfdesktop.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_THUNAR)
CONFIGURE_ARGS+=--enable-thunar-vfs --enable-thunarx
USE_XFCE+=	thunar
.else
CONFIGURE_ARGS+=--disable-thunar-vfs --disable-thunarx
.endif

.include <bsd.port.post.mk>
