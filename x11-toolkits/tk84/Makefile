# New ports collection makefile for:	tk8.1
# Version required:	8.1a2
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.20 1998/12/13 08:49:14 asami Exp $
#

DISTNAME=	tk8.1b1
PKGNAME=	tk-8.1.b1
CATEGORIES=	x11-toolkits tk81
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_1/

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	tcl81.1:${PORTSDIR}/lang/tcl81
FILE_DEPENDS=	${PORTSDIR}/x11-toolkits/tk80

USE_XLIB=	yes
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}
PKGINSTALL=     ${PORTSDIR}/x11-toolkits/tk80/pkg/INSTALL.wish

MAN1=	wish.1
MAN3=	3DBorder.3 BindTable.3 CanvPsY.3 CanvTkwin.3 CanvTxtInfo.3 \
	Clipboard.3 ClrSelect.3 ConfigWidg.3 ConfigWind.3 CoordToWin.3 \
	CrtErrHdlr.3 CrtGenHdlr.3 CrtImgType.3 CrtItemType.3 CrtPhImgFmt.3 \
	CrtSelHdlr.3 CrtWindow.3 DeleteImg.3 DrawFocHlt.3 EventHndlr.3 \
	FindPhoto.3 FontId.3 FreeXId.3 GeomReq.3 GetAnchor.3 GetBitmap.3 \
	GetCapStyl.3 GetClrmap.3 GetColor.3 GetCursor.3 GetFont.3 GetGC.3 \
	GetImage.3 GetJoinStl.3 GetJustify.3 GetOption.3 GetPixels.3 \
	GetPixmap.3 GetRelief.3 GetRootCrd.3 GetScroll.3 GetSelect.3 GetUid.3 \
	GetVRoot.3 GetVisual.3 HandleEvent.3 IdToWindow.3 ImgChanged.3 \
	InternAtom.3 MainLoop.3 MainWin.3 MaintGeom.3 ManageGeom.3 \
	MapWindow.3 MeasureChar.3 MoveToplev.3 Name.3 NameOfImg.3 OwnSelect.3 \
	ParseArgv.3 QWinEvent.3 Restack.3 RestrictEv.3 SetAppName.3 \
	SetClass.3 SetGrid.3 SetOptions.3 SetVisual.3 StrictMotif.3 \
	TextLayout.3 Tk_Init.3 Tk_Main.3 WindowId.3
MANN=	bell.n bind.n bindtags.n bitmap.n button.n canvas.n checkbutton.n \
	chooseColor.n clipboard.n dde.n destroy.n dialog.n entry.n event.n \
	focus.n focusNext.n font.n frame.n getOpenFile.n grab.n grid.n \
	image.n label.n listbox.n loadTk.n lower.n menu.n menubar.n \
	menubutton.n message.n messageBox.n option.n optionMenu.n options.n \
	pack-old.n pack.n palette.n photo.n place.n popup.n radiobutton.n \
	raise.n scale.n scrollbar.n selection.n send.n text.n tk.n tkerror.n \
	tkvars.n tkwait.n toplevel.n winfo.n wm.n
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.post.mk>
