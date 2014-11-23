# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rep-gtk2
PORTVERSION=	0.90.8.2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/
DISTNAME=	rep-gtk_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-2 bindings for rep Lisp interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	librep.so:${PORTSDIR}/lang/librep

USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

PLIST_FILES=	include/rep-gtk/rep-gtk.h lib/rep/gui/gtk-2/gtk.a \
		lib/rep/gui/gtk-2/gtk.so libdata/pkgconfig/rep-gtk.pc

.include <bsd.port.mk>
