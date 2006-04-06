# New ports collection makefile for:	tkXwin
# Date created:				Tue Aug  9 14:32:29 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkXwin
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITES_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl/Tk library to detect idle periods of an X session

LIB_DEPENDS=	tcl${SHORT_TK_VER}:${PORTSDIR}/lang/tcl${SHORT_TK_VER} \
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TK_VER} \
		--with-tk=${LOCALBASE}/lib/tk${TK_VER} \
		--with-tkinclude=${LOCALBASE}/include/tk${TK_VER}
CONFIGURE_ENV=	INSTALL="${INSTALL_DATA}"

TK_VER=		8.4
SHORT_TK_VER=	${TK_VER:S/.//}

.include <bsd.port.mk>
