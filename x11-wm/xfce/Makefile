# New ports collection makefile for:	xfce
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	3.8.18
PORTREVISION=	2
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.xfce.org/archive/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CDE like desktop with GTK

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gdkpixbuf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-conf-dir=${PREFIX}/etc/xfce \
		--with-data-dir=${PREFIX}/share/xfce \
		--with-locale-dir=${PREFIX}/share/locale \
		--with-xpm=${X11BASE} \
		--enable-gtk-engine=${PREFIX}/lib/gtk/themes/engines \
		--disable-arts \
		--enable-taskbar

OPTIONS=	XFT "enable anti-aliased font support" off

MAN1=		glob.1 xfbd.1 xfce.1 xfclock.1 xfglob.1 xfgnome.1 xfhelp.1 \
		xflock.1 xfmountdev.1 xfmouse.1 xfpager.1 xfprint.1 xfrun.1 \
		xfskin.1 xfsound.1 xfterm.1 xftrash.1 xftree.1 xfumed.1 xfwm.1

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
.if defined(WITH_XFT)
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/Xft
CONFIGURE_ARGS+=	--enable-xft
.endif
CONFIGURE_ARGS+=	--enable-xinerama
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|xfplay|internal|g' ${WRKSRC}/other/xfsoundrc.in
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/other/xinitrc.in
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG:T}|g' ${WRKSRC}/xfce/setup.c
	@${REINPLACE_CMD} -e 's|/opt/kde3|${LOCALBASE}|g ; \
		 s|/opt/gnome|${X11BASE}|g' ${WRKSRC}/xfmenu/xfmenu.c

.include <bsd.port.post.mk>
