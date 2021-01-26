# Created by: ijliao
# $FreeBSD$

PORTNAME=	Gnome2-VFS
PORTVERSION=	1.084
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	SF/gtk2-perl/Gnome2_VFS/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allows you to use the GNOME Virtual File System library from Perl

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Deprecated by the Gtk-Perl project. No more security patches and bug fixes
EXPIRATION_DATE=2021-02-28

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib>=0:devel/p5-Glib \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2
RUN_DEPENDS=	p5-Glib>=0:devel/p5-Glib \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

USES=		gnome perl5 pkgconfig
USE_GNOME=	gnomevfs2
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
