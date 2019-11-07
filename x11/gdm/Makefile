# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdm
PORTVERSION=	3.28.4
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 display manager

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		itstool:textproc/itstool \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libck-connector.so:sysutils/consolekit2 \
		libaccountsservice.so:sysutils/accountsservice \
		libfribidi.so:converters/fribidi \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity \
		gnome-shell>=3.15.92:x11/gnome-shell \
		gnome-settings-daemon>=3.0.0:sysutils/gnome-settings-daemon \
		gnome-keyring-3:security/gnome-keyring \
		gnome-session>=3.0.0:x11/gnome-session \
		gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic \
		polkit-gnome>=0.105:sysutils/polkit-gnome \
		at-spi2-core>=0:accessibility/at-spi2-core \
		iso-codes>=0:misc/iso-codes
# used in scripts
RUN_DEPENDS+=	xrdb:x11/xrdb \
		setxkbmap:x11/setxkbmap \
		xsetroot:x11/xsetroot \
		xhost:x11/xhost \
		xmodmap:x11/xmodmap \
		xterm:x11/xterm

USERS=		gdm
GROUPS=		gdm video

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz xorg
CPE_VENDOR=	gnome
CPE_PRODUCT=	gnome_display_manager
USE_GNOME=	cairo dconf gtk30 intltool introspection
USE_LDCONFIG=	yes
USE_XORG=	x11 xau xcb xdmcp xorgproto
INSTALLS_ICONS=	yes
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	org.gnome.login-screen.gschema.xml
CONFIGURE_ARGS=	--disable-static \
		--mandir=${PREFIX}/man \
		--with-lang-file=${PREFIX}/etc/gdm/locale.conf \
		--with-at-spi-registryd-directory=${LOCALBASE}/libexec \
		--with-custom-conf=${PREFIX}/etc/gdm/custom.conf \
		--with-dbus-sys=${PREFIX}/etc/dbus-1/system.d \
		--with-log-dir=/var/log/gdm \
		--localstatedir=/var \
		--without-selinux \
		--without-libaudit \
		--with-console-kit \
		--with-working-directory=${PREFIX}/etc/gdm/home \
		--with-sysconfsubdir=gdm \
		--with-pid-file=/var/run/gdm.pid \
		--with-dmconfdir=${LOCALBASE}/share/xsessions \
		--with-screenshot-dir=/var/run/gdm/greeter \
		--enable-authentication-scheme=pam \
		--without-plymouth \
		--without-systemd \
		--with-user=gdm \
		--with-group=gdm \
		--with-initial-vt=09 \
		--enable-gdm-xsession \
		--disable-wayland-support \
		--with-systemd=no

# this is a hack until we can get our own pam dir and dir in order.
CONFIGURE_ARGS+=--with-default-pam-config=redhat
CPPFLAGS+=	-I${LOCALBASE}/include -DHAS_SA_LEN
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SUB_FILES+=	gdm-launch-environment \
		gdm-password \
		gdm-autologin \
		client.conf \
		locale.conf

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

OPTIONS_DEFINE=	IPV6

IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|root:root|root:wheel|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/daemon/gdm-session-worker.c
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|/usr/bin/X|${LOCALBASE}/bin/X|g' \
		-e 's|/usr/bin/Xorg|${LOCALBASE}/bin/Xorg|g' \
		${WRKSRC}/configure ${WRKSRC}/daemon/*.c ${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|/at-spi-registryd|/at-spi2-registryd|g' \
		${WRKSRC}/chooser/gdm-host-chooser.c \
		${WRKSRC}/chooser/chooser-main.c
	@${REINPLACE_CMD} -e 's|/etc/X11|${LOCALBASE}/etc/X11|g' \
		${WRKSRC}/data/Init.in \
		${WRKSRC}/data/PostLogin \
		${WRKSRC}/data/PostSession.in \
		${WRKSRC}/data/PreSession.in \
		${WRKSRC}/data/Xsession.in
	@${RM}	${WRKSRC}/data/applications/gdm-simple-greeter.desktop \
		${WRKSRC}/data/applications/gdm-simple-greeter.desktop.in \
		${WRKSRC}/data/applications/gnome-shell.desktop \

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/gdm.conf-custom \
		${STAGEDIR}${PREFIX}/etc/gdm/custom.conf.sample
	@${RM} ${STAGEDIR}${PREFIX}/etc/gdm/custom.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/gdm/PostSession/Default \
		${STAGEDIR}${PREFIX}/etc/gdm/PostSession/Default.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/gdm/PreSession/Default \
		${STAGEDIR}${PREFIX}/etc/gdm/PreSession/Default.sample

	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/Sessions
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/dm/Sessions

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/home
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/home/.pulse/

	${INSTALL_DATA} ${WRKDIR}/gdm-autologin \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-autologin
	${INSTALL_DATA} ${WRKDIR}/gdm-launch-environment \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-launch-environment
	${INSTALL_DATA} ${WRKDIR}/gdm-password \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-password

	${INSTALL_DATA} ${WRKDIR}/client.conf \
		${STAGEDIR}${PREFIX}/etc/gdm/home/.pulse/client.conf.sample

	${INSTALL_DATA} ${WRKDIR}/locale.conf \
		${STAGEDIR}${PREFIX}/etc/gdm/locale.conf.sample

	@${RM} ${STAGEDIR}${PREFIX}/lib/udev/rules.d/61-gdm.rules
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/udev/rules.d
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/udev

	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}

.include <bsd.port.mk>
