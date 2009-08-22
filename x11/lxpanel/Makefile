# New ports collection makefile for:	lxpanel
# Date created:		Sat Oct 7 01:22:35 CST 2006
# Whom:			Lin, Cheng-Tao <b89605222@ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	lxpanel
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXPanel%20%28desktop%20panel%29/LXPanel%20${PORTVERSION}

MAINTAINER=	b89605222@ntu.edu.tw
COMMENT=	LXPanel is a lightweight X11 desktop panel

OPTIONS=	ALSA "enable ALSA audio architecture support" Off \
		NLS "NLS support" On

USE_XORG=	x11 xmu
USE_GNOME=	gtk20 gnomedesktop gnomeprefix libgnome
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:110:env
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC}
USE_GMAKE=	yes

MAN1=		lxpanel.1 lxpanelctl.1
WITH_ALSA=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_ALSA)
RUN_DEPENDS+=	${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
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

.include <bsd.port.post.mk>
