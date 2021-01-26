# Created by: ijliao
# $FreeBSD$

PORTNAME=	Gnome2
PORTVERSION=	1.048
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN \
		SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

LICENSE=	LGPL21

DEPRECATED=	Deprecated by the Gtk-Perl project. No more security patches and bug fixes
EXPIRATION_DATE=2021-02-28

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib>=0:devel/p5-Glib \
		p5-Gnome2-Canvas>=0:x11-toolkits/p5-Gnome2-Canvas \
		p5-Gnome2-VFS>=0:x11-toolkits/p5-Gnome2-VFS \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2
RUN_DEPENDS=	p5-Glib>=0:devel/p5-Glib \
		p5-Gnome2-Canvas>=0:x11-toolkits/p5-Gnome2-Canvas \
		p5-Gnome2-VFS>=0:x11-toolkits/p5-Gnome2-VFS \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

USES=		gnome perl5
USE_GNOME=	libbonoboui libgnome libgnomeui
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gnome2/Gnome2.so

.include <bsd.port.mk>
