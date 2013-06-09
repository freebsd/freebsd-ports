# $FreeBSD$

PORTNAME=	gtksourceview3
PORTVERSION=	2.0.2
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GtkSourceView3 is a Ruby binding of gtksourceview-3.x

RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3 \
		gtksourceview3>=0:${PORTSDIR}/x11-toolkits/gtksourceview3

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
