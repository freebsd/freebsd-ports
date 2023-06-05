PORTNAME=	gtksourceview4
PORTVERSION=	4.1.7
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of gtksourceview 4.x
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-gtk3

USES=		gem gnome
USE_GNOME=	gtksourceview4

NO_ARCH=	yes

.include <bsd.port.mk>
