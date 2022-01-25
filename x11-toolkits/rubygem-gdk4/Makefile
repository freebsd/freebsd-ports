PORTNAME=	gdk4
PORTVERSION=	3.5.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GDK 4.x

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango

USES=		gem gnome pkgconfig
USE_GNOME=	gtk40
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
