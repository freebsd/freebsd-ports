# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gtksourceview/Makefile,v 1.24 2010/04/19 11:30:28 kwm Exp $

PORTNAME=	gtksourceview
PORTVERSION=	2.10.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome python
MASTER_SITES=	GNOME/sources/pygtksourceview/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtksourceview-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GtkSourceView 2

USES=		gmake libtool:keepla pathfix pkgconfig python:2.7 tar:bzip2
USE_GNOME=	gnomeprefix gtksourceview2 pygtk2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
