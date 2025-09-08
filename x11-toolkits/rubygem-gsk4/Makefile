PORTNAME=	gsk4
PORTVERSION=	4.3.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GSK 4
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-gdk4>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-gdk4 \
		rubygem-graphene1>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-graphene1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
