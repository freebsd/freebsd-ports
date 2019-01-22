# $FreeBSD$

PORTNAME=	xfce4-screensaver
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 screen saver and locker

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification \
		libxklavier.so:x11/libxklavier

USES=		gettext-tools gmake gnome pkgconfig tar:bzip2 xfce:gtk3
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	garcon libexo libutil
USE_XORG=	ice sm x11 xext xrandr xscrnsaver xxf86vm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-console-kit=yes \
		--with-systemd=no \
		--enable-maintainer-mode

XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
SCREENSAVER_DIR=	share/applications/screensavers

OPTIONS_DEFINE=	NLS PAM XSCREENSAVER
OPTIONS_DEFAULT=PAM
PAM_DESC=	Pluggable Authentication Module support
XSCREENSAVER_DESC=	Use xscreensaver hacks

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

PAM_RUN_DEPENDS=	pam_helper:security/pam_helper
PAM_CONFIGURE_ON=	--enable-authentication-scheme=helper \
			--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PAM_CONFIGURE_OFF=	--disable-pam

XSCREENSAVER_RUN_DEPENDS=	xscreensaver-gnome-hacks>=0:x11/xscreensaver-gnome-hacks

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

post-patch-PAM-on:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/xfce-screensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/xfce-screensaver

.include <bsd.port.post.mk>
