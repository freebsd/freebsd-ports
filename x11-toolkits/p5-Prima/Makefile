# Created by: dmitry@karasik.eu.org
# $FreeBSD$

PORTNAME=	Prima
PORTVERSION=	1.56
CATEGORIES=	x11-toolkits graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible Perl toolkit for multi-platform GUI development

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		jpeg perl5 pkgconfig xorg
USE_PERL5=	configure
USE_XORG=	x11 xcursor xext xpm xrender xrandr

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GTK2 GTK3 ICONV XFT
OPTIONS_DEFAULT=ICONV XFT
GTK2_CONFIGURE_OFF=	WITH_GTK2=0
GTK2_CONFIGURE_ON=	WITH_GTK2=1
GTK2_USE=		GNOME=gtk20
GTK2_USES=		gnome
GTK3_CONFIGURE_OFF=	WITH_GTK3=0
GTK3_CONFIGURE_ON=	WITH_GTK3=1
GTK3_USE=		GNOME=gtk30
GTK3_USES=		gnome
ICONV_CONFIGURE_OFF=	WITH_ICONV=0
ICONV_CONFIGURE_ON=	WITH_ICONV=1
ICONV_USES=		iconv
XFT_CONFIGURE_OFF=	WITH_XFT=0
XFT_CONFIGURE_ON=	WITH_XFT=1
XFT_USE=		XORG=xft

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Prima/Prima.so
	@${REINPLACE_CMD} -e 's|${STAGEDIR}||' ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/Prima/Config.pm

.include <bsd.port.mk>
