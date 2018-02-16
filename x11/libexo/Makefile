# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	libexo
PORTVERSION=	0.12.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME:C/lib//}/${PORTVERSION:R}
DISTNAME=	exo-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	p5-URI>=1.60:net/p5-URI
RUN_DEPENDS=	p5-URI>=1.60:net/p5-URI

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		desktop-file-utils gmake libtool pathfix perl5 \
		pkgconfig gettext-tools xfce:gtk3 tar:bzip2
USE_GNOME=	cairo glib20 gtk20 gtk30 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

CONFIGURE_ARGS=--without-html-dir --disable-silent-rules

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
	${REINPLACE_CMD} -e 's|internet-mail|mail-send|' \
		${WRKSRC}/exo-open/exo-mail-reader.desktop.in

.include <bsd.port.mk>
