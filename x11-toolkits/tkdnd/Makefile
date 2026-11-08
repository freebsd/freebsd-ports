PORTNAME=	tkdnd
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/TkDND/TkDND%20${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Native drag and drop capabilities for Tk
WWW=		http://www.iit.demokritos.gr/~petasis/Tcl/tkDND/tkDND.html

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES+=		tk:tea xorg
USE_XORG=	x11 xext

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

TCL_PKG=	${PORTNAME}${PORTVERSION}
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/tkDND.n ${STAGEDIR}/${PREFIX}/share/man/mann/${MANN}

.include <bsd.port.mk>
