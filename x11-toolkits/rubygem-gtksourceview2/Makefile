# $FreeBSD$

PORTNAME=	gtksourceview2
PORTVERSION=	3.4.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for gtksourceview-2.x

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-gtk2>=${PORTVERSION}:x11-toolkits/rubygem-gtk2

USES=		gem gnome
USE_GNOME=	gtksourceview2
USE_RUBY=	yes

.include <bsd.port.mk>
