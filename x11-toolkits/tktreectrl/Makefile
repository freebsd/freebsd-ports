# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
PORTVERSION=	2.4.1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Multi-column hierarchical listbox widget

USES=		tk:86
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--exec-prefix=${PREFIX} \
		--enable-shared
TKPKG=		treectrl${PORTVERSION}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
PLIST_SUB=	TKPKG=${TKPKG}

.include <bsd.port.mk>
