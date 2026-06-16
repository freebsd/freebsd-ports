PORTNAME=	mate-screensaver
DISTVERSION=	1.28.0
PORTREVISION=	3
CATEGORIES=	x11 mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE screen saver and locker
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification

USES=		gettext gl gmake gnome localbase mate pathfix pkgconfig tar:xz \
		xorg
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GL=		gl
USE_MATE=	desktop libmatekbd menus session:run
USE_XORG=	ice sm x11 xext xscrnsaver xxf86vm
USE_GNOME=	cairo gdkpixbuf gtk30 intltool
PORTSCOUT=	site:https://github.com/mate-desktop/mate-screensaver/releases/ limitw:1,even
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-console-kit=yes \
		--with-systemd=no

GLIB_SCHEMAS=	org.mate.screensaver.gschema.xml

SUB_FILES+=	mate-screensaver.pam

SCREENSAVER_DIR=	share/applications/screensavers

OPTIONS_DEFINE=	PAM
OPTIONS_DEFAULT=PAM
OPTIONS_SUB=	yes

PAM_RUN_DEPENDS=	mate_pam_helper:security/mate-pam-helper
PAM_CONFIGURE_ON=	--enable-authentication-scheme=helper \
			--with-passwd-helper=${LOCALBASE}/bin/mate_pam_helper
PAM_CONFIGURE_OFF=	--disable-pam

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MPAM}
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}
.if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${WRKDIR}/mate-screensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/mate-screensaver
.endif

.include <bsd.port.mk>
