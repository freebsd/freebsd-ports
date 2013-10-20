# Created by: ijliao
# $FreeBSD$

PORTNAME=	Gnome2
PORTVERSION=	1.044
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gnome2-Canvas>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas \
		p5-Gnome2-VFS>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gnome2-Canvas>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas \
		p5-Gnome2-VFS>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_GNOME=	libbonoboui libgnome libgnomeui
USE_PERL5=	configure

.include <bsd.port.mk>
