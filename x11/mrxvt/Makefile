PORTNAME=	mrxvt
PORTVERSION=	0.4.2
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	SF/materm/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tabbed version of rxvt
WWW=		https://materm.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cpe jpeg localbase tar:tgz xorg
CPE_VENDOR=	${PORTNAME}_project
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-lastlog --disable-wtmp

CONFLICTS=	mrxvt-0.5.*

PORTDOCS=	TIPS \
		README.greek \
		README.menu \
		README.xvt \
		xdefaults-sample.txt \
		xterm.seq \
		mrxvt.vbs \
		mrxvtset.pl

OPTIONS_DEFINE=	DOCS JAPANESE XFT

JAPANESE_DESC=	Japanese Language support

JAPANESE_CONFIGURE_ON=	--enable-xim --enable-cjk --with-encoding=eucj
XFT_LIB_DEPENDS=	libXft.so:x11-fonts/libXft
XFT_CONFIGURE_ENABLE=	xft

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

.include <bsd.port.post.mk>
