# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	libexo
PORTVERSION=	0.10.7
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME:C/lib//}/${PORTVERSION:R}
DISTNAME=	exo-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_DISTFILES=	${WRKSRC}/COPYING \
	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	p5-URI>=1.60:net/p5-URI
RUN_DEPENDS=	p5-URI>=1.60:net/p5-URI

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		desktop-file-utils gmake libtool pathfix perl5 \
		pkgconfig gettext-tools xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	x11

CONFIGURE_ARGS=--without-html-dir

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
	${REINPLACE_CMD} -e 's|internet-mail|mail-send|' \
		${WRKSRC}/exo-open/exo-mail-reader.desktop.in

.include <bsd.port.mk>
