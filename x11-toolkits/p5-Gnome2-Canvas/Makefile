# ex:ts=8
# Ports collection makefile for:	p5-Gnome2-Canvas
# Date created:			Apr 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2-Canvas
PORTVERSION=	1.002
PORTREVISION=	7
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN/Gnome2 \
		SF/gtk2-perl/Gnome2_Canvas/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows a perl developer to use the GnomeCanvas widget with Gtk2-Perl

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo
RUN_DEPENDS=	p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	libgnomecanvas
USE_PKGCONFIG=	build
PERL_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
