# New ports collection makefile for:	Ruby-FLTK
# Date created:		25 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	0.8.2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_WITH_PTHREAD=	yes

USE_MESA=	yes

INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-fltk-dir="${X11BASE}" --with-gl-dir="${X11BASE}"
MAKE_ARGS=	LOCAL_LIBS="-lgcc"

DOCS_EN=	Changes README ToDo doc/en/*.txt
DOCS_JA=	doc/ja/*.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
