PORTNAME=	xscreensaver
PORTVERSION=	6.02
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Save your screen while you entertain your cat

LICENSE=	MIT

RUN_DEPENDS=	giftopnm:graphics/netpbm \
		p5-libwww>0:www/p5-libwww
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgle.so:graphics/gle \
		libharfbuzz.so:print/harfbuzz

USES=		autoreconf cpe gettext gl gmake gnome jpeg localbase:ldflags perl5 \
		pkgconfig xorg
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool libglade2 libxml2
USE_PERL5=	run
USE_XORG=	ice sm x11 xext xft xi xinerama xmu xrandr xrender xt xxf86vm
CPE_VENDOR=	xscreensaver_project

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PERL="${PERL}"
CONFIGURE_ARGS=	--enable-locking \
		--with-app-defaults=${PREFIX}/lib/X11/app-defaults/ \
		--with-configdir=${PREFIX}/share/xscreensaver/config/ \
		--with-dpms-ext \
		--with-gl \
		--with-gle \
		--with-gtk \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks/ \
		--with-jpeg=${LOCALBASE} \
		--with-pixbuf \
		--with-randr-ext \
		--with-xdbe-ext \
		--with-xf86gamma-ext \
		--with-xf86vmode-ext \
		--with-xft \
		--with-xinerama-ext \
		--with-xshm-ext \
		--without-kerberos
MAKE_ARGS+=	install_prefix=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FIREF NLS NSFW PAM SETUID_HACKS XAOS1 XDALI XEARTH \
			XMOUN XPLANET XSNOW
OPTIONS_DEFAULT=	PAM
OPTIONS_SUB=		yes

PAM_CONFIGURE_WITH=	passwd-helper=${PREFIX}/bin/pam_helper
PAM_RUN_DEPENDS=	pam_helper:security/pam_helper

SETUID_HACKS_DESC=	Install sonar hack suid so it can ping
SETUID_HACKS_CONFIGURE_WITH=	setuid-hacks

FIREF_DESC=		Add extra port x11/fireflies
FIREF_RUN_DEPENDS=	${LOCALBASE}/bin/xscreensaver-hacks/fireflies:x11/fireflies

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

NSFW_DESC=		Include material that is Not Safe For Work

XAOS1_DESC=		Add extra port graphics/xaos
XAOS1_RUN_DEPENDS=	xaos:graphics/xaos

XDALI_DESC=		Add extra port x11-clocks/xdaliclock
XDALI_RUN_DEPENDS=	xdaliclock:x11-clocks/xdaliclock

XEARTH_DESC=		Add extra port astro/xearth
XEARTH_RUN_DEPENDS=	xearth:astro/xearth

XMOUN_DESC=		Add extra port graphics/xmountains
XMOUN_RUN_DEPENDS=	xmountains:graphics/xmountains

XPLANET_DESC=		Add extra port astro/xplanet
XPLANET_RUN_DEPENDS=	xplanet:astro/xplanet

XSNOW_DESC=		Add extra port x11/xsnow
XSNOW_RUN_DEPENDS=	xsnow:x11/xsnow

SUB_FILES=	xscreensaver-blank.desktop xscreensaver-lock.desktop \
		xscreensaver-start.desktop xscreensaver-stop.desktop

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
			-e 's|pkg_config --list-all|pkg_config --help|' \
			${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e "s|/etc/pam.d|${PREFIX}/etc/pam.d|g" \
		${WRKSRC}/driver/passwd-pam.c \
		${WRKSRC}/driver/xscreensaver.man

post-patch-NSFW-off:
	${REINPLACE_CMD} -e 's|Dick Pix|Stuff|' ${WRKSRC}/hacks/bsod.c
	${REINPLACE_CMD} -e 's|dick pics|data, etc.|' ${WRKSRC}/hacks/bsod.c

post-install:
	${INSTALL_DATA} ${FILESDIR}/x*.xml ${STAGEDIR}${DATADIR}/config/
	${INSTALL_DATA} ${WRKDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/xscreensaver.pam

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/xscreensaver.pam ${STAGEDIR}${PREFIX}/etc/pam.d/xscreensaver

.include <bsd.port.mk>
