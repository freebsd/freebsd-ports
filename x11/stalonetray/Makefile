# New ports collection makefile for:	stalonetray
# Date created:		Apr 6 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stalonetray
PORTVERSION=	0.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	redchrom@gmail.com
COMMENT=	STAnd-aLONE system tray

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-native-kde --disable-debug
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAN1=		stalonetray.1
PLIST_FILES=	bin/stalonetray

.include <bsd.port.mk>
