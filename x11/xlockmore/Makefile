# Created by: Scott Mace <smace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlockmore
PORTVERSION=	5.55
PORTREVISION=	1
CATEGORIES?=	x11
MASTER_SITES=	http://www.sillycycle.com/xlock/ \
		LOCAL/jgh/x11/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Like XLock session locker/screen saver, but just more

LICENSE=	BSD2CLAUSE

USES=		tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-motif --without-ttf --without-editres \
		--without-dtsaver --without-rplay --without-nas \
		--without-gtk --without-esound --disable-setuid

USE_GNOME=	#
USE_XORG=	x11 xaw ice sm xpm xext xinerama

LIB_DEPENDS+=	libfreetype.so:print/freetype2

OPTIONS_DEFINE=	MESAGL MB SYSLOG DISABLE_ALLOW_ROOT NICE_ONLY BLANK_ONLY \
		KERBEROS4 BAD_PAM GTK2 TIME_BOMB CUSTOMIZATION MAGICK JP \
		XINERAMA
OPTIONS_DEFAULT=	XINERAMA
OPTIONS_SUB=	yes

MESAGL_DESC=	Mesa 3D (for GL modes)
MB_DESC=	Xmb function series
SYSLOG_DESC=	Syslog logging
DISABLE_ALLOW_ROOT_DESC=	Allows users to turn off allowroot
NICE_ONLY_DESC=	Only low cpu modes
BLANK_ONLY_DESC=	Blank mode only (boring)
BAD_PAM_DESC=	Xlock will ask PAM with root rights
GTK2_DESC=	Build Gtk2 graphical shell
XLOCK_GROUP_DESC=	Allow xlock group to logout
TIME_BOMB_DESC=	Allow autologout
CUSTOMIZATION_DESC=	Allow tune through resource file
JP_DESC=	Japanese Language Support

OPTIONS_RADIO=	ONE
OPTIONS_RADIO_ONE=	PAM XLOCK_GROUP

NO_OPTIONS_SORT=yes

JP_IMPLIES=	MB

MAKE_ARGS+=	bindir=${PREFIX}/bin \
		mandir=${PREFIX}/man/man1 \
		datarootdir=${PREFIX}/share \
		xapploaddir=${PREFIX}/lib/X11/app-defaults

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS4}
CONFIGURE_ARGS+=--enable-kerberos4
KRB4LIB=	-lcom_err -lcrypto
.endif
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--enable-kerberos5
CFLAGS+=	-I${KRB5_HOME}/include
KRB5LIB=	-L${KRB5_HOME}/lib
.endif

.if ${PORT_OPTIONS:MMESAGL}
CONFIGURE_ARGS+=	--with-mesa
MESALIB=	-lpthread
USE_GL=		yes
LIB_DEPENDS+=	libftgl.so:graphics/ftgl
CFLAGS+=	-I${LOCALBASE}/include/FTGL -I${LOCALBASE}/include/freetype2
.else
CONFIGURE_ARGS+=	--without-mesa --without-opengl --without-ftgl
.endif

.if ${PORT_OPTIONS:MNICE_ONLY}
CONFIGURE_ARGS+=	--enable-nice-only
.endif

.if ${PORT_OPTIONS:MBAD_PAM}
CONFIGURE_ARGS+=	--enable-bad-pam
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam
.endif

.if ${PORT_OPTIONS:MNICE_ONLY}
CONFIGURE_ARGS+=	--enable-nice-only
.endif

.if ${PORT_OPTIONS:MBLANK_ONLY}
CONFIGURE_ARGS+=	--enable-blank-only
.endif

.if ${PORT_OPTIONS:MMB}
CONFIGURE_ARGS+=	--enable-use-mb
.endif

.if ${PORT_OPTIONS:MJP}
XLOCKMORE_LANG=	ja
CATEGORIES+=	japanese
.endif

.if defined(XLOCKMORE_LANG)
CONFIGURE_ARGS+=	--with-lang=${XLOCKMORE_LANG}
.endif

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--with-gtk2
USE_GNOME+=	gtk20
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if ${PORT_OPTIONS:MXLOCK_GROUP}
CONFIGURE_ARGS+=	--enable-xlock-group
.endif

.if ${PORT_OPTIONS:MTIME_BOMB}
CONFIGURE_ARGS+=	--enable-bomb
.else
CONFIGURE_ARGS+=	--disable-bomb
.endif

.if ${PORT_OPTIONS:MCUSTOMIZATION}
CONFIGURE_ARGS+=	--enable-customization
.endif

.if ${PORT_OPTIONS:MMAGICK}
LIB_DEPENDS+=	libMagickCore-6.so:graphics/ImageMagick6
.else
CONFIGURE_ARGS+=	--without-magick
.endif

CONFIGURE_ENV+=		XLOCKLIBS="${KRB5LIB} ${KRB4LIB} ${MESALIB}"

.if ${PORT_OPTIONS:MDISABLE_ALLOW_ROOT}
CONFIGURE_ARGS+=	--disable-allow-root
.endif

.if ${PORT_OPTIONS:MXINERAMA}
CONFIGURE_ARGS+=	--with-xinerama
.endif

.if ${PORT_OPTIONS:MPAM} && empty(PORT_OPTIONS:MBAD_PAM)
pre-extract:
	@${ECHO}
	@${ECHO} "You have enabled PAM support. If you want to authenticate against"
	@${ECHO} "root only accessible PAM modules then define WITH_BAD_PAM=yes also."
	@${ECHO} "For example, pam_unix requires root rights to access shadow passwords."
	@${ECHO}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/xglockrc/ s|PROGRAM|DATA|' ${WRKSRC}/xglock/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(SOUNDPATH)|$$(DESTDIR)$$(SOUNDPATH)|g' ${WRKSRC}/modes/Makefile.in
	@${REINPLACE_CMD} -e '/$$(ETCDIR)play.sh/ s|$$(INSTALL_PROGRAM)|$$(INSTALL_PROGRAM:N-s)|' ${WRKSRC}/modes/Makefile.in
.if exists(/usr/bin/fortune)
	@${REINPLACE_CMD} -e 's|/usr/games/fortune|/usr/bin/fortune|' ${WRKSRC}/modes/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile

.include <bsd.port.mk>
