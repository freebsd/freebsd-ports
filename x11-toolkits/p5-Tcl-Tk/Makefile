# New ports collection makefile for:	p5-Tcl-Tk
# Version required:			b1
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/16 03:05:22 jfitz Exp $

DISTNAME=	TclTk-b1
PKGNAME=	p5-Tcl-Tk-b1
CATEGORIES=	x11 lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5
LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/TclTk

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Tcl::Tk.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
