PORTNAME=	gtk4
PORTVERSION=	4.0.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GTK+ 4.x
WWW=		https://ruby-gnome.github.io/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:accessibility/rubygem-atk \
		rubygem-gdk4>=${PORTVERSION}:x11-toolkits/rubygem-gdk4

USES=		gem gnome
USE_GNOME=	gtk40
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
