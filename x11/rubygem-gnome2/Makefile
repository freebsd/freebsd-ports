# $FreeBSD$

PORTNAME=	gnome2
PORTVERSION=	3.0.7
CATEGORIES=	x11 gnome rubygems
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Meta port for all Ruby Gnome2 Gems

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:${PORTSDIR}/accessibility/rubygem-atk \
		rubygem-cairo-gobject>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-cairo-gobject \
		rubygem-clutter>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-clutter \
		rubygem-clutter-gstreamer>=${PORTVERSION}:${PORTSDIR}/multimedia/rubygem-clutter-gstreamer \
		rubygem-clutter-gtk>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-clutter-gtk \
		rubygem-gdk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gdk3 \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2 \
		rubygem-gio2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gio2 \
		rubygem-glib2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-glib2 \
		rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection \
		rubygem-goocanvas>=2.2.0:${PORTSDIR}/graphics/rubygem-goocanvas \
		rubygem-gstreamer>=${PORTVERSION}:${PORTSDIR}/multimedia/rubygem-gstreamer \
		rubygem-gtk2>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3 \
		rubygem-gtksourceview2>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtksourceview2 \
		rubygem-gtksourceview3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtksourceview3 \
		rubygem-pango>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-pango \
		rubygem-poppler>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-poppler \
		rubygem-rsvg2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-rsvg2 \
		rubygem-vte>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-vte \
		rubygem-vte3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-vte3 \
		rubygem-webkit-gtk>=${PORTVERSION}:${PORTSDIR}/www/rubygem-webkit-gtk \
		rubygem-webkit-gtk2>=${PORTVERSION}:${PORTSDIR}/www/rubygem-webkit-gtk2 \

USES=		metaport
USE_RUBY=	yes

.include <bsd.port.mk>
