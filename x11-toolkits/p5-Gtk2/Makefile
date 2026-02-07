PORTNAME=	Gtk2
PORTVERSION=	1.24993
PORTREVISION=	5
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN \
		SF/${PORTNAME:tl}-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library
WWW=		https://gtk2-perl.sourceforge.net/

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Cairo>=1:graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0.300:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:devel/p5-ExtUtils-PkgConfig \
		p5-Glib>=1.280:devel/p5-Glib \
		p5-Pango>=1.220:x11-toolkits/p5-Pango
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	p5-Cairo>=1:graphics/p5-Cairo \
		p5-Glib>=1.280:devel/p5-Glib \
		p5-Pango>=1.220:x11-toolkits/p5-Pango

USES=		gmake gnome perl5
USE_GNOME=	cairo gdkpixbuf gtk20 pango
USE_PERL5=	configure

CONFIGURE_ENV=	FORCE_MAKE_CMD=yes

post-patch:
	${REINPLACE_CMD} -e 's|"gtk+-2.0.*|"gtk+-2.0");|g' \
		${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gtk2/Gtk2.so

.include <bsd.port.mk>
