# New ports collection makefile for:	tktreectrl
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tktreectrl
PORTVERSION=	2.2.8
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Multi-column hierarchical listbox widget

USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--exec-prefix=${PREFIX} --enable-shared
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${TCL_INCLUDES} ${TK_INCLUDES}"
TCL_INCLUDES=	-I${TCL_INCLUDEDIR} -I${TCL_INCLUDEDIR}/generic
TK_INCLUDES=	-I${TK_INCLUDEDIR} -I${TK_INCLUDEDIR}/generic \
		-I${TK_INCLUDEDIR}/unix
TKPKG=		treectrl${PORTVERSION}
TKLIBVER=	2.2
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG} TKLIBVER=${TKLIBVER}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
MANN=	treectrl.n

post-install:
	@${LN} -sf ${PREFIX}/lib/${TKPKG}/libtreectrl${TKLIBVER}.so \
		${PREFIX}/lib/${TKPKG}/libtreectrl${TKLIBVER}.so.0
	@${LN} -sf ${PREFIX}/lib/${TKPKG}/libtreectrl${TKLIBVER}.so \
		${PREFIX}/lib/${TKPKG}/libtreectrl.so.0

.include <bsd.port.mk>
