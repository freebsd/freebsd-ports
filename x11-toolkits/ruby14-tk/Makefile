# New ports collection makefile for:	ruby-tk
# Date created:		15 March 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	${RUBY_VERSION}
CATEGORIES+=	x11-toolkits ruby tk${TK_VERSION}
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	${RUBY_VER}
DISTNAME=	ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER?=	yasuf@bsdclub.org

RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/tcltklib.so:${PORTSDIR}/${TCLTKLIB_CATEGORY}/ruby14-tcltklib

WRKSRC=		${WRKDIR}/${DISTNAME}/ext/tk

RUBY_VER=	1.4

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

TK_VERSION?=	82
.if defined(WITH_TCLTK_JP)
TCLTKLIB_CATEGORY?=	japanese
.else
TCLTKLIB_CATEGORY?=	lang
.endif

.include <bsd.port.pre.mk>

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/tk
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk/
.endif

.include <bsd.port.post.mk>
