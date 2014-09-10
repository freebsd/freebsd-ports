# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver/Makefile,v 1.125 2012/09/03 16:28:29 mezz Exp $

PORTNAME=	gnome-screensaver
PORTVERSION=	2.30.2
PORTREVISION=	5
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

CONFLICTS=	gnome-screensaver-3.[0-9]*

GNU_CONFIGURE=	yes
USE_XORG=	xtst xxf86vm
USES=		pathfix gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomemenus libgnomekbd gnomedesktop
CONFIGURE_ARGS=	--with-gdm-config=${LOCALBASE}/etc/gdm/custom.conf \
		--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-screensaver.schemas
MAN1=		gnome-screensaver-command.1 gnome-screensaver-preferences.1 \
		gnome-screensaver.1

PLIST=	${WRKDIR}/pkg-plist
SUB_FILES+=	gnome-screensaver.pam

XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
SCREENSAVER_DIR=	share/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS_DEFINE=	PAM KEYRING
OPTIONS_DEFAULT=PAM KEYRING
PAM_DESC=	Pluggable Authentication Module support
KEYRING_DESC=	GnomeKeyring integration (needs PAM)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
RUN_DEPENDS+=		pam_helper:${PORTSDIR}/security/pam_helper
CONFIGURE_ARGS+=	--enable-authentication-scheme=helper \
			--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		PAM="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING} && ${PORT_OPTIONS:MPAM}
SUB_LIST+=		PAM_KEYRING=
RUN_DEPENDS+=		${LOCALBASE}/lib/pam_gnome_keyring.so:${PORTSDIR}/security/gnome-keyring
.else
SUB_LIST+=		PAM_KEYRING=\#
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

pre-install:
	@${CAT} ${.CURDIR}/pkg-plist > ${PLIST}
	@cd ${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
		${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
		${SED} -e 's:^:${SCREENSAVER_DIR}/:' | \
		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
	@${ECHO_CMD} @dirrm ${SCREENSAVER_DIR} >> ${PLIST}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}
	cd ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR} && \
		${FIND} -s ${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
			${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh
.if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${WRKDIR}/gnome-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/gnome-screensaver
.endif

.include <bsd.port.mk>
