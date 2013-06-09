# $FreeBSD$

PORTNAME=	gnome2
PORTVERSION=	2.0.2
CATEGORIES=	x11 rubygems
CATEGORIES=	x11 gnome rubygems
MASTER_SITES=	# none
PKGNAMEPREFIX=	rubygem-
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Meta port for all Ruby Gnome2 Gems

RUN_DEPENDS=	rubygem-clutter-gtk>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-clutter-gtk \
		rubygem-goocanvas>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-goocanvas \
		rubygem-rsvg2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-rsvg2 \
		rubygem-clutter-gstreamer>=${PORTVERSION}:${PORTSDIR}/multimedia/rubygem-clutter-gstreamer \
		rubygem-webkit-gtk>=${PORTVERSION}:${PORTSDIR}/www/rubygem-webkit-gtk \
		rubygem-webkit-gtk2>=${PORTVERSION}:${PORTSDIR}/www/rubygem-webkit-gtk2 \
		rubygem-gtksourceview2>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtksourceview2 \
		rubygem-gtksourceview3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtksourceview3 \
		rubygem-poppler>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-poppler \
		rubygem-vte>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-vte

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
