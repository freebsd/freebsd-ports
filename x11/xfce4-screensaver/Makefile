PORTNAME=	xfce4-screensaver
PORTVERSION=	4.20.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 screen saver and locker
WWW=		https://docs.xfce.org/apps/xfce4-screensaver/start

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxklavier.so:x11/libxklavier

USES=		compiler:c11 gettext-tools gnome meson pkgconfig python \
		shebangfix tar:xz xfce xorg
USE_GNOME=	glib20 gtk30 libwnck3
USE_XFCE=	garcon xfconf
USE_XORG=	ice sm x11 xext xrandr xscrnsaver xxf86vm

SHEBANG_FILES=	src/xfce4-screensaver-configure.py
MESON_ARGS=	-Dsession-manager=consolekit \
		-Dwayland=disabled \
		-Dx11=enabled

SCREENSAVER_DIR=	share/applications/screensavers

PORTDOCS=		docbook.css xfce4-screensaver.html

OPTIONS_DEFINE=		DOCS NLS PAM
OPTIONS_DEFAULT=	PAM
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			xmlto:textproc/xmlto
DOCS_MESON_ENABLED=	docs
DOCS_MESON_ON=		-Ddocdir=${DOCSDIR}

NLS_USES=	gettext-runtime

PAM_RUN_DEPENDS=	pam_helper:security/pam_helper
PAM_MESON_ON=		-Dauthentication-scheme=helper \
			-Dpasswd-helper=${LOCALBASE}/bin/pam_helper
PAM_MESON_OFF=		-Dauthentication-scheme=pwent

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

post-patch-PAM-on:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCREENSAVER_DIR}
	@${REINPLACE_CMD} 's/^\(Name[^=]*=\)\(.*\)/\1XFCE \2/' ${STAGEDIR}${PREFIX}/etc/xdg/autostart/xfce4-screensaver.desktop

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/xfce4-screensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/xfce4-screensaver.sample

.include <bsd.port.mk>
