# $FreeBSD$

PORTNAME=	gtk3
PORTVERSION=	3.2.1
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GTK+3

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:accessibility/rubygem-atk \
		rubygem-gdk3>=${PORTVERSION}:x11-toolkits/rubygem-gdk3 \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gio2>=${PORTVERSION}:devel/rubygem-gio2 \
		rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2 \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango

USE_GNOME=	gtk30
USE_RUBY=	yes
USES=		gem gnome

.include <bsd.port.mk>
