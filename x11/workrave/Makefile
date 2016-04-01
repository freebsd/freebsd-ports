# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	workrave
PORTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSI prevention tool

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>0:devel/py-cheetah
LIB_DEPENDS=	libgdome.so:textproc/gdome2

USES=		gettext gmake pathfix pkgconfig python
USE_XORG=	recordproto x11 xext xmu xscrnsaver xtst
USE_GNOME=	intlhack gconf2 gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-gconf --disable-gnome3 \
		--disable-indicator
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		GNOME GSTREAMER PULSEAUDIO
OPTIONS_DEFAULT=	GSTREAMER
OPTIONS_SUB=		yes

GNOME_USE=		gnome=gnomepanel
GNOME_LIB_DEPENDS=	libgnomeuimm-2.6.so:x11-toolkits/libgnomeuimm26
GNOME_CONFIGURE_ENABLE=	gnome2
GSTREAMER_USE=		gstreamer=good
GSTREAMER_CONFIGURE_ENABLE=	gstreamer
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's| gnome-shell$$||' ${WRKSRC}/frontend/applets/Makefile.in

.include <bsd.port.mk>
