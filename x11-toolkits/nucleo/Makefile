# New ports collection makefile for:	Nucleo
# Date created:				30 May 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nucleo
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		exif.12:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		glu
USE_QT_VER=	4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

OPTIONS=	GNUTLS	"Build with GnuTLS support"	off \
		DNSSD	"Build with DNS-SD support"	off \
		FFMPEG	"Enable FFmpeg plugin"		off \
		QT4	"Enable Qt4 plugin"		off \
		GD	"Enable GD plugin"		off

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITH_DNSSD)
.  if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h)
LIB_DEPENDS+=	dns_sd.1:${PORTSDIR}/net/avahi-libdns
.  else
LIB_DEPENDS+=	dns_sd.1:${PORTSDIR}/net/mDNSResponder
.  endif
.else
CONFIGURE_ARGS+=	--without-dns-sd
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=	--without-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if defined(WITH_QT4)
QT_COMPONENTS=	moc_build corelib
MAKE_ARGS+=	QT4MOC=${LOCALBASE}/bin/moc-qt4
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--without-qt
PLIST_SUB+=	QT4="@comment "
.endif

.if defined(WITH_GD)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	GD=""
.else
CONFIGURE_ARGS+=	--without-gd
PLIST_SUB+=	GD="@comment "
.endif

post-patch:
# Fix for libpng 1.4
	@${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/nucleo/image/encoding/PNGenc.cxx

.include <bsd.port.post.mk>
