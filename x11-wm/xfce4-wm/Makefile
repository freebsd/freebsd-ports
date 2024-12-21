PORTNAME=	xfce4-wm
PORTVERSION=	4.20.0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DISTNAME=	xfwm4-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's window manager
WWW=		https://gitlab.xfce.org/xfce/xfwm4

LICENSE=	GPLv2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 libwnck3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xi xinerama \
		xorgproto xpresent xrandr xrender xres

CONFIGURE_ARGS=	--enable-xsync \
		--enable-render \
		--enable-randr \
		--enable-compositor \
		--enable-xpresent \
		--enable-poswin
GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/xfwm4

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS STARTUP
OPTIONS_DEFAULT=	STARTUP
OPTIONS_SUB=		yes

STARTUP_DESC=		Startup notification

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

post-patch:
	@${REINPLACE_CMD} -e 's|Default|Greybird|' \
		${WRKSRC}/settings-dialogs/xfwm4-settings.c

.include <bsd.port.mk>
