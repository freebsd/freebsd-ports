# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	tktable
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/tk/Tk/}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A table/matrix widget extension to Tk

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.txt

USES+=		tk

GNU_CONFIGURE=	yes

PLIST_SUB=	DISTNAME=${DISTNAME}

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tkinclude=${TK_INCLUDEDIR} \
		--with-x \
		--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}

.if defined(MAINTAINER_MODE)
test: build
	(cd ${WRKSRC};  \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.mk>
