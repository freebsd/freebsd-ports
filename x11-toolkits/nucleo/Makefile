# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nucleo
PORTVERSION=	0.7.6
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LICENSE=	LGPL21

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		exif:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNUTLS DNSSD FFMPEG QT4 GD

DNSSD_DESC=	DNS-SD support
FFMPEG_DESC=	FFmpeg plugin
QT4_DESC=	Qt4 plugin
GD_DESC=	GD plugin

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not compile on powerpc-9
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MDNSSD}
.  if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h)
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/avahi-libdns
.  else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.  endif
.else
CONFIGURE_ARGS+=	--without-dns-sd
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=	--without-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	moc_build corelib
MAKE_ARGS+=	QT4MOC=${LOCALBASE}/bin/moc-qt4
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--without-qt
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
PLIST_SUB+=	GD=""
.else
CONFIGURE_ARGS+=	--without-gd
PLIST_SUB+=	GD="@comment "
.endif

.include <bsd.port.post.mk>
