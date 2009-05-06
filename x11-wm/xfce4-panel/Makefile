# New ports collection makefile for:	xfce4-panel
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-panel
PORTVERSION=	4.6.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 panel module

LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck

CONFLICTS=	xfce4-systray-*
GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libgui libutil

OPTIONS=	GTKDOC	"install the library documentation"	off \
		STARTUP "Enable startup notification support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
PLIST_SUB+=	GTK_DOC=""
.else
CONFIGURE_ARGS+=--disable-gtk-doc
PLIST_SUB+=	GTK_DOC="@comment "
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.include <bsd.port.post.mk>
