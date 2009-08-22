# New ports collection makefile for:  tktable
# Date created:         25 Jun 2003
# Whom:                 thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	tktable
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/tk/Tk/}${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A table/matrix widget extension to Tk

USE_XORG=	x11
USE_TK=		84+

GNU_CONFIGURE=	yes
PORTDOCS=	*

PLIST_SUB=	DISTNAME=${DISTNAME}

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tkinclude=${TK_INCLUDEDIR} \
		--with-x

post-patch:
.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.if defined(MAINTAINER_MODE)
test: build
	(cd ${WRKSRC};  \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.post.mk>
