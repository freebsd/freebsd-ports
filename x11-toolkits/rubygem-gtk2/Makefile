# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.0.2
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GTK+2

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:${PORTSDIR}/accessibility/rubygem-atk \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-pango

USE_GNOME=	gtk20
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
