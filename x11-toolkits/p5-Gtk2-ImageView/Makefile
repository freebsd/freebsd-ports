# New ports collection makefile for:	Gtk2-ImageView
# Date created:				2008/11/27
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Gtk2-ImageView
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RA/RATCLIFFE
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Perl bindings to the GtkImageView image viewer widget

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends	\
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	gtkimageview:${PORTSDIR}/x11-toolkits/gtkimageview
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

USE_GNOME=	gnomelibs

MAN3=		Gtk2::ImageView.3 \
  		Gtk2::Gdk::Pixbuf::Draw::Cache.3 \
  		Gtk2::ImageView::Anim.3 \
		Gtk2::ImageView::Nav.3 \
		Gtk2::ImageView::ScrollWin.3 \
		Gtk2::ImageView::Tool.3 \
		Gtk2::ImageView::Tool::Dragger.3 \
		Gtk2::ImageView::Tool::Painter.3 \
		Gtk2::ImageView::Tool::Selector.3 \
		Gtk2::ImageView::Zoom.3 \
		Gtk2::ImageView::index.3

.include <bsd.port.mk>
