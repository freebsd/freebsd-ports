# New ports collection makefile for:	p5-GtkXmHTML
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GtkXmHTML
PORTVERSION=	0.7008
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

.include <bsd.port.mk>
