# New ports collection makefile for:	tix
# Date created:		22 December 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tix
PORTVERSION=	8.4.3
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	An extension to the Tk toolkit

DISTNAME=	Tix${DISTVERSION}-src${DISTVERSIONSUFFIX}
WRKSRC=		${WRKDIR}/Tix${DISTVERSION}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_TK=		84+
CONFIGURE_ARGS=	--enable-shared --enable-sam \
		--with-tclconfig="${TCL_LIBDIR}" \
		--with-tkconfig="${TK_LIBDIR}" \
		--with-tclinclude="${TCL_INCLUDEDIR}" \
		--with-tkinclude="${TK_INCLUDEDIR}"
# this should probably be added to bsd.port.mk
CONFIGURE_ENV=	PREFIX=${PREFIX}
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

.include <bsd.port.pre.mk>

pre-extract:
	@${MAKE} clean

pre-configure:
	@(cd ${WRKSRC} && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-configure:
	@${REINPLACE_CMD} -e "s|package require Tcl 8\.4|package require Tcl ${TCL_VER}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,TCL_SRC_DIR .*,TCL_SRC_DIR=${TCL_INCLUDEDIR},g" \
	-e "s,TK_SRC_DIR .*,TK_SRC_DIR=${TK_INCLUDEDIR},g" \
	-e "s,\$$(TCL_BIN_DIR)/tclsh,${TCLSH},g" \
	${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.n ${PREFIX}/man/mann/

.include <bsd.port.post.mk>
