# $FreeBSD$

PORTNAME=	gnome2
PORTVERSION=	3.2.5
CATEGORIES=	x11 gnome rubygems
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Meta port for all Ruby Gnome2 Gems

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:accessibility/rubygem-atk \
		rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-clutter>=${PORTVERSION}:graphics/rubygem-clutter \
		rubygem-clutter-gstreamer>=${PORTVERSION}:multimedia/rubygem-clutter-gstreamer \
		rubygem-clutter-gdk>=${PORTVERSION}:graphics/rubygem-clutter-gdk \
		rubygem-clutter-gtk>=${PORTVERSION}:graphics/rubygem-clutter-gtk \
		rubygem-gdk3>=${PORTVERSION}:x11-toolkits/rubygem-gdk3 \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gio2>=${PORTVERSION}:devel/rubygem-gio2 \
		rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2 \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-goocanvas>=2.2.0:graphics/rubygem-goocanvas \
		rubygem-gstreamer>=${PORTVERSION}:multimedia/rubygem-gstreamer \
		rubygem-gtk2>=${PORTVERSION}:x11-toolkits/rubygem-gtk2 \
		rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3 \
		rubygem-gtksourceview2>=${PORTVERSION}:x11-toolkits/rubygem-gtksourceview2 \
		rubygem-gtksourceview3>=${PORTVERSION}:x11-toolkits/rubygem-gtksourceview3 \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango \
		rubygem-poppler>=${PORTVERSION}:x11-toolkits/rubygem-poppler \
		rubygem-rsvg2>=${PORTVERSION}:graphics/rubygem-rsvg2 \
		rubygem-vte>=${PORTVERSION}:x11-toolkits/rubygem-vte \
		rubygem-vte3>=${PORTVERSION}:x11-toolkits/rubygem-vte3 \
		rubygem-webkit-gtk>=${PORTVERSION}:www/rubygem-webkit-gtk \
		rubygem-webkit-gtk2>=${PORTVERSION}:www/rubygem-webkit-gtk2

USES=		metaport
USE_RUBY=	yes

.include <bsd.port.mk>
