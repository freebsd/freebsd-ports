# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION=	5.29
CATEGORIES?=	x11
MASTER_SITES=	ftp://ibiblio.org/pub/Linux/X11/screensavers/ \
		http://www.tux.org/~bagleyd/xlock/${PORTNAME}-${PORTVERSION}/ \
		CRITICAL

MAINTAINER?=	marius@nuenneri.ch
COMMENT=	Like XLock session locker/screen saver, but just more

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gl --without-motif --without-sx --without-ttf \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk --without-esound
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+=--enable-kerberos4
KRB4LIB=	-lcom_err -lcrypto
.endif
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--enable-kerberos5
CFLAGS+=	-I${KRB5_HOME}/include
KRB5LIB=	-L${KRB5_HOME}/lib
.endif
USE_GNOME=	#
USE_XORG=	x11 xaw ice

MAN1=		xlock.1
PLIST_FILES=	bin/xlock lib/X11/app-defaults/XLock

OPTIONS=MESAGL			"Enable Mesa 3D (for GL modes)"		off \
	MB			"Enable Xmb function series"		off \
	SYSLOG			"Enable syslog logging"			off \
	DISABLE_ALLOW_ROOT	"Allows users to turn off allowroot"	off \
	NICE_ONLY		"Enable only low cpu modes"		off \
	BLANK_ONLY		"Enable blank mode only (boring)"	off \
	PAM			"Enable PAM authentication support"	off \
	BAD_PAM			"Xlock will ask PAM with root rights"	off \
	GTK2			"Build Gtk2 graphical shell"		off \
	XLOCK_GROUP		"Allow xlock group to logout"		off \
	TIME_BOMB		"Allow autologout"			off \
	CUSTOMIZATION		"Allow tune through resource file"	off

.include <bsd.port.pre.mk>

.if defined(WITH_MESAGL)
CONFIGURE_ARGS+=	--with-mesa
MESALIB=${PTHREAD_LIBS}
USE_GL=	yes
CFLAGS+=	-I${LOCALBASE}/include/FTGL
.else
CONFIGURE_ARGS+=	--without-mesa --without-opengl
.endif

.if defined(WITH_NICE_ONLY)
CONFIGURE_ARGS+=	--enable-nice-only
.endif

.if defined(WITH_BAD_PAM)
CONFIGURE_ARGS+=	--enable-bad-pam
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
.if defined(WITH_XLOCK_GROUP)
BROKEN=			PAM and xlock group simultaneously breaks the build
.endif
.endif

.if defined(WITH_NICE_ONLY)
CONFIGURE_ARGS+=	--enable-nice-only
.endif

.if defined(WITH_BLANK_ONLY)
CONFIGURE_ARGS+=	--enable-blank-only
.endif

.if defined(WITH_MB)
CONFIGURE_ARGS+=	--enable-use-mb
.endif

.if defined(XLOCKMORE_LANG)
CONFIGURE_ARGS+=	--with-lang=${XLOCKMORE_LANG}
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	--with-gtk2
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/xglock share/xlock/xglockrc
PLIST_DIRS+=	share/xlock
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if defined(WITH_XLOCK_GROUP)
CONFIGURE_ARGS+=	--enable-xlock-group
.if defined(WITH_PAM)
BROKEN=			PAM and xlock group simultaneously breaks the build
.endif
.endif

.if defined(WITH_TIME_BOMB)
CONFIGURE_ARGS+=	--enable-bomb
.else
CONFIGURE_ARGS+=	--disable-bomb
.endif

.if defined(WITH_CUSTOMIZATION)
CONFIGURE_ARGS+=	--enable-customization
.endif

CONFIGURE_ENV+=		XLOCKLIBS="${KRB5LIB} ${KRB4LIB} ${MESALIB}"

.if defined(WITH_DISABLE_ALLOW_ROOT)
CONFIGURE_ARGS+=	--disable-allow-root
.endif

.if defined(WITH_PAM) && !defined (WITH_BAD_PAM)
pre-extract:
	@${ECHO}
	@${ECHO} "You have enabled PAM support. If you want to authenticate against"
	@${ECHO} "root only accessible PAM modules then define WITH_BAD_PAM=yes also."
	@${ECHO} "For example, pam_unix requires root rights to access shadow passwords."
	@${ECHO}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/xglockrc/ s|PROGRAM|DATA|' ${WRKSRC}/xglock/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile

.include <bsd.port.post.mk>
