# New ports collection makefile for:   vdk
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdk
PORTVERSION=	1.2.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.sourceforge.net/vdkbuilder/

MAINTAINER=	nakai@FreeBSD.org

USE_NEWGCC=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		vdk-config.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=	--enable-gnome
.endif

.include <bsd.port.post.mk>
