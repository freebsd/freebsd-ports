# New ports collection makefile for:	tix
# Date created:		22 December 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tix
PORTVERSION=	4.1.0.007
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk82
MASTER_SITES=   http://www.neosoft.com/tcl/ftparchive/%SUBDIR%/ \
		ftp://ftp.riken.go.jp/pub/lang/tcl/netsoft/%SUBDIR%/
MASTER_SITE_SUBDIR= sorted/packages-8.0/x11/Tix/4.1.0.007
DISTNAME=	Tix${PORTVERSION}

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/Tix4.1.0.007/unix/tk8.0
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-sam \
		--with-tcl="${PREFIX}/include/tcl8.2" \
		--with-tk="${PREFIX}/include/tk8.2"
# this should probably be added to bsd.port.mk
CONFIGURE_ENV=	PREFIX=${PREFIX}
MAN1=		tixwish.1
MANN=		BtnBox.n Balloon.n ChkList.n Destroy.n ComboBox.n Control.n \
		DItem.n DirDlg.n DirList.n DirTree.n FileBox.n EFileBox.n \
		EFileDlg.n FileDlg.n FileEnt.n Form.n GetBool.n GetInt.n \
		Grid.n HList.n InpOnly.n LabEntry.n Meter.n LabFrame.n \
		ListNBK.n Mwm.n NBFrame.n NoteBook.n SHList.n PopMenu.n \
		OptMenu.n PanedWin.n SListBox.n SText.n SWindow.n TList.n \
		Select.n StdBBox.n TixIntro.n Tree.n Utils.n Wm.n compound.n \
		pixmap.n tix.n

TIX_LIB=	libtix4182.so
TIXSAM_LIB=	libtixsam4182.so
TIX_LIB_FILE=	${TIX_LIB}.1
TIXSAM_LIB_FILE=${TIXSAM_LIB}.1

.include <bsd.port.pre.mk>

pre-configure:
	@(cd ${WRKSRC}/.. && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	@(cd ${WRKSRC}/.. && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${LN} -fs ${PREFIX}/bin/tixwish4.1.8.2 ${PREFIX}/bin/tixwish
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
