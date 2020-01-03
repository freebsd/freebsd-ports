# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nucleo
PORTVERSION=	0.7.6
PORTREVISION=	23
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

DEPRECATED=	Unmaintained, only used by deprecated x11/metisse
EXPIRATION_DATE=	2020-01-27

.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN=		ld: error: /wrkdirs/usr/ports/x11-toolkits/nucleo/work/nucleo-0.7.6/nucleo/.libs/libNucleo.so: undefined reference to XCloseDisplay
.endif

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES=		gl gmake jpeg libtool localbase:ldflags \
		pathfix pkgconfig python:run shebangfix tar:bzip2
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-opencv --without-qt
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	docs/MacOSX/nBundle.in

OPTIONS_DEFINE=	FFMPEG GD GNUTLS
OPTIONS_RADIO=	DNSSD
OPTIONS_RADIO_DNSSD=	AVAHI MDNSRESPONDER
OPTIONS_SUB=	yes
DNSSD_DESC=		Service discovery

AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_CPPFLAGS=		-I${LOCALBASE}/include/avahi-compat-libdns_sd

FFMPEG_DESC=		Build FFmpeg plugin
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_OFF=	--without-ffmpeg

GD_DESC=		Build GD plugin
GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_OFF=	--without-gd

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--without-gnutls

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MAVAHI} && ! ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=	--without-dns-sd
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/nucleo

.include <bsd.port.mk>
