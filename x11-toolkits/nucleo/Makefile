# New ports collection makefile for:	Nucleo
# Date created:				30 May 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nucleo
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/latest/ \
		http://freebsd.nsu.ru/distfiles/metisse/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		glu
USE_XORG=	x11 xt
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

OPTIONS=	EXIF	"Build with EXIF support"	on \
		DNSSD	"Build with DNS-SD support"	off \
		QT4	"Enable Qt4 plugin"		off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXIF)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
.endif

.if defined(WITH_QT4)
LIB_DEPENDS+=	QtCore:${PORTSDIR}/devel/qt4-corelib
MAKE_ARGS+=	QT4MOC=${LOCALBASE}/bin/moc-qt4
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--disable-qt
PLIST_SUB+=	QT4="@comment "
.endif

.if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h)
LIB_DEPENDS+=	dns_sd.1:${PORTSDIR}/net/avahi-libdns
.elif defined(WITH_DNSSD)
LIB_DEPENDS+=	dns_sd.1:${PORTSDIR}/net/mDNSResponder
.endif

.include <bsd.port.post.mk>
