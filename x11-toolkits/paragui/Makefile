# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	0.6.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.bms-austria.com/pub/paragui/release/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_ttf.2:${PORTSDIR}/graphics/sdl_ttf

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

USE_GMAKE=	yes

PLIST_SUB=	PORTVER=${PORTVERSION}

INSTALLS_SHLIB=	yes

MAN3=	MSG_MESSAGE.3 PARAGUI_EVENTHANDLERDATA.3 SDLApplication.3 \
	SDLButton.3 SDLButtonGroup.3 SDLCheckButton.3 SDLColumnItem.3 \
	SDLDrawObject.3 SDLGradientWidget.3 SDLLabel.3 SDLLineEdit.3 \
	SDLListBox.3 SDLListBoxBaseItem.3 SDLListBoxItem.3 \
	SDLMessageObject.3 SDLProgressBar.3 SDLRadioButton.3 SDLScrollBar.3 \
	SDLScrollBar__ScrollButton.3 SDLSlider.3 SDLStaticFrame.3 SDLTheme.3 \
	SDLUserButton.3 SDLWidget.3 SDLWidgetDnD.3 SDLWidgetList.3 \
	SDLWindow.3 SDL_Gradient.3 SDL_Point.3 bresenham_h.3 paragui_h.3 \
	paragui_msgmap_h.3 paragui_types_h.3 parastretch_h.3 \
	rendertextrect_h.3 sdlapplication_h.3 sdlbutton_h.3 \
	sdlbuttongroup_h.3 sdlcheckbutton_h.3 sdlcolumnitem_h.3 \
	sdldrawobject_h.3 sdlgradientwidget_h.3 sdllabel_h.3 sdllineedit_h.3 \
	sdllistbox_h.3 sdllistboxbaseitem_h.3 sdllistboxitem_h.3 \
	sdlmessageobject_h.3 sdlprogressbar_h.3 sdlradiobutton_h.3 \
	sdlscrollbar_h.3 sdlslider_h.3 sdlstaticframe_h.3 sdlwidget_h.3 \
	sdlwidgetdnd_h.3 sdlwidgetlist_h.3 sdlwindow_h.3 theme_h.3

.include <bsd.port.mk>
