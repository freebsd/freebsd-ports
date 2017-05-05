# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vte3
PORTVERSION=	3.1.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for VTE

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

NO_ARCH=	yes
USE_GNOME=	vte3
USE_RUBY=	yes
USES=		gem gnome

.include <bsd.port.mk>
