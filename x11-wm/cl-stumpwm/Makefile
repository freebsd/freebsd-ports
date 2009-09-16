# New ports collection makefile for:	stumpwm
# Date created:				2008-02-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	stumpwm
PORTVERSION=	0.9.6
CATEGORIES=	x11-wm
MASTER_SITES=	SAVANNAH
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiling, keyboard driven Window Manager written in Common Lisp

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=clisp

PLIST_FILES=	bin/${PORTNAME}
INFO=		${PORTNAME}

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/clisp) || \
    !exists(${LOCALBASE}/lib/clisp/full/clx.o)
IGNORE=		requires lang/clisp built with CLX_NEW option ON
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>
