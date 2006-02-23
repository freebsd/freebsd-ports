# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.70 2005/11/28 07:30:27 ahze Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.12.2
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

USE_GECKO=	firefox mozilla seamonkey thunderbird

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mozilla=${GECKO}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	yelp.schemas

OPTIONS=	MAN "Enable man page support" off \
		INFO "Enable GNU info support" off

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

.if ${OSVERSION} < 500000
USE_GCC=	2.95
.endif

.if defined(WITH_MAN)
CONFIGURE_ARGS+=--enable-man
.endif

.if defined(WITH_INFO)
CONFIGURE_ARGS+=--enable-info
.endif

.include <bsd.port.post.mk>
