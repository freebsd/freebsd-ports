# New ports collection makefile for:	p5-GdkImlib
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GdkImlib
PORTVERSION=	0.7009
PORTREVISION=	8
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN/Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Imlib module of Gtk-Perl

DEPRECATED=	Abandonned upstream, not used by any ports
EXPIRATION_DATE=	2012-10-20

BUILD_DEPENDS=	p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes
USE_GNOME=	imlib
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3=		Gtk::Gdk::ImlibImage::reference.3pm

.include <bsd.port.mk>
