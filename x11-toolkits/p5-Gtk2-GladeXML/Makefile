# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	Gtk2-GladeXML
PORTVERSION=	1.007
PORTREVISION=	4
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Creates users interfaces directly from Glade XML files

LICENSE=	LGPL20

BUILD_DEPENDS=	p5-Glib2>=1.00:devel/p5-Glib2 \
		p5-ExtUtils-Depends>=0.3:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.1:devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2 \
		p5-Cairo>=0:graphics/p5-Cairo
RUN_DEPENDS=	p5-Glib2>=1.00:devel/p5-Glib2 \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2

USE_GNOME=	libglade2

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
