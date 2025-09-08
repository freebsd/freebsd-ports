PORTNAME=	gdk3
PORTVERSION=	4.3.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GDK 3
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-pango \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem gnome
USE_GNOME=	gtk30

NO_ARCH=	yes

.include <bsd.port.mk>
