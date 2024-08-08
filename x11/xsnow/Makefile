PORTNAME=	xsnow
PORTVERSION=	3.7.9
CATEGORIES=	x11
MASTER_SITES=	https://ratrabbit.nl/downloads/xsnow/ \
		SF/${PORTNAME}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Create a snowy and Santa-y desktop
WWW=		https://www.ratrabbit.nl/ratrabbit/xsnow/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2
USE_XORG=	x11 xext xinerama xpm xt xtst xorgproto
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/games,/bin,g' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
