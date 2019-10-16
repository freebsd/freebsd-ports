# $FreeBSD$

PORTNAME=	xfce4-screensaver
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 screen saver and locker

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxklavier.so:x11/libxklavier

USES=		compiler:c11 gettext-tools gl gmake gnome pkgconfig python:3.5+ \
		shebangfix tar:bzip2 xfce xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libwnck3
USE_XFCE=	garcon libexo xfconf
USE_XORG=	ice sm x11 xext xrandr xscrnsaver xxf86vm

SHEBANG_FILES=	src/xfce4-screensaver-configure
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-console-kit=yes \
		--with-systemd=no \
		--enable-maintainer-mode

SCREENSAVER_DIR=	share/applications/screensavers

OPTIONS_DEFINE=	NLS PAM
OPTIONS_DEFAULT=PAM
PAM_DESC=	Pluggable Authentication Module support

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

PAM_RUN_DEPENDS=	pam_helper:security/pam_helper
PAM_CONFIGURE_ON=	--enable-authentication-scheme=helper \
			--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PAM_CONFIGURE_OFF=	--disable-pam

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

post-patch-PAM-on:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}
	@${REINPLACE_CMD} 's/^\(Name[^=]*=\)\(.*\)/\1XFCE \2/' ${STAGEDIR}${PREFIX}/etc/xdg/autostart/xfce4-screensaver.desktop

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/xfce-screensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/xfce-screensaver

.include <bsd.port.post.mk>
