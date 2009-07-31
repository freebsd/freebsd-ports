# New ports collection makefile for:		x11-toolkits/p5-Gtk2
# Date created:					Oct 27 2003
# Whom:						clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2
PORTVERSION=	1.200
PORTREVISION=	2
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN SF/gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2

USE_GNOME=	gtk20 pango
PERL_CONFIGURE=	5.8.0+
USE_GMAKE=	yes
CONFIGURE_ENV+=	FORCE_GMAKE=yes

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
