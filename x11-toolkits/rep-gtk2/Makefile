PORTNAME=	rep-gtk2
PORTVERSION=	0.90.8.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/
DISTNAME=	rep-gtk_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GTK-2 bindings for rep Lisp interpreter
WWW=		https://sawfish.tuxfamily.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated gtk2 library
EXPIRATION_DATE=	2024-12-31

LIB_DEPENDS=	librep.so:lang/librep \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk20

PLIST_FILES=	include/rep-gtk/rep-gtk.h lib/rep/gui/gtk-2/gtk.a \
		lib/rep/gui/gtk-2/gtk.so libdata/pkgconfig/rep-gtk.pc

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/rep/gui/gtk-2/gtk.so

.include <bsd.port.mk>
