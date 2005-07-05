# New ports collection makefile for:	tk
# Date created:		19 August 1997
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	8.4.11
PORTEPOCH=	2
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcl
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical toolkit for TCL

LIB_DEPENDS=	tcl84:${PORTSDIR}/${TCL84_PORT}

LATEST_LINK=	tk84
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix
GNU_CONFIGURE=	yes
TK_VER=		8.4
SHORT_TK_VER=	84
CONFIGURE_ARGS=	--enable-shared --with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
		--includedir=${PREFIX}/include/tk${TK_VER}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1
MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}
PLIST_SUB=	TK_VER=${TK_VER} SHORT_TK_VER=${SHORT_TK_VER}
PKGINSTALL=	${PKGDIR}/pkg-install.wish
PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.wish
NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken
TCL84_PORT?=	lang/tcl84
USE_REINPLACE=	YES
MANCOMPRESSED=	no

.ifdef (WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
PKGNAMESUFFIX?=		-threads
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TK84_MAN)

MAN1=	wish.1
MAN3=	3DBorder.3 AddOption.3 BindTable.3 CanvPsY.3 CanvTkwin.3 \
	CanvTxtInfo.3 Clipboard.3 ClrSelect.3 ConfigWidg.3 ConfigWind.3 \
	CoordToWin.3 CrtCmHdlr.3 CrtErrHdlr.3 CrtGenHdlr.3 CrtImgType.3 \
	CrtItemType.3 CrtPhImgFmt.3 CrtSelHdlr.3 CrtWindow.3 DeleteImg.3 \
	DrawFocHlt.3 EventHndlr.3 FindPhoto.3 FontId.3 FreeXId.3 GeomReq.3 \
	GetAnchor.3 GetBitmap.3 GetCapStyl.3 GetClrmap.3 GetColor.3 \
	GetCursor.3 GetDash.3 GetFont.3 GetGC.3 GetHINSTANCE.3 GetHWND.3 \
	GetImage.3 GetJoinStl.3 GetJustify.3 GetOption.3 GetPixels.3 \
	GetPixmap.3 GetRelief.3 GetRootCrd.3 GetScroll.3 GetSelect.3 GetUid.3 \
	GetVRoot.3 GetVisual.3 Grab.3 HWNDToWindow.3 HandleEvent.3 \
	IdToWindow.3 ImgChanged.3 InternAtom.3 MainLoop.3 MainWin.3 \
	MaintGeom.3 ManageGeom.3 MapWindow.3 MeasureChar.3 MoveToplev.3 \
	Name.3 NameOfImg.3 OwnSelect.3 ParseArgv.3 QWinEvent.3 Restack.3 \
	RestrictEv.3 SetAppName.3 SetCaret.3 SetClass.3 SetClassProcs.3 \
	SetGrid.3 SetOptions.3 SetVisual.3 StrictMotif.3 TextLayout.3 \
	Tk_Init.3 Tk_Main.3 TkInitStubs.3 WindowId.3

MANN=	bell.n bind.n bindtags.n bitmap.n button.n canvas.n checkbutton.n \
	chooseColor.n chooseDirectory.n clipboard.n colors.n console.n \
	cursors.n destroy.n dialog.n entry.n event.n focus.n focusNext.n \
	font.n frame.n getOpenFile.n grab.n grid.n keysyms.n image.n label.n \
	labelframe.n listbox.n loadTk.n lower.n menu.n menubar.n menubutton.n \
	message.n messageBox.n option.n optionMenu.n options.n pack-old.n \
	pack.n panedwindow.n palette.n photo.n place.n popup.n radiobutton.n \
	raise.n scale.n scrollbar.n selection.n send.n spinbox.n text.n tk.n \
	tkerror.n tkvars.n tkwait.n toplevel.n winfo.n wm.n

