# Created by: Scott Mace <smace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlockmore
PORTVERSION=	5.58
PORTREVISION=	1
CATEGORIES?=	x11
MASTER_SITES=	http://www.sillycycle.com/xlock/ \
		SF/bsdsrc/${.CURDIR:T}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Like XLock session locker/screen saver, but just more

LICENSE=	BSD2CLAUSE

USES=		tar:xz gnome xorg

GNU_CONFIGURE=	yes
PORTDOCS=	README ${PORTNAME}.README
CONFIGURE_ARGS=	--without-motif --without-ttf --without-editres \
		--without-dtsaver --without-rplay --without-nas \
		--without-gtk --without-esound --disable-setuid

USE_XORG=	x11 xaw ice sm xpm xext xinerama

LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

OPTIONS_DEFINE=	MESAGL MB SYSLOG DISABLE_ALLOW_ROOT NICE_ONLY BLANK_ONLY \
		KERBEROS5 BAD_PAM GTK2 TIME_BOMB CUSTOMIZATION MAGICK JP \
		XINERAMA DOCS
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

MESAGL_CONFIGURE_WITH=	mesa
MESAGL_VARS=	CFLAGS+="-I${LOCALBASE}/include/FTGL -I${LOCALBASE}/include/freetype2" USE_GL=yes
MESAGL_LIB_DEPENDS=	libftgl.so:graphics/ftgl
MESAGL_CONFIGURE_ENV=	XLOCKLIBS="-lpthread"
MESAGL_CONFIGURE_OFF=	--without-opengl --without-ftgl
KERBEROS5_CONFIGURE_ENABLE=	kerberos5
KERBEROS5_VARS=		CFLAGS+=-I${KRB5_HOME}/include KRB5LIB=-L${KRB5_HOME}/lib
KERBEROS5_CONFIGURE_ENV=	XLOCKLIBS="${KRB5LIB}"
BAD_PAM_CONFIGURE_ENABLE=	bad-pam
PAM_CONFIGURE_ENABLE=	pam
NICE_ONLY_CONFIGURE_ENABLE=	nice-only
BLANK_ONLY_CONFIGURE_ENABLE=	blank-only
MB_CONFIGURE_ON=	--enable-use-mb
MB_CONFIGURE_OFF=	--disable-mb
SYSLOG_CONFIGURE_ENABLE=	syslog
XINERAMA_CONFIGURE_WITH=	xinerama
DISABLE_ALLOW_ROOT_CONFIGURE_ON=	--disable-allow-root
XLOCK_GROUP_CONFIGURE_ENABLE=	xlock-group
TIME_BOMB_CONFIGURE_ENABLE=		bomb
CUSTOMIZATION_CONFIGURE_ENABLE=	customization
JP_VARS=	XLOCKMORE_LANG=ja CATEGORIES+=japanese
MAGICK_CONFIGURE_OFF=	--without-magick
MAGICK_LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick6
GTK2_CONFIGURE_WITH=	gtk2
GTK2_VARS+=	USE_GNOME+=gtk20

.include <bsd.port.options.mk>

.if defined(XLOCKMORE_LANG)
CONFIGURE_ARGS+=	--with-lang=${XLOCKMORE_LANG}
.endif

.if ${PORT_OPTIONS:MKERBEROS5} && empty(KRB5_HOME)
BROKEN=	KRB5_HOME is undefined!
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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Revisions ${STAGEDIR}${DOCSDIR}/${PORTNAME}.README
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
