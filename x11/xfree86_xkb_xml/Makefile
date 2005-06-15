# New ports collection makefile for:	xfree86_xkb_xml
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfree86_xkb_xml
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gswitchit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A little set of XML files useful for dealing with XKB rules

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--with-xkb-base=${X11BASE}/lib/X11/xkb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
