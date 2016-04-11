# $FreeBSD$

PORTNAME=	gdk3
PORTVERSION=	3.0.8
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GDK3 is a Ruby binding of GDK-3.x

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango

NO_ARCH=	yes
USE_GNOME=	gtk30
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
