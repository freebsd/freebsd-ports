# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	3.1.0
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Pango

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-cairo>=1.14.0:graphics/rubygem-cairo \
		rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2

USE_GNOME=	pango
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
