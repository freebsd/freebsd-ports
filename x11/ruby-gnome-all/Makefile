# New ports collection makefile for:	Ruby-GNOME-all
# Date created:		3 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-all
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The "meta-port" for Ruby/GNOME

#RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/lglade.so:${PORTSDIR}/devel/ruby-libglade
#RUN_DEPENDS+=	${RUBY_SITELIBDIR}/gdk_imlib.rb:${PORTSDIR}/graphics/ruby-gdk_imlib
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/gdk_pixbuf.rb:${PORTSDIR}/graphics/ruby-gdk_pixbuf
#RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gnome.so:${PORTSDIR}/x11/ruby-gnome
#RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/libart.so:${PORTSDIR}/graphics/ruby-libart

# libglade	depends on gtk, gnome
# gdk_imlib	depends on gtk
# gdk_pixbuf	depends on gtk
# gnome		depends on gtk, gdk_imlib, libart

USE_RUBY=	yes

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
