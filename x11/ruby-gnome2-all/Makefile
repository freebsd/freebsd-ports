# New ports collection makefile for:	Ruby/GNOME2-all
# Date created:		3 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#   $MCom: ports/x11/ruby-gnome2-all/Makefile,v 1.2 2005/10/17 07:05:42 mezz Exp $
#

PORTNAME=	gnome2-all
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	The "meta-port" for Ruby/GNOME2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtkhtml2.so:${PORTSDIR}/www/ruby-gtkhtml2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtkmozembed.so:${PORTSDIR}/www/ruby-gtkmozembed \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gnomevfs.so:${PORTSDIR}/devel/ruby-gnomevfs \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/rsvg2.so:${PORTSDIR}/graphics/ruby-rsvg2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtkglext.so:${PORTSDIR}/x11-toolkits/ruby-gtkglext \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtksourceview.so:${PORTSDIR}/x11-toolkits/ruby-gtksourceview \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gnomeprintui2.so:${PORTSDIR}/x11-toolkits/ruby-gnomeprintui \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/panelapplet2.so:${PORTSDIR}/x11-toolkits/ruby-panelapplet \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2

USE_RUBY=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
