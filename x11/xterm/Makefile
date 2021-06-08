# Created by: krion

PORTNAME=	xterm
PORTVERSION=	368
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.invisible-island.net/xterm/:src1 \
		https://invisible-mirror.net/archives/xterm/:src1 \
		LOCAL/ehaupt:src1 \
		LOCAL/ehaupt:src2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src1 \
		bsd-xterm-icons-${ICONVERSION}${EXTRACT_SUFX}:src2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig

USES=			cpe localbase ncurses tar:tgz xorg
CPE_VENDOR=		invisible-island
USE_XORG=		ice x11 xext xft xmu xpm xt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-narrowproto \
			--with-utempter

CPPFLAGS+=	-DPIXMAP_ROOTDIR=${LOCALBASE}/share/pixmaps

CONFLICTS=	x11iraf-[0-9]*

OPTIONS_DEFINE=		256COLOR DABBREV DECTERM GNOME LOGGING LUIT PCRE2 REGIS \
			SCRNDUMP SIXEL TOOLBAR WCHAR XINERAMA
OPTIONS_DEFAULT=	256COLOR LUIT SIXEL WCHAR
OPTIONS_RADIO=		3D
OPTIONS_RADIO_3D=	NEXTAW XAW3D XAW3DXFT

256COLOR_DESC=	Enable 256-color support
DABBREV_DESC=	Enable support for dabbrev-expand
DECTERM_DESC=	Enable DECterm Locator support
LOGGING_DESC=	Enable logging terminal I/O to a file
LUIT_DESC=	Use LUIT for locale convertion from/to UTF-8
NEXTAW_DESC=	Link with neXT Athena library
PCRE2_DESC=	${PCRE_DESC} version 2
REGIS_DESC=	Enable ReGIS graphics support
SCRNDUMP_DESC=	Enable XHTML and SVG screen dumps
SIXEL_DESC=	Enable Sixel graphics support
TOOLBAR_DESC=	Enable pulldown menus with a toolbar
WCHAR_DESC=	Enable wide-character support
XAW3DXFT_DESC=	Link with Xaw 3d xft (extended fonts) library
XAW3D_DESC=	Link with Xaw 3d library

256COLOR_CONFIGURE_ENABLE=	256-color
DABBREV_CONFIGURE_ENABLE=	dabbrev
DECTERM_CONFIGURE_ENABLE=	dec-locator
GNOME_USES=			desktop-file-utils
LOGGING_CONFIGURE_ENABLE=	logging
LUIT_IMPLIES=			WCHAR
LUIT_BUILD_DEPENDS=		luit:x11/luit
LUIT_CONFIGURE_ENABLE=		luit
NEXTAW_LIB_DEPENDS=		libneXtaw.so:x11-toolkits/neXtaw
NEXTAW_CONFIGURE_WITH=		neXtaw
PCRE2_LIB_DEPENDS=		libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=		pcre2
REGIS_CONFIGURE_ENABLE=		regis-graphics
SCRNDUMP_CONFIGURE_ENABLE=	screen-dumps
SIXEL_CONFIGURE_ENABLE=		sixel-graphics
TOOLBAR_CONFIGURE_ENABLE=	toolbar
WCHAR_LIB_DEPENDS=		libfreetype.so:print/freetype2
WCHAR_CONFIGURE_ENABLE=		wide-chars
WCHAR_VARS=			PKGMESSAGE="${PKGDIR}/pkg-message.wchar"
XAW3DXFT_LIB_DEPENDS=		libXaw3dxft.so:x11-toolkits/libxaw3dxft
XAW3DXFT_CONFIGURE_WITH=	Xaw3dxft
XAW3D_LIB_DEPENDS=		libXaw3d.so:x11-toolkits/Xaw3d
XAW3D_CONFIGURE_WITH=		Xaw3d
XINERAMA_USE=			XORG=xinerama,xorgproto
XINERAMA_CONFIGURE_OFF=		--without-xinerama

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MXAW3D} && ! ${PORT_OPTIONS:MXAW3DXFT} && ! ${PORT_OPTIONS:MNEXTAW}
USE_XORG+=	xaw
.endif

ICONVERSION=	1

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
