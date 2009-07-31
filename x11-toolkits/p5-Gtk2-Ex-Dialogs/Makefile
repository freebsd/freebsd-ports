# New ports collection makefile for:	p5-Gtk2-Ex-Dialogs
# Date created:		22 July 2008
# Whom:			Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-Ex-Dialogs
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Useful tools for Gnome2/Gtk2 Perl GUI design

BUILD_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-ExtUtils-Depends>=0.3:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo
RUN_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2

PERL_CONFIGURE=	yes
MAN3=		Gtk2::Ex::Dialogs::Question.3 \
		Gtk2::Ex::Dialogs::ChooseDirectory.3 \
		Gtk2::Ex::Dialogs::Message.3 \
		Gtk2::Ex::Dialogs::ErrorMsg.3 \
		Gtk2::Ex::Dialogs::ChooseFile.3 \
		Gtk2::Ex::Dialogs::ChoosePreviewFile.3 \
		Gtk2::Ex::Dialogs.3

.include <bsd.port.mk>
