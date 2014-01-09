# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	tkXwin
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://beepcore-tcl.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl/Tk library to detect idle periods of an X session

USES=		tk:84
GNU_CONFIGURE=	yes
USE_XORG=	xt xscrnsaver
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tkinclude=${TK_INCLUDEDIR}
CONFIGURE_ENV=	INSTALL="${INSTALL_DATA}"

.include <bsd.port.mk>
