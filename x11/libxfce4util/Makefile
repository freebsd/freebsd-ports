# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4util
PORTVERSION=	4.6.1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 library with non-graphical helper functions

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
PLIST_SUB+=	GTK_DOC=""
.else
CONFIGURE_ARGS+=--disable-gtk-doc
PLIST_SUB+=	GTK_DOC="@comment "
.endif

.include <bsd.port.mk>
