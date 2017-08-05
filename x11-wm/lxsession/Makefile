# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxsession
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%200.5.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Session Manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libunique-1.0.so:x11-toolkits/unique \
		libpolkit-agent-1.so:sysutils/polkit \
		libck-connector.so:sysutils/consolekit2

USES=		autoreconf gmake localbase pkgconfig tar:xz
USE_GNOME=	glib20 gtk20 intltool cairo gdkpixbuf2 libxslt
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--enable-buildin-clipboard \
		--enable-buildin-polkit

OPTIONS_DEFINE=	NLS UPOWER
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_DESC=	Suspend/Hibernate support

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|/etc/xdg|${PREFIX}/etc/xdg|g ;\
			s|%%PREFIX%%|${PREFIX}| ;\
			s|/usr/bin/pkexec|${PREFIX}/bin/pkexec|g ;\
			s|:/usr/share:/usr/share/gdm||g ;\
			s|:/var/lib/menu-xdg||g ;\
			s|/usr/share|${PREFIX}/share|g ;\
			s|/usr/lib|${PREFIX}/lib|g ;\
			s|%%QT4_LIBDIR%%|${PREFIX}/lib/qt4| ;\
			s|%%QT5_LIBDIR%%|${PREFIX}/lib/qt5| ;\
			s|Clearlooks|Adwaita|'

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
