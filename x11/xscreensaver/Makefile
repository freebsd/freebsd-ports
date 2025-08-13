PORTNAME=	xscreensaver
DISTVERSION=	6.12
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Save your screen while you entertain your cat
WWW=		https://www.jwz.org/xscreensaver/

LICENSE=	MIT

EXTRACT_DEPENDS=	gtar:archivers/gtar
LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgle.so:graphics/gle \
			libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=		giftopnm:graphics/netpbm \
			p5-libwww>0:www/p5-libwww \
			p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
			unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		cpe gettext gl gmake gnome jpeg localbase:ldflags perl5 \
		pkgconfig shebangfix xorg
CPE_VENDOR=	xscreensaver_project
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf gtk30 intltool libxml2
USE_XORG=	ice sm x11 xext xft xi xinerama xmu xrandr xrender xt xxf86vm

SHEBANG_FILES=	hacks/check-configs.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-locking \
		--with-app-defaults=${PREFIX}/lib/X11/app-defaults \
		--with-configdir=${PREFIX}/share/xscreensaver/config/ \
		--with-dpms-ext \
		--with-gl \
		--with-gle \
		--with-gtk \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks/ \
		--with-jpeg=${LOCALBASE} \
		--with-pam \
		--with-pixbuf \
		--with-randr-ext \
		--with-xdbe-ext \
		--with-xf86gamma-ext \
		--with-xf86vmode-ext \
		--with-xft \
		--with-xinerama-ext \
		--with-xshm-ext \
		--without-kerberos \
		--without-shadow
CONFIGURE_ENV=	PERL="${PERL}"

MAKE_ARGS=	install_prefix=${STAGEDIR}

EXTRACT_CMD=	gtar
SUB_FILES=	xscreensaver-blank.desktop xscreensaver-lock.desktop \
		xscreensaver-start.desktop xscreensaver-stop.desktop

OPTIONS_DEFINE=	FIREF NLS NSFW SETUID_HACKS WAYLAND XAOS1 XDALI XEARTH XMOUN \
		XPLANET XSNOW
OPTIONS_SUB=	yes

FIREF_DESC=		Add extra port x11/fireflies
NSFW_DESC=		Include material that is Not Safe For Work
SETUID_HACKS_DESC=	Install sonar hack suid so it can ping
XAOS1_DESC=		Add extra port graphics/xaos
XDALI_DESC=		Add extra port x11-clocks/xdaliclock
XEARTH_DESC=		Add extra port astro/xearth
XMOUN_DESC=		Add extra port graphics/xmountains
XPLANET_DESC=		Add extra port astro/xplanet
XSNOW_DESC=		Add extra port x11/xsnow

FIREF_RUN_DEPENDS=		${FIREF_HACKBIN}:x11/fireflies
NLS_USES=			gettext-runtime
NLS_CONFIGURE_ENABLE=		nls
SETUID_HACKS_CONFIGURE_WITH=	setuid-hacks
WAYLAND_BUILD_DEPENDS=		wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_WITH=		wayland
XAOS1_RUN_DEPENDS=		xaos:graphics/xaos
XDALI_RUN_DEPENDS=		xdaliclock:x11-clocks/xdaliclock
XEARTH_RUN_DEPENDS=		xearth:astro/xearth
XMOUN_RUN_DEPENDS=		xmountains:graphics/xmountains
XPLANET_RUN_DEPENDS=		xplanet:astro/xplanet
XSNOW_RUN_DEPENDS=		xsnow:x11/xsnow

FIREF_HACKBIN=	${LOCALBASE}/bin/xscreensaver-hacks/fireflies

post-patch:
	${REINPLACE_CMD} -e "s|/etc/pam.d|${PREFIX}/etc/pam.d|g" \
		${WRKSRC}/driver/passwd-pam.c \
		${WRKSRC}/driver/xscreensaver.man

post-patch-NSFW-off:
	${REINPLACE_CMD} -e 's|Dick Pix|Stuff|' ${WRKSRC}/hacks/bsod.c
	${REINPLACE_CMD} -e 's|dick pics|data, etc.|' ${WRKSRC}/hacks/bsod.c

pre-configure-NLS-on:
	cd ${WRKSRC} && ${LOCALBASE}/bin/intltoolize -f -c

post-install:
	${INSTALL_DATA} ${FILESDIR}/x*.xml ${STAGEDIR}${DATADIR}/config/
	${INSTALL_DATA} ${WRKDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/xscreensaver
	${LN} -s ${LOCALBASE}/etc/pam.d/unix-selfauth \
		${STAGEDIR}${PREFIX}/etc/pam.d/xscreensaver

.include <bsd.port.mk>
