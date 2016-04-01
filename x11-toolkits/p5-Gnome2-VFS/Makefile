# Created by: ijliao
# $FreeBSD$

PORTNAME=	Gnome2-VFS
PORTVERSION=	1.082
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	SF/gtk2-perl/Gnome2_VFS/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allows you to use the GNOME Virtual File System library from Perl

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:devel/p5-Glib2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2
RUN_DEPENDS=	p5-Glib2>=0:devel/p5-Glib2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes
USE_GNOME=	gnomevfs2
USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
