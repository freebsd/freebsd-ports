# New ports collection makefile for:   vdk
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdk
PORTVERSION=	1.2.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdkbuilder

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		vdk-config.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk
CONFIGURE_ARGS+=	--enable-gnome
.endif

.include <bsd.port.post.mk>
