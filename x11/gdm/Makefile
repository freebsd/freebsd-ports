# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gdm/Makefile,v 1.192 2012/09/03 16:28:28 mezz Exp $

PORTNAME=	gdm
PORTVERSION=	2.30.7
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 version of xdm display manager

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
    		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	libck-connector.so:${PORTSDIR}/sysutils/consolekit \
		libpolkit-gtk-1.so:${PORTSDIR}/sysutils/polkit-gnome \
    		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
		gnome-session:${PORTSDIR}/x11/gnome-session \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

CONFLICTS=	gdm-3.[0-9]*

USERS=		gdm
GROUPS=		gdm

USE_LDCONFIG=	yes
USE_XORG=	dmx dmxproto
INSTALLS_ICONS=	yes
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
USES=		pathfix gettext gmake pkgconfig tar:xz
USE_GNOME=	intlhack gnomehier gconf2 librsvg2 \
		gnomedocutils gnomeprefix gnomepanel
GCONF_SCHEMAS=	gdm-simple-greeter.schemas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-working-directory=${PREFIX}/etc/gdm/home \
		--with-at-spi-registryd-directory=${LOCALBASE}/libexec
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include -DHAS_SA_LEN
LIBS+=		-L${LOCALBASE}/lib -lm

SUB_FILES+=	gdm.pam

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

OPTIONS_DEFINE=	IPV6 KEYRING
OPTIONS_DEFAULT=KEYRING
KEYRING_DESC=	GnomeKeyring/PAM integration

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
SUB_LIST+=	PAM_KEYRING=
.else
SUB_LIST+=	PAM_KEYRING=\#
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e '/root:/d; s/1640/0640/g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/daemon/gdm-session-worker.c \
		${WRKSRC}/data/gconf.path
	@${REINPLACE_CMD} -e 's|/bin/true|/usr/bin/true|g' \
	    	${WRKSRC}/data/session-setup.entries
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure ${WRKSRC}/daemon/*.c ${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|/usr/lib|${LOCALBASE}/lib|g' \
		${WRKSRC}/data/greeter-autostart/*.desktop.in*

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/gconf.path \
	    	${STAGEDIR}${PREFIX}/share/gdm/gconf.path
	${INSTALL_DATA} ${WRKSRC}/data/session-setup.entries \
	    ${STAGEDIR}${PREFIX}/share/gdm/session-setup.entries
	${INSTALL_DATA} ${WRKSRC}/data/gdm.conf-custom \
		${STAGEDIR}${PREFIX}/etc/gdm/custom.conf.default
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/gdm.pam ${STAGEDIR}${PREFIX}/etc/pam.d/gdm
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	${RM} -rf ${STAGEDIR}${ETCDIR}/home/.gconf*
	${RM} -f ${STAGEDIR}${ETCDIR}/custom.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/Sessions ${STAGEDIR}${PREFIX}/etc/dm/Sessions

.include <bsd.port.mk>
