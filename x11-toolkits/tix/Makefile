# New ports collection makefile for:	tix
# Version required:	4.1b2
# Date created:		22 December 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.2 1997/01/02 07:12:33 tg Exp $
#

DISTNAME=	Tix4.1b2
PKGNAME=	tix-4.1b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xpi.com/pub/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tk40 --enable-tk41 --enable-tk41-shared \
		--with-tcl75_src_dir=/usr/include/tcl \
		--with-tk41_src_dir="${PREFIX}/include/tk" \
		--with-extra_ldflags="-L${PREFIX}/lib"
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

post-install:
	@${MKDIR} ${PREFIX}/man/man1
	@mv ${PREFIX}/man/mann/tixwish.1 ${PREFIX}/man/man1
	@ln -sf ${PREFIX}/bin/tixwish4.1.4.1 ${PREFIX}/bin/tixwish
	/sbin/ldconfig -m ${PREFIX}/lib
.for dir in generic unix
	@${MKDIR} ${PREFIX}/include/tix/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.h ${PREFIX}/include/tix/${dir}
.endfor
	${RM} ${PREFIX}/include/tix/generic/tix.h
	@# These two files are the same
	/bin/ln -sf ../../tix.h ${PREFIX}/include/tix/generic

.include <bsd.port.mk>
