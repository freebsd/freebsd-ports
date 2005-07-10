# New ports collection makefile for:	Ruby/GNOME2-all
# Date created:		3 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-all
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	The "meta-port" for Ruby/GNOME2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR}/gtkhtml2.so:${PORTSDIR}/www/ruby-gtkhtml2 \
		${RUBY_SITEARCHLIBDIR}/gnomevfs.so:${PORTSDIR}/devel/ruby-gnomevfs \
		${RUBY_SITEARCHLIBDIR}/gst.so:${PORTSDIR}/multimedia/ruby-gst \
		${RUBY_SITEARCHLIBDIR}/libgda.so:${PORTSDIR}/databases/ruby-libgda \
		${RUBY_SITEARCHLIBDIR}/rsvg2.so:${PORTSDIR}/graphics/ruby-rsvg2 \
		${RUBY_SITEARCHLIBDIR}/gtkglext.so:${PORTSDIR}/x11-toolkits/ruby-gtkglext \
		${RUBY_SITEARCHLIBDIR}/gtksourceview.so:${PORTSDIR}/x11-toolkits/ruby-gtksourceview \
		${RUBY_SITEARCHLIBDIR}/gnomeprintui2.so:${PORTSDIR}/x11-toolkits/ruby-gnomeprintui \
		${RUBY_SITEARCHLIBDIR}/panelapplet2.so:${PORTSDIR}/x11-toolkits/ruby-panelapplet \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2

USE_RUBY=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
