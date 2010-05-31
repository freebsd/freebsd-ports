# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.154 2010/04/27 13:32:17 kwm Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
    		rarian.0:${PORTSDIR}/textproc/rarian

USE_GECKO=	libxul
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XORG=	ice
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gecko=${GECKO} \
		--with-gecko-home=${LOCALBASE}/lib/${GECKO}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	yelp.schemas

.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

post-extract:
	${RM} -f ${WRKSRC}/data/yelp.schemas

.include <bsd.port.post.mk>
