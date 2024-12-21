PORTNAME=	libexo
PORTVERSION=	4.20.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	exo-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment
WWW=		https://gitlab.xfce.org/xfce/exo

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix perl5 \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
