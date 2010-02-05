# New ports collection makefile for:	py-gtksourceview
# Date created:				25 June 2007
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gtksourceview/Makefile,v 1.20 2009/09/22 08:25:11 kwm Exp $
#

PORTNAME=	gtksourceview
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygtksourceview/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtksourceview-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python bindings for the version 2 of the GtkSourceView library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtksourceview2 pygtk2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs

post-patch:
	@${REINPLACE_CMD} -e 's| == x| = x|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
