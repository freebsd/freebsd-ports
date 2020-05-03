# $FreeBSD$

PORTNAME=	gtksourceview3
PORTVERSION=	3.4.2
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby/GtkSourceView3 is a Ruby binding of gtksourceview-3.x

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

USES=		gem gnome
USE_GNOME=	gtksourceview3
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
