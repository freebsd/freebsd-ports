# New ports collection makefile for:		x11-toolkits/p5-Gtk2
# Date created:					Oct 27 2003
# Whom:						clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2
PORTVERSION=	1.00
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20
PERL_CONFIGURE=	yes

MAN3=		Gtk2.3 Gtk2::devel.3 Gtk2::api.3 Gtk2::Pango.3 \
		Gtk2::Gdk::Keysyms.3 Gtk2::SimpleMenu.3 \
		Gtk2::Helper.3 Gtk2::SimpleList.3 Gtk2::CodeGen.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
