PORTNAME=	gdm
PORTVERSION=	47.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME display manager
WWW=		https://gitlab.gnome.org/GNOME/gdm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes \
		xorg-server>0:x11-servers/xorg-server \
		itstool:textproc/itstool
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libck-connector.so:sysutils/consolekit2 \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	gnome-keyring-3:security/gnome-keyring \
		gnome-session>0:x11/gnome-session \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		iso-codes>0:misc/iso-codes
# used in scripts
RUN_DEPENDS+=	setxkbmap:x11/setxkbmap \
		xhost:x11/xhost \
		xmodmap:x11/xmodmap \
		xrdb:x11/xrdb \
		xsetroot:x11/xsetroot \
		xterm:x11/xterm \
		zenity:x11/zenity

USERS=		gdm
GROUPS=		gdm video

USES=		cpe gettext gnome localbase:ldflags meson pathfix \
		pkgconfig tar:xz xorg
CPE_VENDOR=	gnome
CPE_PRODUCT=	gnome_display_manager
USE_GNOME=	atk dconf gdkpixbuf glib20 gtk30 introspection:build
USE_LDCONFIG=	yes
USE_XORG=	x11 xau xcb xdmcp xorgproto
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
GLIB_SCHEMAS=	org.gnome.login-screen.gschema.xml \
		15_org.gnome.login-screen.gschema.override
MESON_ARGS=	-Dat-spi-registryd-dir=${PREFIX}/libexec \
		-Dcustom-conf=${PREFIX}/etc/gdm/custom.conf \
		-Ddefault-pam-config=none \
		-Ddmconfdir=${PREFIX}/share/xsessions \
		-Dgdm-xsession=true \
		-Dgroup=gdm \
		-Dinitial-vt=09 \
		-Dlang-file=${PREFIX}/etc/gdm/locale.conf \
		-Dlibaudit=disabled \
		-Dpid-file=/var/run/gdm.pid \
		-Dplymouth=disabled \
		-Dscreenshot-dir=/var/run/gdm/greeter \
		-Dselinux=disabled \
		-Dsystemd-journal=false \
		-Duser-display-server=false \
		-Dudev-dir=${PREFIX}/lib/udev/rules.d \
		-Duser=gdm \
		-Dworking-dir=/var/cache/gdm \
		-Dxauth-dir=/var/run/gdm

# this is a hack until we can get our own pam dir and dir in order.
CPPFLAGS+=	-DHAS_SA_LEN -DWITH_CONSOLE_KIT=1

SUB_FILES+=	gdm-autologin gdm-launch-environment gdm-password \
		locale.conf

GDMDIR?=	${PREFIX}/etc/gdm

GNOME_LOCALSTATEDIR=	/var

OPTIONS_DEFINE=	IPV6

IPV6_MESON_TRUE=	ipv6

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|/usr/bin/X|${LOCALBASE}/bin/X|g' \
		-e 's|/usr/bin/Xorg|${LOCALBASE}/bin/Xorg|g' \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|g' \
		${WRKSRC}/daemon/gdm-local-display-factory.c
	@${REINPLACE_CMD} -e 's|/at-spi-registryd|/at-spi2-registryd|g' \
		${WRKSRC}/chooser/gdm-host-chooser.c \
		${WRKSRC}/chooser/chooser-main.c
	@${REINPLACE_CMD} -e 's|/etc/X11|${LOCALBASE}/etc/X11|g' \
		${WRKSRC}/data/Init.in \
		${WRKSRC}/data/Xsession.in

# Force X11 session (support of Wayland is not yet complete!)
	@${REINPLACE_CMD} -e 's|wayland|xorg|' \
		${WRKSRC}/data/gdm.schemas.in

pre-install:
	${MKDIR} ${STAGEDIR}/var/cache/gdm
	${MKDIR} ${STAGEDIR}/var/log/gdm
	${MKDIR} ${STAGEDIR}/var/run/gdm/greeter

	#${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/home
	#${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/home/.pulse
	#${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdm/home/.config

post-install:
	${INSTALL_DATA} ${WRKDIR}/gdm-autologin \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-autologin.sample
	${INSTALL_DATA} ${WRKDIR}/gdm-launch-environment \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-launch-environment.sample
	${INSTALL_DATA} ${WRKDIR}/gdm-password \
		${STAGEDIR}${PREFIX}/etc/pam.d/gdm-password.sample

	#${INSTALL_DATA} ${WRKDIR}/client.conf \
	#	${STAGEDIR}${PREFIX}/etc/gdm/home/.pulse/client.conf.sample

	${INSTALL_DATA} ${WRKDIR}/locale.conf \
		${STAGEDIR}${PREFIX}/etc/gdm/locale.conf.sample

	${INSTALL_DATA} ${FILESDIR}/15_org.gnome.login-screen.gschema.override \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/

.include <bsd.port.mk>
