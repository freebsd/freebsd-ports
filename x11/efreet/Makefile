# New ports collection makefile for:	efreet
# Date created:				28 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	efreet
DISTVERSION=	1.0.1
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freedesktop.org EFL compatiblity layer

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eet eina ecore libtool_hack librt_hack
USE_EFL_ECORE=	file
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
