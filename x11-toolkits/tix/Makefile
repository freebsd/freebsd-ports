# New ports collection makefile for:	tix
# Date created:		22 December 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tix
PORTVERSION=	8.1.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= tix

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	An extension to the Tk toolkit

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${TCL84_PORT}:build \
		${NONEXISTENT}:${PORTSDIR}/${TK84_PORT}:build
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${DISTNAME}/unix/tk8.4
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-sam \
		--with-tclconfig="${PREFIX}/lib/tcl8.4" \
		--with-tkconfig="${PREFIX}/lib/tk8.4" \
		--with-tclinclude="${PREFIX}/include/tcl8.4" \
		--with-tkinclude="${PREFIX}/include/tk8.4"
# this should probably be added to bsd.port.mk
CONFIGURE_ENV=	PREFIX=${PREFIX}
MAN1=		tixwish.1
MANN=		TixIntro.n compound.n pixmap.n tix.n tixBalloon.n \
		tixButtonBox.n tixCheckList.n tixComboBox.n tixControl.n \
		tixDestroy.n tixDirList.n tixDirSelectDialog.n tixDirTree.n \
		tixDisplayStyle.n tixExFileSelectBox.n tixExFileSelectDialog.n \
		tixFileEntry.n tixFileSelectBox.n tixFileSelectDialog.n \
		tixForm.n tixGetBoolean.n tixGetInt.n tixGrid.n tixHList.n \
		tixInputOnly.n tixLabelEntry.n tixLabelFrame.n \
		tixListNoteBook.n tixMeter.n tixMwm.n tixNBFrame.n \
		tixNoteBook.n tixOptionMenu.n tixPanedWindow.n tixPopupMenu.n \
		tixScrolledHList.n tixScrolledListBox.n tixScrolledText.n \
		tixScrolledWindow.n tixSelect.n tixStdButtonBox.n tixTList.n \
		tixTree.n tixUtils.n

TIX_LIB=	libtix8184.so
TIXSAM_LIB=	libtixsam8184.so
TIX_LIB_FILE=	${TIX_LIB}.1
TIXSAM_LIB_FILE=${TIXSAM_LIB}.1
TIXWISH=	tixwish8.1.8.4
TCL84_PORT?=	lang/tcl84
TK84_PORT?=	x11-toolkits/tk84

.include <bsd.port.pre.mk>

TCLBASE!=	( cd ${PORTSDIR}/${TCL84_PORT} && make -V TCLBASE )
TCLWRK!=	( cd ${PORTSDIR}/${TCL84_PORT} && make -V WRKDIR )
TKBASE!=	( cd ${PORTSDIR}/${TK84_PORT} && make -V TKBASE )
TKWRK!=		( cd ${PORTSDIR}/${TK84_PORT} && make -V WRKDIR )

pre-configure:
	@(cd ${WRKSRC}/.. && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
	${REINPLACE_CMD} \
		-e 's|$${WRKDIRPREFIX}${TCLBASE}/work|${TCLWRK}|g' \
		-e 's|$${WRKDIRPREFIX}${TKBASE}/work|${TKWRK}|g' \
		${WRKSRC}/../Makefile

post-configure:
	${REINPLACE_CMD} \
		-e 's|$${WRKDIRPREFIX}${TCLBASE}/work|${TCLWRK}|g' \
		-e 's|$${WRKDIRPREFIX}${TKBASE}/work|${TKWRK}|g' \
		${WRKSRC}/Makefile

post-install:
	@(cd ${WRKSRC}/.. && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${LN} -fs ${PREFIX}/bin/${TIXWISH} ${PREFIX}/bin/tixwish
	${LN} -fs ${TIX_LIB_FILE} ${PREFIX}/lib/${TIX_LIB}
	${LN} -fs ${TIXSAM_LIB_FILE} ${PREFIX}/lib/${TIXSAM_LIB}
.for dir in generic unix
	@${MKDIR} ${PREFIX}/include/tix/${dir}
	${INSTALL_DATA} ${WRKSRC}/../../${dir}/*.h ${PREFIX}/include/tix/${dir}
.endfor
	${RM} ${PREFIX}/include/tix/generic/tix.h
	@# These two files are the same
	${LN} -sf ../../tix.h ${PREFIX}/include/tix/generic
	${MV} ${PREFIX}/man/mann/tixwish.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
