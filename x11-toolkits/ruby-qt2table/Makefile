# New ports collection makefile for:	Ruby-qt2table
# Date created:		23 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2table
PORTVERSION=	${RUBY_QT2_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_QT2_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_QT2_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${RUBY_QT2_WRKSRC}/modules/table
CONFIGURE_ARGS=	${RUBY_QT2_CONFIGURE_ARGS}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

.include "${.CURDIR}/../ruby-qt2/Makefile.common"
.include <bsd.port.mk>
