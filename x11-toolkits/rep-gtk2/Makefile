# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/rep-gtk2/Makefile,v 1.8 2006/07/18 16:50:28 ahze Exp $

PORTNAME=	rep-gtk2
PORTVERSION=	0.90.7
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/
DISTNAME=	rep-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-2 binding for rep Lisp interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	rep.16:${PORTSDIR}/lang/librep

USE_XZ=		yes
USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
