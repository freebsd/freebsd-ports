# New ports collection makefile for:	efreet
# Date created:				28 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	efreet
PORTVERSION=	0.0.3.042
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Freedesktop.org EFL compatiblity layer

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_EFL=	ecore
USE_EFL_ECORE=	file
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's,-g -O0,,g' ${WRKSRC}/src/lib/Makefile.in

.include <bsd.port.mk>
