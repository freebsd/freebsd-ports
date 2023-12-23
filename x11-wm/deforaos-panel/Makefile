PORTNAME=	deforaos-panel
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Panel/
DISTNAME=	Panel-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop panel
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/Desktop/Browser.h:x11-fm/deforaos-browser
LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libasound.so:audio/alsa-lib \
		libharfbuzz.so:print/harfbuzz \
		libxkbfile.so:x11/libxkbfile

USES=		gnome pkgconfig xorg desktop-file-utils

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
    ${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
	gtkdoc-mkhtml:textproc/gtk-doc

USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_XORG=	x11
USE_LDCONFIG=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/battery.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/bluetooth.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/brightness.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/clock.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/close.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/cpu.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/cpufreq.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/desktop.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/embed.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/gps.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/gsm.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/leds.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/lock.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/logout.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/memory.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/menu.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/mixer.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/network.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/pager.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/rotate.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/separator.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/shutdown.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/spacer.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/suspend.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/swap.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/systray.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/tasks.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/title.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/usb.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/user.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/volume.so \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/wpa_supplicant.so \
		${STAGEDIR}${PREFIX}/lib/libPanel.so.0.0

.include <bsd.port.mk>
