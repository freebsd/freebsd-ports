PORTNAME=	gtk2
PORTVERSION=	3.4.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GTK+ 2.x
WWW=		https://ruby-gnome2.osdn.jp/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	rubygem-atk>=${PORTVERSION}:accessibility/rubygem-atk \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-pango>=${PORTVERSION}:x11-toolkits/rubygem-pango

USES=		gem gnome xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20 introspection
USE_XORG=	x11

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=int-conversion"
.endif

.include <bsd.port.mk>
