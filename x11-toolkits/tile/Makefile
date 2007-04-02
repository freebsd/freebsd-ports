# New ports collection makefile for:	tile
# Date created:		18 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tile
PORTVERSION=	0.7.8
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	SF/tktable

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Themed widget set for Tk

USE_TK=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include \
		--exec-prefix=${PREFIX} --enable-shared
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${TCL_INCLUDES} ${TK_INCLUDES}"
TCL_INCLUDES=	-I${LOCALBASE}/include/tcl${TK_VER} -I${LOCALBASE}/include/tcl${TK_VER}/generic
TK_INCLUDES=	-I${LOCALBASE}/include/tk${TK_VER} -I${LOCALBASE}/include/tk${TK_VER}/generic
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}

post-install:
	@${LN} -sf ${USE_LDCONFIG}/lib${TKPKG}.so ${USE_LDCONFIG}/lib${TKPKG}.so.0

.include <bsd.port.mk>
