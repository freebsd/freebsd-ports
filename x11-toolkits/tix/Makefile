# New ports collection makefile for:	tix
# Version required:	1.4b1
# Date created:		22 December 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id$
#

DISTNAME=	Tix4.1b1
PKGNAME=	tix-4.1b1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xpi.com/pub/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tk40 --enable-tk41 --enable-tk41_shared \
		--with-tcl75_src_dir=/usr/src/contrib/tcl \
		--with-tk41_src_dir="${PORTSDIR}/x11/tk41/work/tk4.1" \
		--with-extra_ldflags="-L${PREFIX}/lib"
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

pre-extract:
.if !exists(/usr/src/contrib/tcl)
	@echo "Tix wants access to the Tcl source."
	@echo "Please install /usr/src/contrib/tcl"
	@echo "from the FreeBSD source distribution."
	@false
.endif
.if !exists(${PORTSDIR}/x11/tk41/work/tk4.1)
	@cd ${PORTSDIR}/x11/tk41; make extract
.endif

post-install:
	@${MKDIR} ${PREFIX}/man/man1
	@mv ${PREFIX}/man/mann/tixwish.1 ${PREFIX}/man/man1
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
