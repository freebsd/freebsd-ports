# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A collection of Enlightenment dock applications

BUILD_DEPENDS=	e16:${PORTSDIR}/x11-wm/e16
LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	e16:${PORTSDIR}/x11-wm/e16 \
		import:${PORTSDIR}/graphics/ImageMagick

USE_XORG=	xext
USE_GNOME=	esound gnometarget
USE_GL=		glut
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:262
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-auto-respawn

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|<machine/soundcard\.h>|<sys/soundcard.h>|g' \
		${WRKSRC}/epplets/Emix.c
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/epplets/mbox.c

.include <bsd.port.post.mk>
