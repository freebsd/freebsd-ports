# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A collection of Enlightenment dock applications

BUILD_DEPENDS=	e16:${PORTSDIR}/x11-wm/enlightenment
LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	e16:${PORTSDIR}/x11-wm/enlightenment \
		import:${PORTSDIR}/graphics/ImageMagick

USE_XORG=	xext
USE_GNOME=	esound gnometarget
USE_GL=		glut
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:261
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-auto-respawn

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=	Does not compile on 5.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<machine/soundcard\.h>|<sys/soundcard.h>|g' \
		${WRKSRC}/epplets/Emix.c
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/epplets/mbox.c

.include <bsd.port.post.mk>
