# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	3.2.5
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Poppler

LICENSE=	LGPL21+

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gio2>=${PORTVERSION}:devel/rubygem-gio2

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
