# New ports collection makefile for:	Nucleo
# Date created:				30 May 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nucleo
PORTVERSION=	0.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/latest/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

OPTIONS=	JPEG	"Build with JPEG image support"		on \
		PNG	"Build with PNG image support"		on \
		EXIF	"Build with EXIF support"		on \
		QT4	"Enable Qt4 plugin"			off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

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

.include <bsd.port.post.mk>
