PORTNAME=	libexo
PORTVERSION=	4.18.0
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	exo-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment
WWW=		https://www.xfce.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
BUILD_DEPENDS=	p5-URI>=1.70:net/p5-URI
RUN_DEPENDS=	p5-URI>=1.70:net/p5-URI

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		perl5 pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--without-html-dir --disable-silent-rules

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	 NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
