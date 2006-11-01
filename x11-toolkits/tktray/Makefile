# New ports collection makefile for:	tktray
# Date created:		14 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tktray
PORTVERSION=	1.1
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	http://www.sw4me.com/ CSME
DISTNAME=	${TKPKG}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	System tray icon support

LIB_DEPENDS=	tk${USE_TK}.1:${PORTSDIR}/x11-toolkits/tk${USE_TK}

USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} \
		--with-tkinclude=${TK_INCLUDEDIR} --enable-shared
CPPFLAGS=	-I${TK_INCLUDEDIR}/generic -I${TCL_INCLUDEDIR}/generic
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	TKPKG=${TKPKG}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
MANN=		${PORTNAME}.n

post-patch:
	@${REINPLACE_CMD} -Ee '/^.+TCLLIBPATH/s#$$# \\#' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${USE_LDCONFIG}/lib${TKPKG}.so ${USE_LDCONFIG}/lib${TKPKG}.so.0

.include <bsd.port.mk>
