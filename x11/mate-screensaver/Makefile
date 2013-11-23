# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-screensaver
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE screen saver and locker

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_GL=		gl
USE_XZ=		yes
USE_MATE=	desktop libmatekbd menus
USE_XORG=	ice sm x11 xext xtst xxf86misc xxf86vm xscrnsaver
USE_GNOME=	glib20 gnomehier gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-console-kit=yes \
		--with-systemd=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.screensaver.gschema.xml

#PLIST=		${WRKDIR}/pkg-plist
SUB_FILES+=	mate-screensaver.pam

XSCREENSAVER_DIR=	${PREFIX}/share/xscreensaver/config
SCREENSAVER_DIR=	share/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS_DEFINE=	PAM KEYRING HACKS
OPTIONS_DEFAULT=PAM KEYRING
PAM_DESC=	Pluggable Authentication Module support
KEYRING_DESC=	MateKeyring integration (needs PAM)
HACKS_DESC=	Install extra gnome xscreensavers

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXSCREENSAVER}
RUN_DEPENDS=	xscreensaver-gnome-hacks>=0:${PORTSDIR}/x11/xscreensaver-gnome-hacks
.endif

.if ${PORT_OPTIONS:MPAM}
RUN_DEPENDS+=	pam_helper:${PORTSDIR}/security/pam_helper
CONFIGURE_ARGS+=--enable-authentication-scheme=helper \
		--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PLIST_SUB+=	PAM=""
.else
CONFIGURE_ARGS+=--disable-pam
PLIST_SUB+=	PAM="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING} && ${PORT_OPTIONS:MPAM}
SUB_LIST+=	PAM_KEYRING=
USE_MATE+=	keyring:run
.else
SUB_LIST+=	PAM_KEYRING=\#
.endif

pre-everything::
.if !${PORT_OPTIONS:MPAM} && ${PORT_OPTIONS:MKEYRING}
	@${ECHO_MSG} "Keyring integration is disabled because it needs PAM."
.endif

post-patch:
.if ${PORT_OPTIONS:MPAM}
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
.endif

#.if defined (HACKS)
#pre-install:
#	@${CAT} ${.CURDIR}/pkg-plist > ${PLIST}
#	@cd ${STAGEDIR}${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
#		${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
#		${SED} -e 's:^:${SCREENSAVER_DIR}/:' | \
#		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
#	@${ECHO_CMD} @dirrm ${SCREENSAVER_DIR} >> ${PLIST}
#.endif

post-install:
#.if defined(HACKS)
#	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}
#	cd ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR} && \
#		${FIND} -s ${STAGEDIR}${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
#			${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
#			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh
#.endif
.if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${WRKDIR}/mate-screensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/mate-screensaver
.endif

.include <bsd.port.mk>
