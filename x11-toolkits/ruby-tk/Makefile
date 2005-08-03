# New ports collection makefile for:	ruby-tk
# Date created:		15 March 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES+=	x11-toolkits ruby tk${TK_VERSION}
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER?=	knu@FreeBSD.org
COMMENT?=	Ruby interface to the Tk widget set

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch
RUN_DEPENDS=	${RUBY_ARCHLIBDIR}/tcltklib.so:${PORTSDIR}/${TCLTKLIB_CATEGORY}/ruby-tcltklib

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

TK_VERSION?=	84
.if defined(WITH_TCLTK_JP)
TCLTKLIB_CATEGORY?=	japanese
.else
TCLTKLIB_CATEGORY?=	lang
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 1.7
MAKE_ARGS=	sitelibdir='$$(rubylibdir)'
.endif

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.if ${RUBY_VER} >= 1.8
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.fork ${RUBY_MODDOCDIR}/
.endif
.endif

.include <bsd.port.post.mk>
