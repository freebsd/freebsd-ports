# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	icewm
PORTVERSION=	1.3.8
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Manager designed for speed, usability and consistency

LICENSE=	GPLv2

USES=		gmake iconv pkgconfig
USE_XORG=	ice sm x11 xext
USE_GNOME=	gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-guievents \
		--with-cfgdir=${DATADIR} \
		--with-libdir=${DATADIR} \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc \
		--with-mkfontdir=${NONEXISTENT}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		BEASTIE ESOUND GNOME LITE MENUFIX NLS XFT XINERAMA \
			XRANDR DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	BEASTIE MENUFIX NLS XFT XINERAMA XRANDR
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_SUB=		yes

BEASTIE_DESC=		Use Beastie'fied startup button
ESOUND_USE=		GNOME=esound
ESOUND_CONFIGURE_ON=	--with-icesound=esound
ESOUND_CONFIGURE_OFF=	--with-icesound=oss
GNOME_DESC=		Display GNOME 2 menus
GNOME_USE=		GNOME=gnomedesktop,libgnomeui
GNOME_CONFIGURE_ENABLE=	menus-gnome2
LITE_CONFIGURE_ENABLE=	lite
MENUFIX_DESC=		MenuIconSize fix
MENUFIX_EXTRA_PATCHES=	${FILESDIR}/extra-menu-icon-fix.patch
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
XFT_LIB_DEPENDS=	libXft.so:${PORTSDIR}/x11-fonts/libXft
XFT_CONFIGURE_OFF=	--enable-corefonts --disable-xfreetype
XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_ENABLE=	xinerama
XRANDR_USE=		XORG=xrandr
XRANDR_CONFIGURE_ENABLE=	xrandr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=--enable-x86-asm
.else
CONFIGURE_ARGS+=--disable-x86-asm
.endif

.if ${PORT_OPTIONS:MBEASTIE}
STARTUP_PIXMAP=	${DATADIR}/taskbar/bsd-daemon.xpm
.else
STARTUP_PIXMAP=	icewm-logo.xpm
.endif

.if ${PORT_OPTIONS:MLITE}
PLIST_SUB+=	NOLITE="@comment "
.else
PLIST_SUB+=	NOLITE=""
.endif

post-extract:
.for dir in taskbar themes/Infadel2/taskbar
	@cd ${WRKSRC}/lib/${dir} && ${MV} start.xpm icewm-logo.xpm
.endfor
	@${CP} -f ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/share/control|${LOCALBASE}/share/control|g ; \
		 s|/usr/share/app|${LOCALBASE}/share/app|g ; \
		 s|/usr/share/gnome|${LOCALBASE}/share/gnome|g' \
		 ${WRKSRC}/src/gnome2.cc
	@${REINPLACE_CMD} -e \
		's|SHELL=.*|SHELL=@SHELL@| ; \
		 s|icewm-set-gnomewm||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|icewm-$$(VERSION)|icewm| ; \
		 s|`pkg-config fontconfig --cflags`|| ; \
		 s|`pkg-config fontconfig --libs`|| ; \
		 /@echo/s|^|#| ; \
		 s|@$$(|$$(|' ${WRKSRC}/src/Makefile.in

post-install:
.for dir in taskbar themes/Infadel2/taskbar
	@${LN} -s ${STARTUP_PIXMAP} ${STAGEDIR}${DATADIR}/${dir}/start.xpm
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in CHANGES INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
