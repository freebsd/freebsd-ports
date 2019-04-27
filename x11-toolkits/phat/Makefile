# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	phat
PORTVERSION=	0.4.1
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	BERLIOS/phat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of GTK+ widgets geared toward pro-audio apps

BROKEN=		unfetchable
DEPRECATED=	Unmaintained, upstream disappeared, underlinks
EXPIRATION_DATE=	2019-05-28

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20 libgnomecanvas
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.mk>
