# New ports collection makefile for:	icewm
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm
PORTVERSION=	1.2.30
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Window Manager designed for speed, usability and consistency

WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-shaped-decorations \
		--enable-guievents \
		--with-cfgdir=${DATADIR} \
		--with-libdir=${DATADIR} \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc \
		--with-mkfontdir=${NONEXISTENT}

OPTIONS=	GNOMEDESKTOP	"Enable GNOME desktop support"		off \
		IMLIB		"Build with Imlib support"		on \
		ESOUND		"Enable EsounD daemon support"		off \
		XFT		"Enable Xft support for fonts"		on \
		XINERAMA	"Enable Xinerama support"		on \
		X86_ASM		"Use optimized x86 assembly code"	on \
		BEASTIE		"Use Beastie'fied startup button"	off \
		NLS		"Enable National Language Support"	on

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomedesktop}!="" || defined(WITH_GNOMEDESKTOP)
USE_GNOME+=	gnomedesktop
CONFIGURE_ARGS+=	--enable-menus-gnome2
INSTALL_TARGET=		install install-gnome
PLIST_SUB+=	GNOMEDESKTOP=""
PKGNAMESUFFIX=	-gnome
.else
PLIST_SUB+=	GNOMEDESKTOP="@comment "
.endif

.if ${HAVE_GNOME:Mimlib}!="" || defined(WITH_IMLIB)
USE_GNOME+=	imlib
CONFIGURE_ARGS+=	--with-imlib
.else
USE_XPM=	yes
CONFIGURE_ARGS+=	--without-imlib
.endif

.if ${HAVE_GNOME:Mesound}!="" || defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-icesound=esound
.else
CONFIGURE_ARGS+=	--with-icesound=oss
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3 || defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-corefonts --disable-xfreetype
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-gradients
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3 || defined(WITHOUT_XINERAMA)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
CONFIGURE_ARGS+=	--disable-x86-asm
.endif

.if defined(WITH_BEASTIE)
STARTUP_PIXMAP=		${DATADIR}/taskbar/bsd-daemon.xpm
.else
STARTUP_PIXMAP=		icewm-logo.xpm
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls --disable-i18n
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@cd ${WRKSRC}/lib/taskbar && ${MV} start.xpm icewm-logo.xpm
.for dir in Infadel2
	@cd ${WRKSRC}/lib/themes/${dir}/taskbar && ${MV} start.xpm icewm-logo.xpm
.endfor
	@${CP} -f ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

post-patch:
.for file in configure
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/${file}
.endfor
.for file in src/gnome2.cc
	@${REINPLACE_CMD} -e \
		's|/usr/share/control|${LOCALBASE}/share/gnome/control|g ; \
		 s|/usr/share/app|${LOCALBASE}/share/gnome/app|g ; \
		 s|/usr/share/gnome|${LOCALBASE}/share/gnome|g' ${WRKSRC}/${file}
.endfor

post-install:
	@${LN} -sf ${STARTUP_PIXMAP} ${DATADIR}/taskbar/start.xpm
.for dir in Infadel2
	@${LN} -sf ${STARTUP_PIXMAP} \
		${DATADIR}/themes/${dir}/taskbar/start.xpm
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
