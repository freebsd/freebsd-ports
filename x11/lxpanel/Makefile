# Created by: Lin, Cheng-Tao <b89605222@ntu.edu.tw>
# $FreeBSD$

PORTNAME=	lxpanel
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXPanel%20%28desktop%20panel%29/LXPanel%20${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lightweight X11 desktop panel

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libmenu-cache.so:${PORTSDIR}/x11/menu-cache
RUN_DEPENDS=	${LOCALBASE}/share/desktop-directories/lxde-audio-video.directory:${PORTSDIR}/x11/lxmenu-data

OPTIONS_DEFINE=	ALSA DOCS NLS
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

ALSA_RUN_DEPENDS=	${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-f10-alsa-li
ALSA_CONFIGURE_ENABLE=	alsa

NLS_USES=	gettext

USE_XORG=	x11 xmu
USE_GNOME=	gtk20 libwnck
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-plugins=volume,deskno,kbled,xkb,batt \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC} -Wno-return-type
USE_CSTD=	gnu89

PORTDOCS=	AUTHORS README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,linux,sys,' \
		${WRKSRC}/src/plugins/volume/volume-impl.c
	@${REINPLACE_CMD} -e 's,$$(DATADIRNAME)/locale,share/locale,' \
		${WRKSRC}/po/Makefile.in.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's,po man,man,' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
