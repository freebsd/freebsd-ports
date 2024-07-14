PORTNAME=	tix
DISTVERSION=	8.4.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF
DISTNAME=	Tix${DISTVERSION}-src${DISTVERSIONSUFFIX}

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Extension to the Tk toolkit
WWW=		https://tix.sourceforge.net/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/docs/license.tcltk
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tk:tea
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/Tix${DISTVERSION}

TIX_LIB=	libTix${PORTVERSION}.so
TIX_LIB_FILE=	${TIX_LIB}.0

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-configure:
	@(cd ${WRKSRC} && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS})

post-configure:
	@${REINPLACE_CMD} -e "s|package require Tcl 8\.4|package require Tcl ${TCL_VER}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,TCL_SRC_DIR .*,TCL_SRC_DIR=${TCL_INCLUDEDIR},g" \
	-e "s,TK_SRC_DIR .*,TK_SRC_DIR=${TK_INCLUDEDIR},g" \
	-e "s,\$$(TCL_BIN_DIR)/tclsh,${TCLSH},g" \
	${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.n ${STAGEDIR}${PREFIX}/share/man/mann/
	${RM} ${STAGEDIR}${PREFIX}/lib/Tix${PORTVERSION}/${TIX_LIB}
	${CP} -p ${WRKSRC}/${TIX_LIB} ${WRKSRC}/${TIX_LIB_FILE}
	${INSTALL_LIB} ${WRKSRC}/${TIX_LIB_FILE} ${STAGEDIR}${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/${TIX_LIB_FILE} ${STAGEDIR}${PREFIX}/lib/${TIX_LIB}
	${LN} -fs ${PREFIX}/lib/${TIX_LIB_FILE} ${STAGEDIR}${PREFIX}/lib/Tix${PORTVERSION}/${TIX_LIB}
.for dir in generic unix
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tix/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.h ${STAGEDIR}${PREFIX}/include/tix/${dir}
.endfor
	${LN} -sf ${PREFIX}/include/tix/generic/tix.h ${STAGEDIR}${PREFIX}/include/tix.h
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/Tix${PORTVERSION}/html

.include <bsd.port.post.mk>
