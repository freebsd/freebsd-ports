# New ports collection makefile for:	p5-Gtk2-GladeXML
# Date created:		22 July 2008
# Whom:			Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-GladeXML
PORTVERSION=	1.007
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Creates users interfaces directly from Glade XML files

BUILD_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-ExtUtils-Depends>=0.3:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo
RUN_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	libglade2

PERL_CONFIGURE=	yes
MAN3=	${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
