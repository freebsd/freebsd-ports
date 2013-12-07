# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	icewm
PORTVERSION=	1.3.7
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Window Manager designed for speed, usability and consistency

LICENSE=	GPLv2

WANT_GNOME=	yes
USE_XORG=	x11 ice xinerama xext xrandr sm
USE_GNOME=	gtk20 # gdkpixbuf really :-)
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake pkgconfig
CONFIGURE_ARGS=	--enable-shaped-decorations \
		--enable-guievents \
		--with-cfgdir=${DATADIR} \
		--with-libdir=${DATADIR} \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc \
		--with-mkfontdir=${NONEXISTENT}

OPTIONS_DEFINE=	GNOME ESOUND XFT XINERAMA ASM BEASTIE NLS LITE MENUFIX
OPTIONS_DEFAULT=	XFT XINERAMA ASM BEASTIE NLS MENUFIX
BEASTIE_DESC=	Use Beastie'fied startup button
MENUFIX_DESC=	MenuIconSize fix

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomedesktop libgnomeui
CONFIGURE_ARGS+=--enable-menus-gnome2
INSTALL_TARGET=	install
PLIST_SUB+=	GNOMEDESKTOP=""
.else
PLIST_SUB+=	GNOMEDESKTOP="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=--with-icesound=esound
.else
CONFIGURE_ARGS+=--with-icesound=oss
.endif

.if ${PORT_OPTIONS:MXFT}
LIB_DEPENDS+=	Xft:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=--enable-gradients
.else
CONFIGURE_ARGS+=--enable-corefonts --disable-xfreetype
.endif

.if empty(PORT_OPTIONS:MXINERAMA)
CONFIGURE_ARGS+=--disable-xinerama
.endif

.if ${ARCH} == "i386" && ${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=--enable-x86-asm
.else
CONFIGURE_ARGS+=--disable-x86-asm
.endif

.if ${PORT_OPTIONS:MBEASTIE}
STARTUP_PIXMAP=	${DATADIR}/taskbar/bsd-daemon.xpm
.else
STARTUP_PIXMAP=	icewm-logo.xpm
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls --disable-i18n
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MLITE}
MAKE_ENV+=	LITE=1
.endif

.if ${PORT_OPTIONS:MMENUFIX}
EXTRA_PATCHES+=	${FILESDIR}/extra-menu-icon-fix.patch
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

post-configure:
	${REINPLACE_CMD} -e 's|icewm-set-gnomewm||g' ${WRKSRC}/Makefile

post-install:
.for dir in taskbar themes/Infadel2/taskbar
	@${LN} -s ${STARTUP_PIXMAP} ${STAGEDIR}${DATADIR}/${dir}/start.xpm
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in CHANGES INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
