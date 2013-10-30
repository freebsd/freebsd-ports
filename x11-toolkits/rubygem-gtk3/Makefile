# $FreeBSD$

PORTNAME=	gtk3
PORTVERSION=	2.0.2
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GTK+3

RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:${PORTSDIR}/accessibility/rubygem-atk \
		rubygem-gdk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gdk3 \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2 \
		rubygem-gio2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gio2 \
		rubygem-glib2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-glib2 \
		rubygem-pango>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-pango

USE_GNOME=	gtk20
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
