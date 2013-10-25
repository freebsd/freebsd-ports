# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efreet
PORTVERSION=	1.7.8
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Freedesktop.org EFL compatibility layer

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_EFL=	eet eina ecore libtool_hack librt_hack
USE_EFL_ECORE=	file
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-nls

.include <bsd.port.mk>
