# New ports collection makefile for:	p5-Tcl-Tk
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TclTk
PORTVERSION=	0.75
CATEGORIES=	x11-toolkits lang perl5 tk82
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to access to Tk via the Tcl extension

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

PERL_CONFIGURE=	yes

MAN3=		Tcl::Tk.3

do-configure:
	-@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601 # lang/p5-Tcl does
IGNORE=         requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
