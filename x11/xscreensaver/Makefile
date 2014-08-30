# Created by: dom@myrddin.demon.co.uk
# $FreeBSD$

PORTNAME=	xscreensaver
PORTVERSION=	5.29
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Save your screen while you entertain your cat

RUN_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		giftopnm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libgle.so:${PORTSDIR}/graphics/gle \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

DESTDIRNAME=	install_prefix

CONFLICTS=	xscreensaver-gnome-[0-9]* xscreensaver-gnome-hacks-[0-9]*

USES=		pkgconfig gettext gmake perl5
USE_AUTOTOOLS=	autoconf
USE_GL=		yes
USE_GNOME=	gdkpixbuf2 gtk20 intltool libglade2 libxml2
USE_PERL5=	run
USE_XORG=	xpm xext xxf86misc

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PERL="${PERL}"
CONFIGURE_ARGS=	--with-gtk --with-gl --with-gle --with-pixbuf --with-xpm \
		--with-jpeg=${LOCALBASE} --with-xshm-ext --with-xdbe-ext \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks/ \
		--with-configdir=${PREFIX}/share/xscreensaver/config/ \
		--with-dpms-ext --with-xinerama-ext --with-xf86vmode-ext \
		--with-xf86gamma-ext --with-randr-ext --without-kerberos \
		--without-setuid-hacks --enable-locking
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PAM SETUID_HACKS FIREF XAOS1 XDALI XEARTH \
		XMOUN XPLANET XSNOW
OPTIONS_SUB=	yes

PAM_CONFIGURE_WITH=		pam

SETUID_HACKS_DESC=		Install sonar hack suid so it can ping

FIREF_DESC=			Add extra port x11/fireflies
FIREF_RUN_DEPENDS=		${LOCALBASE}/bin/xscreensaver-hacks/fireflies:${PORTSDIR}/x11/fireflies

XAOS1_DESC=			Add extra port graphics/xaos
XAOS1_RUN_DEPENDS=		xaos:${PORTSDIR}/graphics/xaos

XDALI_DESC=			Add extra port x11-clocks/xdaliclock
XDALI_RUN_DEPENDS=		xdaliclock:${PORTSDIR}/x11-clocks/xdaliclock

XEARTH_DESC=			Add extra port astro/xearth
XEARTH_RUN_DEPENDS=		xearth:${PORTSDIR}/astro/xearth

XMOUN_DESC=			Add extra port graphics/xmountains
XMOUN_RUN_DEPENDS=		xmountains:${PORTSDIR}/graphics/xmountains

XPLANET_DESC=			Add extra port astro/xplanet
XPLANET_RUN_DEPENDS=		xplanet:${PORTSDIR}/astro/xplanet

XSNOW_DESC=			Add extra port x11/xsnow
XSNOW_RUN_DEPENDS=		xsnow:${PORTSDIR}/x11/xsnow

SUB_FILES=	xscreensaver-blank.desktop xscreensaver-lock.desktop \
		xscreensaver-start.desktop xscreensaver-stop.desktop

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
			-e 's|pkg_config --list-all|pkg_config --help|' \
			${WRKSRC}/configure.in
	${REINPLACE_CMD} -e "s|/etc/pam.d|${PREFIX}/etc/pam.d|g" \
		${WRKSRC}/driver/passwd-pam.c \
		${WRKSRC}/driver/xscreensaver.man
	${CP} ${FILESDIR}/xscreensaver.pam \
		${WRKSRC}/driver/xscreensaver.pam.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/x*.xml ${STAGEDIR}${DATADIR}/config/
	${INSTALL_DATA} ${WRKDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
