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
COMMENT=	Perl5 module to access to Tk via the Tcl extension

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		Tcl::Tk.3

post-patch:
	@${PERL} -pi -e 's,%LOCALBASE%,${LOCALBASE},g; \
		s,%X11BASE%,${X11BASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