# MLINKS generated via  awk '/ln/ {print "\t" $2,$3,"\\"}' unix/mkLinks
MLINKS=	3DBorder.3 Tk_Alloc3DBorderFromObj.3 \
	3DBorder.3 Tk_Get3DBorder.3 \
	3DBorder.3 Tk_Get3DBorderFromObj.3 \
	3DBorder.3 Tk_Draw3DRectangle.3 \
	3DBorder.3 Tk_Fill3DRectangle.3 \
	3DBorder.3 Tk_Draw3DPolygon.3 \
	3DBorder.3 Tk_Fill3DPolygon.3 \
	3DBorder.3 Tk_3DVerticalBevel.3 \
	3DBorder.3 Tk_3DHorizontalBevel.3 \
	3DBorder.3 Tk_SetBackgroundFromBorder.3 \
	3DBorder.3 Tk_NameOf3DBorder.3 \
	3DBorder.3 Tk_3DBorderColor.3 \
	3DBorder.3 Tk_3DBorderGC.3 \
	3DBorder.3 Tk_Free3DBorderFromObj.3 \
	3DBorder.3 Tk_Free3DBorder.3 \
	AddOption.3 Tk_AddOption.3 \
	BindTable.3 Tk_CreateBindingTable.3 \
	BindTable.3 Tk_DeleteBindingTable.3 \
	BindTable.3 Tk_CreateBinding.3 \
	BindTable.3 Tk_DeleteBinding.3 \
	BindTable.3 Tk_GetBinding.3 \
	BindTable.3 Tk_GetAllBindings.3 \
	BindTable.3 Tk_DeleteAllBindings.3 \
	BindTable.3 Tk_BindEvent.3 \
	CanvPsY.3 Tk_CanvasPsY.3 \
	CanvPsY.3 Tk_CanvasPsBitmap.3 \
	CanvPsY.3 Tk_CanvasPsColor.3 \
	CanvPsY.3 Tk_CanvasPsFont.3 \
	CanvPsY.3 Tk_CanvasPsPath.3 \
	CanvPsY.3 Tk_CanvasPsStipple.3 \
	CanvTkwin.3 Tk_CanvasTkwin.3 \
	CanvTkwin.3 Tk_CanvasGetCoord.3 \
	CanvTkwin.3 Tk_CanvasDrawableCoords.3 \
	CanvTkwin.3 Tk_CanvasSetStippleOrigin.3 \
	CanvTkwin.3 Tk_CanvasWindowCoords.3 \
	CanvTkwin.3 Tk_CanvasEventuallyRedraw.3 \
	CanvTkwin.3 Tk_CanvasTagsOption.3 \
	CanvTxtInfo.3 Tk_CanvasTextInfo.3 \
	Clipboard.3 Tk_ClipboardClear.3 \
	Clipboard.3 Tk_ClipboardAppend.3 \
	ClrSelect.3 Tk_ClearSelection.3 \
	ConfigWidg.3 Tk_ConfigureWidget.3 \
	ConfigWidg.3 Tk_ConfigureInfo.3 \
	ConfigWidg.3 Tk_ConfigureValue.3 \
	ConfigWidg.3 Tk_FreeOptions.3 \
	ConfigWind.3 Tk_ConfigureWindow.3 \
	ConfigWind.3 Tk_MoveWindow.3 \
	ConfigWind.3 Tk_ResizeWindow.3 \
	ConfigWind.3 Tk_MoveResizeWindow.3 \
	ConfigWind.3 Tk_SetWindowBorderWidth.3 \
	ConfigWind.3 Tk_ChangeWindowAttributes.3 \
	ConfigWind.3 Tk_SetWindowBackground.3 \
	ConfigWind.3 Tk_SetWindowBackgroundPixmap.3 \
	ConfigWind.3 Tk_SetWindowBorder.3 \
	ConfigWind.3 Tk_SetWindowBorderPixmap.3 \
	ConfigWind.3 Tk_SetWindowColormap.3 \
	ConfigWind.3 Tk_DefineCursor.3 \
	ConfigWind.3 Tk_UndefineCursor.3 \
	CoordToWin.3 Tk_CoordsToWindow.3 \
	CrtCmHdlr.3 Tk_CreateClientMessageHandler.3 \
	CrtCmHdlr.3 Tk_DeleteClientMessageHandler.3 \
	CrtErrHdlr.3 Tk_CreateErrorHandler.3 \
	CrtErrHdlr.3 Tk_DeleteErrorHandler.3 \
	CrtGenHdlr.3 Tk_CreateGenericHandler.3 \
	CrtGenHdlr.3 Tk_DeleteGenericHandler.3 \
	CrtImgType.3 Tk_CreateImageType.3 \
	CrtImgType.3 Tk_GetImageMasterData.3 \
	CrtImgType.3 Tk_InitImageArgs.3 \
	CrtItemType.3 Tk_CreateItemType.3 \
	CrtItemType.3 Tk_GetItemTypes.3 \
	CrtPhImgFmt.3 Tk_CreatePhotoImageFormat.3 \
	CrtSelHdlr.3 Tk_CreateSelHandler.3 \
	CrtSelHdlr.3 Tk_DeleteSelHandler.3 \
	CrtWindow.3 Tk_CreateWindow.3 \
	CrtWindow.3 Tk_CreateWindowFromPath.3 \
	CrtWindow.3 Tk_DestroyWindow.3 \
	CrtWindow.3 Tk_MakeWindowExist.3 \
	DeleteImg.3 Tk_DeleteImage.3 \
	DrawFocHlt.3 Tk_DrawFocusHighlight.3 \
	EventHndlr.3 Tk_CreateEventHandler.3 \
	EventHndlr.3 Tk_DeleteEventHandler.3 \
	FindPhoto.3 Tk_FindPhoto.3 \
	FindPhoto.3 Tk_PhotoPutBlock.3 \
	FindPhoto.3 Tk_PhotoPutZoomedBlock.3 \
	FindPhoto.3 Tk_PhotoGetImage.3 \
	FindPhoto.3 Tk_PhotoBlank.3 \
	FindPhoto.3 Tk_PhotoExpand.3 \
	FindPhoto.3 Tk_PhotoGetSize.3 \
	FindPhoto.3 Tk_PhotoSetSize.3 \
	FontId.3 Tk_FontId.3 \
	FontId.3 Tk_GetFontMetrics.3 \
	FontId.3 Tk_PostscriptFontName.3 \
	FreeXId.3 Tk_FreeXId.3 \
	GeomReq.3 Tk_GeometryRequest.3 \
	GeomReq.3 Tk_SetMinimumRequestSize.3 \
	GeomReq.3 Tk_SetInternalBorder.3 \
	GeomReq.3 Tk_SetInternalBorderEx.3 \
	GetAnchor.3 Tk_GetAnchorFromObj.3 \
	GetAnchor.3 Tk_GetAnchor.3 \
	GetAnchor.3 Tk_NameOfAnchor.3 \
	GetBitmap.3 Tk_AllocBitmapFromObj.3 \
	GetBitmap.3 Tk_GetBitmap.3 \
	GetBitmap.3 Tk_GetBitmapFromObj.3 \
	GetBitmap.3 Tk_DefineBitmap.3 \
	GetBitmap.3 Tk_NameOfBitmap.3 \
	GetBitmap.3 Tk_SizeOfBitmap.3 \
	GetBitmap.3 Tk_FreeBitmapFromObj.3 \
	GetBitmap.3 Tk_FreeBitmap.3 \
	GetCapStyl.3 Tk_GetCapStyle.3 \
	GetCapStyl.3 Tk_NameOfCapStyle.3 \
	GetClrmap.3 Tk_GetColormap.3 \
	GetClrmap.3 Tk_FreeColormap.3 \
	GetColor.3 Tk_AllocColorFromObj.3 \
	GetColor.3 Tk_GetColor.3 \
	GetColor.3 Tk_GetColorFromObj.3 \
	GetColor.3 Tk_GetColorByValue.3 \
	GetColor.3 Tk_NameOfColor.3 \
	GetColor.3 Tk_FreeColorFromObj.3 \
	GetColor.3 Tk_FreeColor.3 \
	GetCursor.3 Tk_AllocCursorFromObj.3 \
	GetCursor.3 Tk_GetCursor.3 \
	GetCursor.3 Tk_GetCursorFromObj.3 \
	GetCursor.3 Tk_GetCursorFromData.3 \
	GetCursor.3 Tk_NameOfCursor.3 \
	GetCursor.3 Tk_FreeCursorFromObj.3 \
	GetCursor.3 Tk_FreeCursor.3 \
	GetDash.3 Tk_GetDash.3 \
	GetFont.3 Tk_AllocFontFromObj.3 \
	GetFont.3 Tk_GetFont.3 \
	GetFont.3 Tk_GetFontFromObj.3 \
	GetFont.3 Tk_NameOfFont.3 \
	GetFont.3 Tk_FreeFontFromObj.3 \
	GetFont.3 Tk_FreeFont.3 \
	GetGC.3 Tk_GetGC.3 \
	GetGC.3 Tk_FreeGC.3 \
	GetHINSTANCE.3 Tk_GetHINSTANCE.3 \
	GetHWND.3 Tk_GetHWND.3 \
	GetImage.3 Tk_GetImage.3 \
	GetImage.3 Tk_RedrawImage.3 \
	GetImage.3 Tk_SizeOfImage.3 \
	GetImage.3 Tk_FreeImage.3 \
	GetJoinStl.3 Tk_GetJoinStyle.3 \
	GetJoinStl.3 Tk_NameOfJoinStyle.3 \
	GetJustify.3 Tk_GetJustifyFromObj.3 \
	GetJustify.3 Tk_GetJustify.3 \
	GetJustify.3 Tk_NameOfJustify.3 \
	GetOption.3 Tk_GetOption.3 \
	GetPixels.3 Tk_GetPixelsFromObj.3 \
	GetPixels.3 Tk_GetPixels.3 \
	GetPixels.3 Tk_GetMMFromObj.3 \
	GetPixels.3 Tk_GetScreenMM.3 \
	GetPixmap.3 Tk_GetPixmap.3 \
	GetPixmap.3 Tk_FreePixmap.3 \
	GetRelief.3 Tk_GetReliefFromObj.3 \
	GetRelief.3 Tk_GetRelief.3 \
	GetRelief.3 Tk_NameOfRelief.3 \
	GetRootCrd.3 Tk_GetRootCoords.3 \
	GetScroll.3 Tk_GetScrollInfo.3 \
	GetScroll.3 Tk_GetScrollInfoObj.3 \
	GetSelect.3 Tk_GetSelection.3 \
	GetUid.3 Tk_GetUid.3 \
	GetUid.3 Tk_Uid.3 \
	GetVRoot.3 Tk_GetVRootGeometry.3 \
	GetVisual.3 Tk_GetVisual.3 \
	Grab.3 Tk_Grab.3 \
	Grab.3 Tk_Ungrab.3 \
	HWNDToWindow.3 Tk_HWNDToWindow.3 \
	HandleEvent.3 Tk_HandleEvent.3 \
	IdToWindow.3 Tk_IdToWindow.3 \
	ImgChanged.3 Tk_ImageChanged.3 \
	InternAtom.3 Tk_InternAtom.3 \
	InternAtom.3 Tk_GetAtomName.3 \
	MainLoop.3 Tk_MainLoop.3 \
	MainWin.3 Tk_MainWindow.3 \
	MainWin.3 Tk_GetNumMainWindows.3 \
	MaintGeom.3 Tk_MaintainGeometry.3 \
	MaintGeom.3 Tk_UnmaintainGeometry.3 \
	ManageGeom.3 Tk_ManageGeometry.3 \
	MapWindow.3 Tk_MapWindow.3 \
	MapWindow.3 Tk_UnmapWindow.3 \
	MeasureChar.3 Tk_MeasureChars.3 \
	MeasureChar.3 Tk_TextWidth.3 \
	MeasureChar.3 Tk_DrawChars.3 \
	MeasureChar.3 Tk_UnderlineChars.3 \
	MoveToplev.3 Tk_MoveToplevelWindow.3 \
	Name.3 Tk_Name.3 \
	Name.3 Tk_PathName.3 \
	Name.3 Tk_NameToWindow.3 \
	NameOfImg.3 Tk_NameOfImage.3 \
	OwnSelect.3 Tk_OwnSelection.3 \
	ParseArgv.3 Tk_ParseArgv.3 \
	QWinEvent.3 Tk_CollapseMotionEvents.3 \
	QWinEvent.3 Tk_QueueWindowEvent.3 \
	Restack.3 Tk_RestackWindow.3 \
	RestrictEv.3 Tk_RestrictEvents.3 \
	SetAppName.3 Tk_SetAppName.3 \
	SetCaret.3 Tk_SetCaretPos.3 \
	SetClass.3 Tk_SetClass.3 \
	SetClass.3 Tk_Class.3 \
	SetClassProcs.3 Tk_SetClassProcs.3 \
	SetGrid.3 Tk_SetGrid.3 \
	SetGrid.3 Tk_UnsetGrid.3 \
	SetOptions.3 Tk_CreateOptionTable.3 \
	SetOptions.3 Tk_DeleteOptionTable.3 \
	SetOptions.3 Tk_InitOptions.3 \
	SetOptions.3 Tk_SetOptions.3 \
	SetOptions.3 Tk_FreeSavedOptions.3 \
	SetOptions.3 Tk_RestoreSavedOptions.3 \
	SetOptions.3 Tk_GetOptionValue.3 \
	SetOptions.3 Tk_GetOptionInfo.3 \
	SetOptions.3 Tk_FreeConfigOptions.3 \
	SetOptions.3 Tk_Offset.3 \
	SetVisual.3 Tk_SetWindowVisual.3 \
	StrictMotif.3 Tk_StrictMotif.3 \
	TextLayout.3 Tk_ComputeTextLayout.3 \
	TextLayout.3 Tk_FreeTextLayout.3 \
	TextLayout.3 Tk_DrawTextLayout.3 \
	TextLayout.3 Tk_UnderlineTextLayout.3 \
	TextLayout.3 Tk_PointToChar.3 \
	TextLayout.3 Tk_CharBbox.3 \
	TextLayout.3 Tk_DistanceToTextLayout.3 \
	TextLayout.3 Tk_IntersectTextLayout.3 \
	TextLayout.3 Tk_TextLayoutToPostscript.3 \
	TkInitStubs.3 Tk_InitStubs.3 \
	Tk_Init.3 Tk_SafeInit.3 \
	WindowId.3 Tk_WindowId.3 \
	WindowId.3 Tk_Parent.3 \
	WindowId.3 Tk_Display.3 \
	WindowId.3 Tk_DisplayName.3 \
	WindowId.3 Tk_ScreenNumber.3 \
	WindowId.3 Tk_Screen.3 \
	WindowId.3 Tk_X.3 \
	WindowId.3 Tk_Y.3 \
	WindowId.3 Tk_Width.3 \
	WindowId.3 Tk_Height.3 \
	WindowId.3 Tk_Changes.3 \
	WindowId.3 Tk_Attributes.3 \
	WindowId.3 Tk_IsContainer.3 \
	WindowId.3 Tk_IsEmbedded.3 \
	WindowId.3 Tk_IsMapped.3 \
	WindowId.3 Tk_IsTopLevel.3 \
	WindowId.3 Tk_ReqWidth.3 \
	WindowId.3 Tk_ReqHeight.3 \
	WindowId.3 Tk_MinReqWidth.3 \
	WindowId.3 Tk_MinReqHeight.3 \
	WindowId.3 Tk_InternalBorderLeft.3 \
	WindowId.3 Tk_InternalBorderRight.3 \
	WindowId.3 Tk_InternalBorderTop.3 \
	WindowId.3 Tk_InternalBorderBottom.3 \
	WindowId.3 Tk_Visual.3 \
	WindowId.3 Tk_Depth.3 \
	WindowId.3 Tk_Colormap.3 \
	chooseColor.n tk_chooseColor.n \
	chooseDirectory.n tk_chooseDirectory.n \
	dialog.n tk_dialog.n \
	focusNext.n tk_focusNext.n \
	focusNext.n tk_focusPrev.n \
	focusNext.n tk_focusFollowsMouse.n \
	getOpenFile.n tk_getOpenFile.n \
	getOpenFile.n tk_getSaveFile.n \
	menu.n tk_menuSetFocus.n \
	menubar.n tk_menuBar.n \
	menubar.n tk_bindForTraversal.n \
	messageBox.n tk_messageBox.n \
	optionMenu.n tk_optionMenu.n \
	palette.n tk_setPalette.n \
	palette.n tk_bisque.n \
	popup.n tk_popup.n \
	text.n tk_textCopy.n \
	text.n tk_textCut.n \
	text.n tk_textPaste.n

.endif

TKBASE?=	${PORTSDIR}/${PKGCATEGORY}/${LATEST_LINK}

pre-everything::
	@if ${TEST} -e "${NONEXISTENT}"; then ${ECHO_MSG} "=== Aborted, please remove ${NONEXISTENT}"; exit 1; fi

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} \
		-e 's|${WRKDIRPREFIX}${.CURDIR}|$${WRKDIRPREFIX}${TKBASE}|' \
		${WRKSRC}/tkConfig.sh
.if defined(WITHOUT_TK84_MAN)
	${REINPLACE_CMD} -e 's|^MAN_INSTALL_DIR.*$$|MAN_INSTALL_DIR = ${WRKDIR}|' \
		${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/tk${TK_VER}/
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.post.mk>
