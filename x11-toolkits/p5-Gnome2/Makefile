# ex:ts=8
# Ports collection makefile for:	p5-Gnome2
# Date created:			Jan 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2
PORTVERSION=	1.00
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl/:cpan \
		gtk2-perl/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/Canvas.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/Canvas.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas

USE_GNOME=	libgnomeui libgnome libbonoboui
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
