# New ports collection makefile for:	mrxvt
# Date created:				27 Nov 2004
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mrxvt
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	materm
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@gmail.com
COMMENT=	A tabbed version of rxvt

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

CONFLICTS=	mrxvt-0.5.*

GNU_CONFIGURE=	yes
USE_XORG=	x11

.if defined(WITH_JAPANESE)
CONFIGURE_ARGS+=	--enable-xim --enable-cjk --with-encoding=eucj
.endif # WITH_JAPANESE

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

MAN1=		mrxvt.1

pre-everything::
	@${ECHO_MSG} "=========================================>"
	@${ECHO_MSG} "For Japanese support use make -DWITH_JAPANESE install"
	@${ECHO_MSG} "For XFT support use make -DWITH_XFT install"
	@${ECHO_MSG} "=========================================>"

.include <bsd.port.mk>
