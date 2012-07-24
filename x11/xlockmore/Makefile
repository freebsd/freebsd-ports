# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION=	5.40
CATEGORIES?=	x11
MASTER_SITES=	ftp://ibiblio.org/pub/Linux/X11/screensavers/ \
		http://www.tux.org/~bagleyd/xlock/${PORTNAME}-${PORTVERSION}/ \
		CRITICAL

MAINTAINER=	marius@nuenneri.ch
COMMENT=	Like XLock session locker/screen saver, but just more

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-motif --without-ttf --without-editres \
		--without-dtsaver --without-rplay --without-nas \
		--without-gtk --without-esound

USE_GNOME=	#
USE_XORG=	x11 xaw ice

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2

MAN1=		xlock.1
PLIST_FILES=	bin/xlock lib/X11/app-defaults/XLock

OPTIONS_DEFINE=	MESAGL MB SYSLOG DISABLE_ALLOW_ROOT NICE_ONLY BLANK_ONLY \
		KERBEROS4 BAD_PAM GTK2 TIME_BOMB CUSTOMIZATION

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

OPTIONS_DEFINE+=	ONE
OPTIONS_SINGLE=	ONE
OPTIONS_SINGLE_ONE=	PAM XLOCK_GROUP
ONE_DESC=	Choose one of PAM or XLOCK_GROUP

NO_OPTIONS_SORT=yes

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
MESALIB=${PTHREAD_LIBS}
USE_GL=	yes
CFLAGS+=	-I${LOCALBASE}/include/FTGL
.else
CONFIGURE_ARGS+=	--without-mesa --without-opengl
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

.if ${PORT_OPTIONS:MXLOCKMORE_LANG}
CONFIGURE_ARGS+=	--with-lang=${XLOCKMORE_LANG}
.endif

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--with-gtk2
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/xglock share/xlock/xglockrc
PLIST_DIRS+=	share/xlock
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if ${PORT_OPTIONS:MXLOCK_GROUP}
CONFIGURE_ARGS+=	--enable-xlock-group
.endif

.if ${PORT_OPTIONS:MTIME_BOMB)
CONFIGURE_ARGS+=	--enable-bomb
.else
CONFIGURE_ARGS+=	--disable-bomb
.endif

.if ${PORT_OPTIONS:MCUSTOMIZATION)
CONFIGURE_ARGS+=	--enable-customization
.endif

CONFIGURE_ENV+=		XLOCKLIBS="${KRB5LIB} ${KRB4LIB} ${MESALIB}"

.if ${PORT_OPTIONS:MDISABLE_ALLOW_ROOT)
CONFIGURE_ARGS+=	--disable-allow-root
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

post-configure:
	${REINPLACE_CMD} -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile

.include <bsd.port.post.mk>
