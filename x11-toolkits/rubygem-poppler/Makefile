# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Poppler

LICENSE=	LGPL21+

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
RUN_DEPENDS=	rubygem-cairo>=1.14.0:${PORTSDIR}/graphics/rubygem-cairo \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
