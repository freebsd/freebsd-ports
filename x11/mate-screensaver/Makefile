# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-screensaver
PORTVERSION=	1.12.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE screen saver and locker

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GL=		gl
USE_MATE=	desktop libmatekbd menus
USE_XORG=	ice sm x11 xext xtst xxf86misc xxf86vm xscrnsaver
USE_GNOME=	glib20 gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-gtk=2.0 \
		--with-console-kit=yes \
		--with-systemd=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.screensaver.gschema.xml

SUB_FILES+=	mate-screensaver.pam

XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
SCREENSAVER_DIR=	share/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS_DEFINE=	PAM XSCREENSAVER
OPTIONS_DEFAULT=PAM
PAM_DESC=	Pluggable Authentication Module support

XSCREENSAVER_RUN_DEPENDS=	xscreensaver-gnome-hacks>=0:x11/xscreensaver-gnome-hacks

OPTIONS_SUB=	yes

PAM_RUN_DEPENDS=	pam_helper:security/pam_helper
PAM_CONFIGURE_ON=--enable-authentication-scheme=helper \
		--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PAM_CONFIGURE_OFF=--disable-pam

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
