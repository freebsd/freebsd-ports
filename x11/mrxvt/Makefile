# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	mrxvt
PORTVERSION=	0.4.2
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	SF/materm/${PORTNAME}%20source/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tabbed version of rxvt

LIB_DEPENDS=	libjpeg.so.11:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

CONFLICTS=	mrxvt-0.5.*

GNU_CONFIGURE=	yes
USE_XORG=	x11

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-lastlog --disable-wtmp
.endif

.if defined(WITH_JAPANESE)
CONFIGURE_ARGS+=	--enable-xim --enable-cjk --with-encoding=eucj
.endif # WITH_JAPANESE

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.if !defined(NOPORTDOCS)
PORTDOCS=	TIPS \
			README.greek \
			README.menu \
			README.xvt \
			xdefaults-sample.txt \
			xterm.seq \
			mrxvt.vbs \
			mrxvtset.pl
.endif

pre-everything::
	@${ECHO_MSG} "=========================================>"
	@${ECHO_MSG} "For Japanese support use make -DWITH_JAPANESE install"
	@${ECHO_MSG} "For XFT support use make -DWITH_XFT install"
	@${ECHO_MSG} "=========================================>"

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^\(install-data-am:\).*/ \
		s/install-docDATA //' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${CHMOD} 4511 ${STAGEDIR}${PREFIX}/bin/mrxvt

.include <bsd.port.post.mk>
