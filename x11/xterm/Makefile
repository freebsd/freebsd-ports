# Created by: krion
# $FreeBSD$

PORTNAME=	xterm
PORTVERSION=	348
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.invisible-island.net/xterm/:src1 \
		https://invisible-mirror.net/archives/xterm/:src1 \
		LOCAL/ehaupt:src1 LOCAL/ehaupt:src2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src1 \
		bsd-xterm-icons-${ICONVERSION}${EXTRACT_SUFX}:src2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe ncurses tar:tgz
USE_XORG=	xft xmu xt x11 xext xpm ice

GNU_CONFIGURE=	yes

CPE_VENDOR=	invisible-island

CONFIGURE_ARGS+=	--with-utempter --enable-narrowproto

CONFLICTS=	x11iraf-[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

ICONVERSION=	1

OPTIONS_DEFINE=	WCHAR LUIT DECTERM PCRE DABBREV 256COLOR SIXEL GNOME LOGGING \
		SCRNDUMP REGIS TOOLBAR XINERAMA
OPTIONS_RADIO=	3D
OPTIONS_RADIO_3D=	XAW3D XAW3DXFT NEXTAW

DABBREV_DESC=	Enable support for dabbrev-expand
DECTERM_DESC=	Enable DECterm Locator support
LUIT_DESC=	Use LUIT for locale convertion from/to UTF-8
SIXEL_DESC=	Enable Sixel graphics support
REGIS_DESC=	Enable ReGIS graphics support
WCHAR_DESC=	Enable wide-character support
256COLOR_DESC=	Enable 256-color support
LOGGING_DESC=	Enable logging terminal I/O to a file
XAW3D_DESC=	Link with Xaw 3d library
XAW3DXFT_DESC=	Link with Xaw 3d xft (extended fonts) library
NEXTAW_DESC=	Link with neXT Athena library
SCRNDUMP_DESC=	Enable XHTML and SVG screen dumps
TOOLBAR_DESC=	Enable pulldown menus with a toolbar

OPTIONS_DEFAULT=WCHAR LUIT 256COLOR

256COLOR_CONFIGURE_ENABLE=	256-color
LUIT_BUILD_DEPENDS=		luit:x11/luit
LUIT_CONFIGURE_ENABLE=		luit
LUIT_IMPLIES=			WCHAR
WCHAR_CONFIGURE_ENABLE=		wide-chars
WCHAR_VARS=			PKGMESSAGE="${PKGDIR}/pkg-message.wchar"
DECTERM_CONFIGURE_ENABLE=	dec-locator
PCRE_CONFIGURE_WITH=		pcre
PCRE_LIB_DEPENDS=		libpcre.so:devel/pcre
DABBREV_CONFIGURE_ENABLE=	dabbrev
SIXEL_CONFIGURE_ENABLE=		sixel-graphics
REGIS_CONFIGURE_ENABLE=		regis-graphics
GNOME_USES=			desktop-file-utils
LOGGING_CONFIGURE_ENABLE=	logging
SCRNDUMP_CONFIGURE_ENABLE=	screen-dumps
XAW3D_CONFIGURE_WITH=		Xaw3d
XAW3D_LIB_DEPENDS=		libXaw3d.so:x11-toolkits/Xaw3d
XAW3DXFT_CONFIGURE_WITH=	Xaw3dxft
XAW3DXFT_LIB_DEPENDS=		libXaw3dxft.so:x11-toolkits/libxaw3dxft
NEXTAW_CONFIGURE_WITH=		neXtaw
NEXTAW_LIB_DEPENDS=		libneXtaw.so:x11-toolkits/neXtaw
TOOLBAR_CONFIGURE_ENABLE=	toolbar
WCHAR_LIB_DEPENDS=		libfreetype.so:print/freetype2
XINERAMA_USE=			XORG=xinerama,xorgproto
XINERAMA_CONFIGURE_OFF=		--without-xinerama

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MXAW3D} && ! ${PORT_OPTIONS:MXAW3DXFT} && ! ${PORT_OPTIONS:MNEXTAW}
USE_XORG+=	xaw
.endif

post-extract:
	@${CP} ${WRKDIR}/bsd-xterm-icons-1/*.png \
		${WRKDIR}/bsd-xterm-icons-1/*.xpm \
			${WRKSRC}/icons/

post-install:
.for f in koi8rxterm resize uxterm xterm
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/xterm.desktop \
		${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
