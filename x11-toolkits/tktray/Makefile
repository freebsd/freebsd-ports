# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktray
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	http://www.sw4me.com/ CENKES
DISTNAME=	${TKPKG}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray icon support

USE_TK=		84
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} \
		--with-tkinclude=${TK_INCLUDEDIR} --enable-shared
CPPFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TCL_INCLUDEDIR}/generic
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	TKPKG=${TKPKG}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
MANN=		${PORTNAME}.n

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -Ee '/^.+TCLLIBPATH/s#$$# \\#' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${USE_LDCONFIG}/lib${TKPKG}.so ${USE_LDCONFIG}/lib${TKPKG}.so.0

.include <bsd.port.mk>
