# Created by: jmz

PORTNAME=	xsnow
PORTVERSION=	3.3.6
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Create a snowy and Santa-y desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2
USE_XORG=	x11 xpm xt xorgproto
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/xsnow man/man6/xsnow.6.gz \
		share/applications/xsnow.desktop \
		share/metainfo/xsnow.appdata.xml \
		share/pixmaps/xsnow.svg

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/games,/bin,g' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
