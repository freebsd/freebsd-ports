# New ports collection makefile for:	xfce4-conf
# Date created:		28 August 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-conf
PORTVERSION=	4.6.0
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfconf-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 configuration mananger

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnometarget gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil

OPTIONS=	GTKDOC	"install the library documentation"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
.else
CONFIGURE_ARGS+=--disable-gtk-doc
.endif

.include <bsd.port.post.mk>
