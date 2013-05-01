# Created by: Lin, Cheng-Tao <b89605222@ntu.edu.tw>
# $FreeBSD$

PORTNAME=	lxpanel
PORTVERSION=	0.5.12
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXPanel%20%28desktop%20panel%29/LXPanel%20${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lightweight X11 desktop panel

LIB_DEPENDS=	menu-cache.1:${PORTSDIR}/x11/menu-cache
RUN_DEPENDS=	${LOCALBASE}/share/desktop-directories/lxde-audio-video.directory:${PORTSDIR}/x11/lxmenu-data

OPTIONS_DEFINE=	ALSA NLS
OPTIONS_DEFAULT=NLS

USE_XORG=	x11 xmu
USE_GNOME=	gtk20 libwnck
USES=		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-plugins=volume,deskno,kbled,xkb,batt\
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC}
USE_GMAKE=	yes

MAN1=		lxpanel.1 lxpanelctl.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
RUN_DEPENDS+=	${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-f10-alsa-lib
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,linux,sys,' \
		${WRKSRC}/src/plugins/volume/volume-impl.c
	@${REINPLACE_CMD} -e 's,$$(DATADIRNAME)/locale,share/locale,' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
