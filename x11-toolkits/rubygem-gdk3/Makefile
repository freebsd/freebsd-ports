# $FreeBSD$

PORTNAME=	gdk3
PORTVERSION=	2.2.5
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GDK3 is a Ruby binding of GDK-3.x

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-gdk_pixbuf2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-pango

USE_GNOME=	gtk30
NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
