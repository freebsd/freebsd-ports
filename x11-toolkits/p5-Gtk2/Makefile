# New ports collection makefile for:		x11-toolkits/p5-Gtk2
# Date created:					Oct 27 2003
# Whom:						clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2
PORTVERSION=	1.043
PORTREVISION=	0
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl/:cpan \
		gtk2-perl/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2

USE_GNOME=	gtk20 pango
PERL_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
