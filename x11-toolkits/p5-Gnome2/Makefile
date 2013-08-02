# ex:ts=8
# Ports collection makefile for:	p5-Gnome2
# Date created:			Jan 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2
PORTVERSION=	1.042
PORTREVISION=	5
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Gnome2-VFS>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		p5-Gnome2-Canvas>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas
RUN_DEPENDS=	p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gnome2-VFS>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		p5-Gnome2-Canvas>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas

USE_GNOME=	libgnomeui libgnome libbonoboui
USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
