PORTNAME=	vte3
PORTVERSION=	4.3.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of VTE for GTK 3
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-gtk3 \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem gnome
USE_GNOME=	vte3

NO_ARCH=	yes

.include <bsd.port.mk>
