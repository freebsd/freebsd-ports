# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Gtk2
PORTVERSION=	1.24993
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN \
		SF/${PORTNAME:tl}-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Cairo>=1:graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0.300:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.280:devel/p5-Glib2 \
		p5-Pango>=1.220:x11-toolkits/p5-Pango
RUN_DEPENDS=	p5-Cairo>=1:graphics/p5-Cairo \
		p5-Glib2>=1.280:devel/p5-Glib2 \
		p5-Pango>=1.220:x11-toolkits/p5-Pango

USES=		gmake gnome perl5
USE_PERL5=	configure
USE_GNOME=	gtk20 pango

CONFIGURE_ENV=	FORCE_MAKE_CMD=yes

.include <bsd.port.mk>
