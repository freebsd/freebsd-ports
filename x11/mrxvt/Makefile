# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	mrxvt
PORTVERSION=	0.4.2
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF/materm/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tabbed version of rxvt

LIB_DEPENDS=	libpng.so:graphics/png

CONFLICTS=	mrxvt-0.5.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lastlog --disable-wtmp
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		jpeg tar:tgz
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS JAPANESE XFT

JAPANESE_CONFIGURE_ON=	--enable-xim --enable-cjk --with-encoding=eucj
XFT_LIB_DEPENDS=	libXft.so:x11-fonts/libXft
XFT_CONFIGURE_ENABLE=	xft

PORTDOCS=	TIPS \
		README.greek \
		README.menu \
		README.xvt \
		xdefaults-sample.txt \
		xterm.seq \
		mrxvt.vbs \
		mrxvtset.pl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT} && ${PORT_OPTIONS:MJAPANESE}
USES+=		iconv
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=no
.else
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=yes
.endif

post-install:
	${CHMOD} 4511 ${STAGEDIR}${PREFIX}/bin/mrxvt

.include <bsd.port.post.mk>
