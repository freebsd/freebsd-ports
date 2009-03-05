# New ports collection makefile for:	p5-Tcl-Tk
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TclTk
PORTVERSION=	0.75
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5 tk
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Tcl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to access to Tk via the Tcl extension

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

BROKEN=		does not build, use x11-toolkits/p5-Tcl-Tk instead
DEPRECATED=	replaced by x11-toolkits/p5-Tcl-Tk
EXPIRATION_DATE=	2009-05-05

PERL_CONFIGURE=	yes

MAN3=		Tcl::Tk.3

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

do-configure:
	-@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.post.mk>
