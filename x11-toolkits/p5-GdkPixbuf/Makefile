# New ports collection makefile for:	p5-GdkPixbuf
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GdkPixbuf
PORTVERSION=	0.7009
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5 gnome
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Pixbuf module of Gtk-Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3=		Gtk::Gdk::Pixbuf::reference.3pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
