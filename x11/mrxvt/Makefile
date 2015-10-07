# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	mrxvt
PORTVERSION=	0.4.2
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	SF/materm/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tabbed version of rxvt

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

CONFLICTS=	mrxvt-0.5.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lastlog --disable-wtmp
USES=		jpeg tar:tgz
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS JAPANESE XFT

JAPANESE_CONFIGURE_ON=	--enable-xim --enable-cjk --with-encoding=eucj
XFT_LIB_DEPENDS=	libXft.so:${PORTSDIR}/x11-fonts/libXft
XFT_CONFIGURE_ENABLE=	xft

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	TIPS \
		README.greek \
		README.menu \
		README.xvt \
		xdefaults-sample.txt \
		xterm.seq \
		mrxvt.vbs \
		mrxvtset.pl

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^\(install-data-am:\).*/ \
		s/install-docDATA //' ${WRKSRC}/doc/Makefile.in

post-install:
	${CHMOD} 4511 ${STAGEDIR}${PREFIX}/bin/mrxvt

.include <bsd.port.mk>
