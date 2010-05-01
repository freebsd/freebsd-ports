# New ports collection makefile for:   libXcursor
# Date Created:			22 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXcursor
PORTVERSION=	1.1.10
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library

XORG_CAT=	lib
USE_XORG=	xrender x11 xfixes fixesproto xproto:both \
		xextproto

CONFIGURE_ARGS=	--with-icondir=${PREFIX}/lib/X11/icons

MAN3=		Xcursor.3 \
		XcursorImageCreate.3 \
		XcursorImageDestroy.3 \
		XcursorImagesCreate.3 \
		XcursorImagesDestroy.3 \
		XcursorCursorsCreate.3 \
		XcursorCursorsDestroy.3 \
		XcursorXcFileLoadImage.3 \
		XcursorXcFileLoadImages.3 \
		XcursorXcFileLoadAllImages.3 \
		XcursorXcFileLoad.3 \
		XcursorXcFileSave.3 \
		XcursorFilenameLoadImage.3 \
		XcursorFilenameLoadImages.3 \
		XcursorFilenameLoadAllImages.3 \
		XcursorFilenameLoad.3 \
		XcursorFilenameSaveImages.3 \
		XcursorFilenameSave.3 \
		XcursorLibraryLoadImage.3 \
		XcursorLibraryLoadImages.3 \
		XcursorFilenameLoadCursor.3 \
		XcursorLibraryLoadCursor.3 \
		XcursorLibraryLoadCursors.3 \
		XcursorShapeLoadImage.3 \
		XcursorShapeLoadImages.3 \
		XcursorShapeLoadCursor.3 \
		XcursorShapeLoadCursors.3 \
		XcursorSupportsARGB.3 \
		XcursorSetDefaultSize.3 \
		XcursorGetDefaultSize.3 \
		XcursorSetTheme.3 \
		XcursorGetTheme.3

.include <bsd.port.mk>
