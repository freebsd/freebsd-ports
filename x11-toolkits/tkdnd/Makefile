# New ports collection makefile for:	tkdnd
# Date created:		14 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdnd
PORTVERSION=	1.0
DISTVERSION=	1.0.20040304
PORTREVISION=	3
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	CENKES
# Distfile prepared from SourceForge CVS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Native drag and drop capabilities

USE_BZIP2=	yes
USE_TK=		yes
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} --with-tkinclude=${TK_INCLUDEDIR} --enable-shared
CPPFLAGS=	-I${TK_INCLUDEDIR}/generic -I${TCL_INCLUDEDIR}/generic
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	TKPKG=${TKPKG}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
MANN=		${PORTNAME}.n

post-patch:
	@${REINPLACE_CMD} -Ee '/^install:/s#install-doc##' -e 's#.*txt.*##' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${USE_LDCONFIG}/lib${TKPKG}.so ${USE_LDCONFIG}/lib${TKPKG}.so.0
	@${INSTALL_MAN} ${WRKSRC}/doc/tkDND.n ${MANNPREFIX}/man/mann/${MANN}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
