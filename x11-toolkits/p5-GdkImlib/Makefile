# New ports collection makefile for:	p5-GdkImlib
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GdkImlib
PORTVERSION= 	0.7004
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/mach/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_PERL5=	yes
USE_IMLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
	CC="${CC}" CCFLAGS="${CFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
