# New ports collection makefile for:	Ruby/GNOME2-all
# Date created:		3 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-all
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The "meta-port" for Ruby/GNOME2

RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/pango.so:${PORTSDIR}/x11-toolkits/ruby-pango
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/libart2.so:${PORTSDIR}/graphics/ruby-libart2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gnomecanvas2.so:${PORTSDIR}/graphics/ruby-gnomecanvas2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2
#RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtkhtml2.so:${PORTSDIR}/www/ruby-gtkhtml2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gnomevfs.so:${PORTSDIR}/devel/ruby-gnomevfs
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gst.so:${PORTSDIR}/multimedia/ruby-gst

# pango         depends on glib2
# gdk_pixbuf2   depends on glib2
# gconf2        depends on glib2
# gtk2          depends on glib2, gdk_pixbuf2, and pango
# gnomecanvas2  depends on glib2, gtk2 and libart2
# gnome2        depends on gtk2, gnomecanvas2
# libglade2     depends on gtk2 and gnome2 (optional)

USE_RUBY=       yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
