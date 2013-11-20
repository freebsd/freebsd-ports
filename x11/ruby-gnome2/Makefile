# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$
#   $MCom: ports/x11/ruby-gnome2/Makefile,v 1.6 2007/10/05 05:12:56 mezz Exp $

PORTNAME=	gnome2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	The "meta-port" for Ruby/GNOME2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gio2.so:${PORTSDIR}/devel/ruby-gio2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/goocanvas.so:${PORTSDIR}/x11-toolkits/ruby-goocanvas \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gstreamer.so:${PORTSDIR}/x11-toolkits/ruby-gstreamer \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtksourceview2.so:${PORTSDIR}/x11-toolkits/ruby-gtksourceview2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/poppler.so:${PORTSDIR}/x11-toolkits/ruby-poppler \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/rsvg2.so:${PORTSDIR}/graphics/ruby-rsvg2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/vte.so:${PORTSDIR}/x11-toolkits/ruby-vte

USE_RUBY=	yes

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
