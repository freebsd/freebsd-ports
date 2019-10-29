# $FreeBSD$

PORTNAME=	vte
PORTVERSION=	3.4.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for VTE

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-gtk2>=${PORTVERSION}:x11-toolkits/rubygem-gtk2

USES=		gem gnome
USE_GNOME=	vte
USE_RUBY=	yes

.include <bsd.port.mk>
