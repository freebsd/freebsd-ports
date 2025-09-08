PORTNAME=	pango
PORTVERSION=	4.3.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of Pango 1.x
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-cairo-gobject \
		rubygem-gobject-introspection>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-gobject-introspection

USES=		gem gnome
USE_GNOME=	pango

.include <bsd.port.mk>
