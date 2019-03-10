# $FreeBSD$

PORTNAME=	gtk3
PORTVERSION=	3.3.3
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GTK+3

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:accessibility/rubygem-atk \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gdk3>=${PORTVERSION}:x11-toolkits/rubygem-gdk3 \
		rubygem-gio2>=${PORTVERSION}:devel/rubygem-gio2 \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango

USES=		gem gnome
USE_GNOME=	gtk30
USE_RUBY=	yes

.include <bsd.port.mk>
