# New ports collection makefile for:	p5-Tcl-Tk
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TclTk
PORTVERSION=	b2
CATEGORIES=	x11-toolkits lang perl5 tk82
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tcl::Tk.3

.include <bsd.port.mk>
