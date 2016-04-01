# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Gnome2-Wnck
PORTVERSION=	0.16
#PORTREVISION=	0
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl interface to the Window Navigator Construction Kit

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Glib2>=0:devel/p5-Glib2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck
RUN_DEPENDS=	p5-Glib2>=0:devel/p5-Glib2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
