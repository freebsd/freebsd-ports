# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	3.4.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for Pango

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection

USES=		gem gnome
USE_GNOME=	pango
USE_RUBY=	yes

.include <bsd.port.mk>
