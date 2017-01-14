# Created by: Eric Turgeon <ericturgeon.bsd@gmail.com>
# $FreeBSD$

PORTNAME=	lxrandr
PORTVERSION=	0.3.1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXRandR%20%28monitor%20config%20tool%29/LXRandR%20${PORTVERSION:R}.x/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Monitor configuration tool

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

USES=		desktop-file-utils gmake localbase pkgconfig tar:xz
USE_GNOME=	gtk20 intltool cairo
USE_XORG=	xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes


OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
