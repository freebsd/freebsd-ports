# New ports collection makefile for:   wmg
# Date created:        27 August 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	wmg
PORTVERSION=	0.15.0
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://ductape.net/~reeve/downloads/ \
		http://www.geocities.com/SiliconValley/Screen/4079/downloads/
DISTNAME=	wmG-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
