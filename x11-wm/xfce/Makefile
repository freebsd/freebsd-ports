# New ports collection makefile for:	xfce
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	3.8.18
PORTREVISION=	9
CATEGORIES=	x11-wm xfce
MASTER_SITES=	SF

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CDE like desktop with GTK

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_GCC=	4.2+
USE_XORG=	x11 xpm
USE_GETTEXT=	yes
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-conf-dir=${PREFIX}/etc/xfce \
		--with-data-dir=${PREFIX}/share/xfce \
		--with-locale-dir=${PREFIX}/share/locale \
		--with-xpm=${LOCALBASE} \
		--enable-gtk-engine=${PREFIX}/lib/gtk/themes/engines \
		--disable-arts \
		--enable-taskbar \
		--enable-xinerama

OPTIONS=	XFT "enable anti-aliased font support" off

MAN1=		glob.1 xfbd.1 xfce.1 xfclock.1 xfglob.1 xfgnome.1 xfhelp.1 \
		xflock.1 xfmountdev.1 xfmouse.1 xfpager.1 xfprint.1 xfrun.1 \
		xfskin.1 xfsound.1 xfterm.1 xftrash.1 xftree.1 xfumed.1 xfwm.1

.include <bsd.port.pre.mk>

.if defined(WITH_XFT)
USE_XORG=	xft
CONFIGURE_ARGS+=	--enable-xft
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|xfplay|internal|g' ${WRKSRC}/other/xfsoundrc.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/other/xinitrc.in
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG:T}|g' ${WRKSRC}/xfce/setup.c
	@${REINPLACE_CMD} -e 's|/opt/kde3|${LOCALBASE}|g ; \
		s|/opt/gnome|${LOCALBASE}|g' ${WRKSRC}/xfmenu/xfmenu.c
	@${REINPLACE_CMD} -e 's|static \(Atom _XA_WIN_STATE;\)|\1|; \
		s|static \(Atom _XA_WIN_WORKSPACE;\)|\1|; \
		s|static \(Atom _XA_WIN_WORKSPACE_COUNT;\)|\1|' \
		${WRKSRC}/xfgnome/xfgnome.h
	@${REINPLACE_CMD} -e 's|static \(nmb_history \*headH;\)|\1|' \
		${WRKSRC}/xfsamba/xfsamba_mem.c
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
