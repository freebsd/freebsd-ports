# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nucleo
PORTVERSION=	0.7.6
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LICENSE=	LGPL21

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		gmake libtool pathfix pkgconfig shebangfix tar:bzip2
USE_GL=		glu
SHEBANG_FILES=	docs/MacOSX/nBundle.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-opencv
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	FFMPEG GD GNUTLS QT4
OPTIONS_RADIO=	DNSSD
OPTIONS_RADIO_DNSSD=	AVAHI MDNSRESPONDER
OPTIONS_SUB=	yes

AVAHI_BUILD_DEPENDS=	avahi-libdns>0:${PORTSDIR}/net/avahi-libdns
AVAHI_LIB_DEPENDS=	libdns_sd.so:${PORTSDIR}/net/avahi-libdns
AVAHI_CPPFLAGS=		-I${LOCALBASE}/include/avahi-compat-libdns_sd
DNSSD_DESC=		DNS-SD support
FFMPEG_DESC=		FFmpeg plugin
FFMPEG_LIB_DEPENDS=	libavformat.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg
GD_DESC=		GD plugin
GD_LIB_DEPENDS=		libgd.so:${PORTSDIR}/graphics/gd
QT4_DESC=		Qt4 plugin
GD_CONFIGURE_WITH=	gd
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls
MDNSRESPONDER_BUILD_DEPENDS=\
			mDNSResponder>0:${PORTSDIR}/net/mDNSResponder
MDNSRESPONDER_LIB_DEPENDS=\
			libdns_sd.so:${PORTSDIR}/net/mDNSResponder
QT4_USE=		QT4=moc_build,corelib
QT4_CONFIGURE_WITH=	qt
QT4_MAKE_ARGS=		QT4MOC="${MOC}"

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MAVAHI} && ! ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=	--without-dns-sd
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=		yes
.endif

.if ${ARCH} == "powerpc" && ${OPSYS} == FreeBSD && ${OSVERSION} > 900000
BROKEN=		Does not compile on powerpc-9
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/nucleo

.include <bsd.port.mk>
