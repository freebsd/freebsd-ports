# New ports collection makefile for:	p5-Tcl-Tk
# Version required:			b1
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	TclTk-b2
PKGNAME=	p5-Tcl-Tk-b2
CATEGORIES=	x11-toolkits lang perl5 tk82
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/TclTk

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tcl::Tk.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
