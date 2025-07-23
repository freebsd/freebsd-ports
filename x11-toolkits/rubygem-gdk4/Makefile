PORTNAME=	gdk4
PORTVERSION=	4.3.0
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GDK 4
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-pango

USES=		gem gnome pkgconfig
USE_GNOME=	gtk40

NO_ARCH=	yes

.include <bsd.port.mk>
